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

float MyFloor(float num)
{
    int intNum=int (num);
    float fractionNum=GetFractionNumber(num);

    if (abs(fractionNum) > 0)
    {
        if (num>0)
        return intNum;
        else
        return --intNum;
    }
    else
        return intNum;
}

int main()
{
    float num=readNumber();

    
    cout <<"my floor result : "<< MyFloor(num)<<endl;
    cout <<"c++ floor result : "<<floor(num)<<endl;
}