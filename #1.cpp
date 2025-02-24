#include <iostream>

using namespace std;

void upperPart()
{
    cout << "\t\t\tmultiplication Table from 1 to 10 \n\n";

    for (int i = 1; i <= 10; i++)
    {
        cout<<"\t";
        cout<<i;
    }
    cout<<"\n___________________________________________________________________________________\n";

}

void Calculation()
{
    for(int i=1 ;i<=10; i++)
    {
        cout<<i;
        if(i<10)
        cout<<"   |";
        else
        cout<<"  |";
        for(int a=1;a<=10;a++)
        {
            cout<<"\t";
            cout<<a*i;
        }
        cout<<"\n";

    }
}

int main()
{
    upperPart();
    Calculation();
}