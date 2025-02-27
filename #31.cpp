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

void Swap(int &first ,int &second)
{
    int swap=first;
    first=second;
    second=swap;

}

void FillArrayWith1ToN(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        array[i] = i+1;
    }
}

int randomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
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

void ShuffleArray(int Array[],int length)
{
    for (int i = 0; i < length; i++)
    {
        Swap(Array[randomNumber(0,length-1)],Array[randomNumber(0,length-1)]);
    }
    
}

int main()
{
    srand(time(0));
    int array[100];
    int length=ReadPostiveNumber("enter number from 1 to 100");

    FillArrayWith1ToN(array,length);
    PrintArray(array,length,"Array elements before shuffle: ");
    ShuffleArray(array,length);

    PrintArray(array,length,"Array elements after shuffle: ");
    



}