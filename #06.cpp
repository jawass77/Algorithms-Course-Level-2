#include <iostream>

using namespace std;

int ReadPostevNumber()
{

    int num;
    do
    {
        cout << "enter postive number : \n";
        cin >> num;
    } while (num < 0);

    return num;
}

int SumReverseNumber(int num)
{
    int sum=0;
    int remainder = num;
    while (remainder>0)
    {
        sum+=remainder%10;
        remainder/=10;

    }
    return sum;
}

int main()
{
    cout<<"sum of Digits : "<<SumReverseNumber(ReadPostevNumber());
}
