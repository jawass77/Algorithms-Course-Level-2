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

bool checkPostiveNumber(int num)
{
    if (num>0)
        return true;
    else
        return false;
}

int CounterPostiveNumber(int array[], int lenth)
{
    int PostiveNumber = 0;
    for (int i = 0; i < lenth; i++)
    {
        if (checkPostiveNumber(array[i]) == true)
            PostiveNumber++;
    }
    return PostiveNumber;
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
        array[i] = randomNumber(-100, 100);
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

    int PostiveNumber = CounterPostiveNumber(array, lenth);

    cout << "Postive number count is : " <<PostiveNumber<< endl;
}