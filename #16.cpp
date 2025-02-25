#include <iostream>

using namespace std;

void PrintAllWordsFromAAAToZZZ()
{
    for (int i = 65; i <= 90; i++)
    {

        for (int a = 65; a <= 90; a++)
        {
            for (int j = 65; j <= 90; j++)
            {
                cout << char(i);
                cout << char(a);
                cout << char(j);
                cout << endl;
            }
        }
    }
}

int main()
{
    PrintAllWordsFromAAAToZZZ();
}