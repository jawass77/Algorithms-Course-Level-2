#include<iostream>

using namespace std;

int readNumber()
{
    int number;

    cout<<"please enter number :"<<endl;
    cin>>number;

    return number;
}

void addArryElement(int number,int arry[],int &lenth)
{
    lenth++;

    arry[lenth-1]=number;

}

void InputUserNumbersInArray(int array[],int &lenth)
{
    bool checkAnterArry;
    
    do
    {
        addArryElement(readNumber(),array,lenth);

        cout<<"do you want to add more numbers?[0]NO,[1]YES \n";
        cin>>checkAnterArry;
        
    } while (checkAnterArry==true);
    
}

void printArry(int arry[], int lenth)
{
    for (int i = 0; i < lenth; i++)
    {
        cout << arry[i] << " ";
    }
    cout << endl
         << endl;

}

bool CheckNumberInArray(int Array[], int length, int search)
{
    for (int i = 0; i < length; i++)
    {
        if (Array[i] == search)
        {
            return true;
        }
    }
    return false;

}

void CopyArrayDistinctNumber(int array[], int copyArray[], int length, int &copyLength)
{
    for (int i = 0; i < length; i++)
    {
        if (CheckNumberInArray(copyArray,copyLength,array[i])==false)
            addArryElement(array[i], copyArray, copyLength);
    }
}

int main()
{
    int Array[100],CopyArray[100];
    int length=0;
    int copyLength=0;

    InputUserNumbersInArray(Array,length);

    CopyArrayDistinctNumber(Array,CopyArray,length,copyLength);

    cout <<"Array length is :"<<length<<endl;
    cout<<"Array 1 elements : ";
    printArry(Array,length);

    cout<<"Array 2 distinct elements : ";
    printArry(CopyArray,copyLength);



}