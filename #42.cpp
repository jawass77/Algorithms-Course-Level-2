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

bool checkOddNumber(int num)
{
    if (num % 2 == 0)
        return false;
    else
        return true;
}

int CounterOddNumber(int array[], int lenth)
{
    int oddNumber = 0;
    for (int i = 0; i < lenth; i++)
    {
        if (checkOddNumber(array[i]) == true)
            oddNumber++;
    }
    return oddNumber;
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

    int oddNumber = CounterOddNumber(array, lenth);

    cout << "odd number count is : " <<oddNumber<< endl;
}