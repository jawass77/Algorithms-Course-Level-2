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

void GetRandomCharacter(enCharType charType)
{
    switch (charType)
    {
    case enCharType::CapitalLetter:
        cout << char(randomNumber(65, 90)) << endl;
        break;
    case enCharType::smallLetter:
        cout << char(randomNumber(87, 122)) << endl;
        break;
    case enCharType::specialCharacter:
        cout << char(randomNumber(33, 47)) << endl;
        break;
    case enCharType::Digit:
        cout << randomNumber(1, 10) << endl;
        break;
    }
}

int main()
{
    srand(time(0));

    GetRandomCharacter(enCharType::CapitalLetter);
    GetRandomCharacter(enCharType::smallLetter);
    GetRandomCharacter(enCharType::specialCharacter);
    GetRandomCharacter(enCharType::Digit);

}