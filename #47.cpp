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

float GetFractionNumber(float num)
{
    return num -int(num);
}

float MyRound(float num)
{
    int intNum=int (num);
    float fractionNum=GetFractionNumber(num);

    if (abs(fractionNum) >= 0.5)
    {
        if (num>0)
        return ++intNum;
        else
        return --intNum;
    }
    else
        return intNum;
}

int main()
{
    float num=readNumber();

    
    cout <<"my my round result : "<< MyRound(num)<<endl;
    cout <<"c++ round result : "<<round(num)<<endl;
}