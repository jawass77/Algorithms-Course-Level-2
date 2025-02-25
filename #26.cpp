#include <iostream>
#include <time.h>

using namespace std;

int ReadPostiveNumber(string text)
{

    int num;
    do
    {
        cout << text << endl;
        cin >> num;
    } while (num < 0);

    return num;
}

void FillArrayWithRandomNumber(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        array[i] = rand() % (100 - 10 + 1) + 10;
    }
}

void PrintArray(int array[], int length)
{
    cout << "Array Elements : ";
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int SumOfAllNumber(int array[], int length)
{
    int sum = 0;

    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum;
}

int main()
{
    srand(time(0));
    int array[100];
    int length = ReadPostiveNumber("enter number from 1 to 100");

    FillArrayWithRandomNumber(array, length);

    PrintArray(array, length);

    cout << "sum of all number is : " << SumOfAllNumber(array, length);
}