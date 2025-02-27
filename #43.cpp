#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void printArray(int arry[], int lenth)
{
    for (int i = 0; i < lenth; i++)
    {
        cout << arry[i] << " ";
    }
    cout << endl
         << endl;

}

bool checkEvenNumber(int num)
{
    if (num % 2 == 0)
        return true;
    else
        return false;
}

int CounterEvenNumber(int array[], int lenth)
{
    int EvenNumber = 0;
    for (int i = 0; i < lenth; i++)
    {
        if (checkEvenNumber(array[i]) == true)
            EvenNumber++;
    }
    return EvenNumber;
}

int readNumber()
{
    int number;

    cout << "please enter number " << endl;
    cin >> number;

    return number;
}

int randomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void readArryWithRandomNumbers(int array[], short lenth)
{
    for (int i = 0; i < lenth; i++)
    {
        array[i] = randomNumber(1, 100);
    }
}

int main()
{
    srand(time(0));

    int array[100];
    int lenth = readNumber();

    readArryWithRandomNumbers(array, lenth);

    cout << "orignal Arry" << endl;
    printArray(array, lenth);

    int oddNumber = CounterEvenNumber(array, lenth);

    cout << "Even number count is : " <<oddNumber<< endl;
}