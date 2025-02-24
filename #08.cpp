#include <iostream>

using namespace std;

int ReadPostiveNumber(string text)
{

    int num;
    do
    {
        cout <<text<<endl;
        cin >> num;
    } while (num < 0);

    return num;
}

int LastNumber(int num)
{
    return num%10;

}


int calculatLenth(int num)
{
    int lenth=0;
    while(num>0)
    {
        num/=10;
        lenth++;
    }
    return lenth;

}

int calculatFrequence(int num ,int serch)
{
    int length=calculatLenth(num);
    int counter=0;
    for (int i =1 ;i<=length;i++)
    {
        if (serch==LastNumber(num))
        counter++;
        num/=10;

    }
    return counter;
}


int main()
{
    int number =ReadPostiveNumber("enter Number?");
    int key =ReadPostiveNumber("enter serch?");

    cout<<"Digit "<<key<<" frequence "<<calculatFrequence(number,key)<<"Time(s)"<<endl;

}