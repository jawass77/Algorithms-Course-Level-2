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

int printInvertedLatterPattern(int num)
{
    for (int a=num;a > 0;a--)
    {
        for (int i = 1; i <= a; i++)
        {
            cout << char(64+a);
        }
        cout<<endl;
    }
}

int main()
{
    printInvertedLatterPattern(ReadPostiveNumber("enter a number"));

}