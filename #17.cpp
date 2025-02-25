#include <iostream>

using namespace std;

string readWord(string text)
{
    string word;
    cout << text << endl;
    cin >> word;

    return word;
}

string SearchKeyFromAAAToZZZ(string key)
{
    int counter = 0;
    for (int i = 65; i <= 90; i++)
    {

        for (int a = 65; a <= 90; a++)
        {
            for (int j = 65; j <= 90; j++)
            {
                string word = "";
                word = word + char(i);
                word = word + char(a);
                word = word + char(j);
                counter++;

                cout << "Trail[" << counter << "]: " << word << endl;

                if (key == word)
                {
                    cout << endl
                         << endl;
                    cout<<"password is " + word + "\nFound atrer "<< counter<< " Trial(s)\n";
                    return 0;
                    
                }
                word = "";
            }
        }
    }
    return "password is not here \n";
}

int main()
{
    cout << SearchKeyFromAAAToZZZ(readWord("enter a key?"));
}