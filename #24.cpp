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
    cout << "Array Elements : " ;
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int MaxNumber(int array[],int length)
{
    int maxNumber=0;

    for (int i = 0; i < length; i++)
    {
        if (maxNumber<array[i])
        maxNumber=array[i];
    }
    return maxNumber;
    
}

int main()
{
    srand(time(0));
    int array[100];
    int length=ReadPostiveNumber("enter number from 1 to 100");

    FillArrayWithRandomNumber(array,length);

    PrintArray(array,length);

    cout<<"Max number : "<<MaxNumber(array,length);
}