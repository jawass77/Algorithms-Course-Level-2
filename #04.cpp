#include <iostream>
#include <cmath>

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

bool checkPerfectNumber(int num)
{
    int m = round(num / 2);
    int sum = 0;
    for (int i = 1; i <= m; i++)
    {
        if (num % i == 0)
            sum += i;
    }
    if (sum == num)
        return true;
    else
        return false;
}

void PrintPerfectNumber(int num)
{
    for (int i = 1; i <= num; i++)
        if (checkPerfectNumber(i))
            cout << i << " is perfect\n";
        
}

int main()
{
    int num=ReadPostevNumber();
    PrintPerfectNumber(num);
}
