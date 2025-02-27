#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

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

int randomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

bool checkPrimeNumber(int num)
{
    int m = round(num / 2);

    for (int a = 2; a <= m; a++)
    {
        if (num % a == 0)
        {
            return false;
        }
    }
    return true;
}
void addArryElement(int number, int array[], int &length)
{
    length++;

    array[length - 1] = number;
}

void readArryWithRandomNumbers(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        array[i] = randomNumber(10, 100);
    }
}

void CopyArrayOddNumber(int array[], int copyArray[], int length, int &copyLength)
{
    for (int i = 0; i < length; i++)
    {
        if (checkPrimeNumber(array[i]))
            addArryElement(array[i], copyArray, copyLength);
    }
}

void printArray(int arry[], int lenth)
{
    for (int i = 0; i < lenth; i++)
    {
        cout << arry[i] << " ";
    }
    cout << endl
         << endl;
}

int main()
{
    srand(time(0));
    int array[100], copyArray[100];
    int copyLength=0;
    int lenth = ReadPostevNumber("enter number from 1 to 100");

    readArryWithRandomNumbers(array, lenth);
    CopyArrayOddNumber(array,copyArray,lenth,copyLength);


    cout << "array 1 enemints: \n";
    printArray(array,lenth);

    cout << "array 2 prime number: \n";
    printArray(copyArray,copyLength);
}