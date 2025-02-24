#include<iostream>
#include<cmath>

using namespace std;

enum PrimeNotPrime
{
    prime = 1,
    notPrime = 2
};

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

PrimeNotPrime checkPrimeNotPrime(int num)
{
    int m = round(num / 2);

    for (int a = 2; a <= m; a++)
    {
        if (num % a == 0)
        {
            return PrimeNotPrime::notPrime;
        }
    }
    return PrimeNotPrime::prime;
}

void PrintPrimeNumber(int num)
{
    for(int i =1;i<=num;i++)
    {
        if(checkPrimeNotPrime(i)==prime)
        cout<<i<<endl;
    }

}

int main()
{
    PrintPrimeNumber(ReadPostevNumber());

}