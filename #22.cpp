#include <iostream>

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

void inPutArrayElements(int array[], int legth)
{
    if (legth > 0)
        cout << "Enter array elements\n";

    for (int i = 0; i < legth; i++)
    {
        cout << "Element [" << i + 1 << "]: ";
        cin >> array[i];
    }
}

int calculateFrequenceInArray(int array[], int length, int serch)
{
    int counter = 0;
    for (int i = 0; i <= length; i++)
    {
        if (serch == array[i])
            counter++;
    }
    return counter;
}

void OutPutArrayElements(int array[], int legth)
{
    if (legth > 0)
        cout << "original array: ";

    for (int i = 0; i < legth; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    int array[100];
    int length = ReadPostiveNumber("enter number?");

    inPutArrayElements(array, length);

    int checkNumber = ReadPostiveNumber("Enter the number you want to check: ");

    OutPutArrayElements(array, length);

    cout << checkNumber << " is repated : " << calculateFrequenceInArray(array, length, checkNumber) << " Time(s)";