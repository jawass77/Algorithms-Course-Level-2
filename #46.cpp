#include <iostream>
#include <cmath>

using namespace std;

float readNumber()
{
    int num;

    cout<<"enter your number, please : \n";
    cin>>num;

    return num;
}

float MyAbs(float num)
{
    if (num > 0)
        return num;
    else
        return num * -1;
}

int main()
{
    float num=readNumber();

    cout <<"my abs result : "<< MyAbs(num)<<endl;
    cout <<"c++ abs result : "<<abs(num)<<endl;
}