#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

enum enCharType
{
    smallLetter = 1,
    CapitalLetter = 2,
    specialCharacter = 3,
    Digit = 4
};

int randomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

int ReadPostevNumber(string masseg)
{

    int num;
    do
    {
        cout << masseg << endl;
        cin >> num;
    } while (num < 0);

    return num;
}

char GetRandomCharacter(enCharType charType)
{
    switch (charType)
    {
    case enCharType::smallLetter:
        return char(rand() % (122 - 97 + 1) + 97);
        break;
    case enCharType::CapitalLetter:
        return char(rand() % (90 - 65 + 1) + 65);
        break;
    case enCharType::specialCharacter:
        return char(rand() % (47 - 32 + 1) + 32);
        break;
    case enCharType::Digit:
        return char(rand() % (57 - 48 + 1) + 48);
        break;
    }
}

string generateWord(enCharType charType, int create)
{
    string word = "";

    for (int i = 1; i <= create; i++)
    {
        word = word + GetRandomCharacter(charType);
    }

    return word;
}

string generateKey(enCharType CharType, int create)
{
    string key;
    key = generateWord(CharType, create) + "-";
    key = key + generateWord(CharType, create) + "-";
    key = key + generateWord(CharType, create) + "-";
    key = key + generateWord(CharType, create);

    return key;
}

void generateKeysInArray(enCharType charType, string Array[], int create, int keys)
{
    for (int i = 0; i < keys; i++)
    {
        Array[i] = generateKey(charType, create);
    }
}

void PrintStringArray(string Array[], int length)
{
    cout << "Array elements: \n\n";
    for (int i = 0; i < length; i++)
    {
        cout << "Array[" << i + 1 << "]: " << Array[i] << endl;
    }
}

int main()
{
    string Array[100];
    int length = ReadPostevNumber("who many keys do you want to create from 1 To 100: ");

    generateKeysInArray(enCharType::CapitalLetter, Array, 4, length);
    PrintStringArray(Array, length);
}