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

int printNumberPattern(int num)
{
    for (int a=1;a <= num;a++)
    {
        for (int i = 1; i <= a; i++)
        {
            cout << a;
        }
        cout<<endl;
    }
}

int main()
{
    printNumberPattern(ReadPostiveNumber("enter a number"));

}