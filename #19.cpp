#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int randomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

int main()
{
    srand(time(0));

    cout << randomNumber(1, 10) << endl;
    cout << randomNumber(1, 10) << endl;
    cout << randomNumber(1, 10) << endl;
}