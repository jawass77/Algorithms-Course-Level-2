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

int ReverseNumber(int num)
{
    int reverse=0;
    int remainder = num;
    while (remainder>0)
    {
        reverse=reverse*10+(remainder%10);
        remainder/=10;

    }
    return reverse;
}

void PrintDigits(int num)
{
    int result=0;

    while(num>0)
    {
        result=num%10;
        num/=10;
        cout<<result<<endl;

    }
}

int main()
{
    PrintDigits(ReverseNumber(ReadPostiveNumber("enter NUmber?")));
}