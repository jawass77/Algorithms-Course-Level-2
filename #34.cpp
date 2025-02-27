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

void printArry(int arry[], int lenth)
{
    cout << "array 1 enemints: \n";
    for (int i = 0; i < lenth; i++)
    {
        cout << arry[i] << " ";
    }
    cout << endl
         << endl;

}

short SearchInArray(int Array[], int length, int search)
{
    for (int i = 0; i < length; i++)
    {
        if (Array[i] == search)
        {
            return i;
        }
    }
    return -1;

}

int main()
{
    int Array[100];
    int length=ReadPostiveNumber("enter number from 1 to 100");

    readArryWithRandomNumbers(Array,length);

    printArry(Array,length);

    int search=ReadPostiveNumber("please enter a number to search for ? ");

    
    cout<<"Number you are looking for is : "<<search<<endl;

    int result =SearchInArray(Array,length,search);

    if (!(result==-1))
    {
        cout<<"The number found at position : "<<result<<endl;
        cout<<"The number found its order : "<<result+1<<endl;
    }else
    {
        cout <<"The number is not found :-("<<endl;
    }


}

