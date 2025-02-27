#include <iostream>

using namespace std;

int readNumber()
{
    int number;

    cout << "please enter number :" << endl;
    cin >> number;

    return number;
}

void addArryElement(int number, int arry[], int &lenth)
{
    lenth++;

    arry[lenth - 1] = number;
}

void InputUserNumbersInArray(int array[], int &lenth)
{
    bool checkAnterArry;

    do
    {
        addArryElement(readNumber(), array, lenth);

        cout << "do you want to add more numbers?[0]NO,[1]YES \n";
        cin >> checkAnterArry;

    } while (checkAnterArry == true);
}

void printArry(int arry[], int lenth)
{
    for (int i = 0; i < lenth; i++)
    {
        cout << arry[i] << " ";
    }
    cout << endl
         << endl;
}

bool CheckArrayPalindrome(int Array[], int length)
{
    int counter = 0;
    for (int i = 0; i < length; i++)
    {
        if (Array[i] == Array[length - 1 - i])
        {
            counter++;
        }
    }
    if (counter == length)
        return true;

    return false;
}

int main()
{
    int Array[100];
    int length = 0;

    InputUserNumbersInArray(Array, length);

    if (CheckArrayPalindrome(Array, length))
    {
        cout << "Yes, Array is palindrome.\n";
    }
    else
        cout << "NO, Array is not palindrome.\n";
}