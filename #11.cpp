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
    int reverse = 0;
    int remainder = num;
    while (remainder > 0)
    {
        reverse = reverse * 10 + (remainder % 10);
        remainder /= 10;
    }
    return reverse;
}

bool checkPalindromeNumber(int num)
{
    return num == ReverseNumber(num);
}

int main()
{
    if (checkPalindromeNumber(ReadPostiveNumber("enter a Number?")))
        cout << "Yes, it is a palindrome number.\n";
    else
        cout << "No, it is not a palindrome number.\n";
}