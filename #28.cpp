#include <iostream>
#include <cstdlib>
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

void readArryWithRandomNumbers(int arry[], int lenth)
{
    for (int i = 0; i < lenth; i++)
    {
        arry[i] = randomNumber(10, 100);
    }
}

void CopyArry(int arry[], int copyArry[], int lenth)
{
    for (int i = 0; i < lenth; i++)
    {
        copyArry[i] = arry[i];
    }
}

void printArry(int arry[], int copyArry[], int lenth)
{
    cout << "array 1 enemints: \n";
    for (int i = 0; i < lenth; i++)
    {
        cout <<arry[i] << " ";
    }
    cout<<endl<<endl;

    cout << "array 2 enemints after copy : \n";

    for (int a = 0; a < lenth; a++)
    {
        cout <<copyArry[a] << " ";
    }
    cout<<endl<<endl;

}

int main()
{
    srand(time(0));
    int arry[100], copyArry[100];
    int lenth = ReadPostevNumber("enter number from 1 to 100");

    readArryWithRandomNumbers(arry, lenth);
    CopyArry(arry,copyArry,lenth);


    printArry(arry,copyArry, lenth);
}