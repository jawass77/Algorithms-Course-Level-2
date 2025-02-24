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

int main()
{
    cout<<ReverseNumber(ReadPostevNumber());
}
