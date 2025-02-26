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

void PrintArray(int array[], int length,string text)
{
    cout <<text<<endl;
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void Sum2Array(int Array1[],int Array2[],int SumArray[],int length)
{
    for (int i = 0; i < length; i++)
    {
        SumArray[i]=Array1[i]+Array2[i];
    }
    
}

int main()
{
    int array1[100],array2[100],sum2Array[100];
    int length=ReadPostiveNumber("enter number from 1 to 100");

    FillArrayWithRandomNumber(array1,length);
    FillArrayWithRandomNumber(array2,length);
    Sum2Array(array1,array2,sum2Array,length);

    PrintArray(array1,length,"Array 1 elements: ");
    PrintArray(array2,length,"Array 2 elements: ");
    PrintArray(sum2Array,length,"Sum of array1 and array2 elements: ");
    



}