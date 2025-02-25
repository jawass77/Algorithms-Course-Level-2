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

int printInveretedNumber(int num)
{
    for (int a=num;a > 0;a--)
    {
        for (int i = 1; i <= num; i++)
        {
            cout << num;
        }
        cout<<endl;
        num--;
    }
}

int main()
{
    printInveretedNumber(ReadPostiveNumber("enter a number"));

}