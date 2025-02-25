#include <iostream>
#include <string>

using namespace std;

string readText()
{
    string name;

    cout << "what is your text" << endl;
    getline(cin, name);

    return name;
}

string EncryptText(string text,int key)
{
    string AfterEncryptText="";
    for (int i = 0; i <= text.length(); i++)
    {
        AfterEncryptText= AfterEncryptText+ char((int)text[i]+key);
        
    }
return AfterEncryptText;
}

string DecryptText(string text,int key)
{
    string AfterDecryptText="";
    for (int i = 0; i < text.length(); i++)
    {
        AfterDecryptText=AfterDecryptText+ char((int)text[i]-key);
    }
    return AfterDecryptText;

}

int main()
{
    int key=2;
string text=readText();
string AfterEncryptionText=EncryptText(text,key);
string AfterDecryptionText=DecryptText(AfterEncryptionText,key);

cout <<"Text Before Encryption : "<<text<<endl;
cout<<"Text After Encryption : "<<AfterEncryptionText<<endl;
cout<<"Text After Decryption : "<<AfterDecryptionText<<endl;
}