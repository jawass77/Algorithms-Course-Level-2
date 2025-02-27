#include <iostream>
#include <cmath>

using namespace std;

float readNumber()
{
    float num;

    cout<<"enter your number, please : \n";
    cin>>num;

    return num;
}

float MySqrt(float num)
{

   return pow(num,0.5);
}

int main()
{
    float num=readNumber();

    
    cout <<"my my Sqrt result : "<< MySqrt(num)<<endl;
    cout <<"c++ Sqrt result : "<<sqrt(num)<<endl;
}