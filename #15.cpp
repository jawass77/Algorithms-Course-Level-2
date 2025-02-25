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

int printLatterPattern(int num)
{
    for (int a=1;a <= num;a++)
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
    printLatterPattern(ReadPostiveNumber("enter a number"));

}