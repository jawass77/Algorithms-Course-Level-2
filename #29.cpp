#include <iostream>
#include <cstdlib>
#include <cmath>
#include <time.h>

using namespace std;

enum PrimeNotPrime
{
    prime = 1,
    notPrime = 2
};

int
ReadPostevNumber(string masseg)
{

    int num;
    do
    {
        cout << masseg << endl;
        cin >> num;
    } while (num < 0);

    return num;
}

PrimeNotPrime checkPrimeNotPrime(int num)
{
    int m = round(num / 2);

    for (int a = 2; a <= m; a++)
    {
        if (num % a == 0)
        {
            return PrimeNotPrime::notPrime;
        }
    }
    return PrimeNotPrime::prime;
}

int randomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void readArryWithRandomNumbers(int arry[], int lenth)
{
    for (int i = 0; i < lenth; i++)
    {
        arry[i] = randomNumber(10, 100);
    }
}

void CopyArryOnlyPrimeNumber(int array[], int copyArray[], int lenth,int &copyLength)
{
    for (int i = 0; i < lenth; i++)
    {
        if (checkPrimeNotPrime(array[i])==PrimeNotPrime::prime)
        {
        copyArray[copyLength] = array[i];
        copyLength++;
        }
    }
}

void printArry(int arry[], int copyArry[], int lenth,int copyLength)
{
    cout << "array 1 enemints: \n";
    for (int i = 0; i < lenth; i++)
    {
        cout << arry[i] << " ";
    }
    cout << endl
         << endl;

    cout << "array 2 enemints after copy : \n";

    for (int a = 0; a < copyLength; a++)
    {
        cout << copyArry[a] << " ";
    }
    cout << endl
         << endl;
}

int main()
{
    srand(time(0));
    int arry[100], copyArry[100];
    int lenth = ReadPostevNumber("enter number from 1 to 100");

    readArryWithRandomNumbers(arry, lenth);

    int copyLength=0;
    CopyArryOnlyPrimeNumber(arry, copyArry, lenth,copyLength);

    printArry(arry, copyArry, lenth,copyLength);
}