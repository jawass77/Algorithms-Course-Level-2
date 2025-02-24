#include <iostream>

using namespace std;

int ReadPostevNumber()
{

    int num;
    do
    {
        cout << "enter postev number : \n";
        cin >> num;
    } while (num < 0);

    return num;
}

void PrintReverseNumber(int num)
{
    int remainder = num;
    while (remainder>0)
    {
        cout<<remainder%10<<endl;
        remainder/=10;       
    }
}

int main()
{
    PrintReverseNumber(ReadPostevNumber());
}
