#include <iostream>
#include <string>
#include <cstring>
using namespace std;
void first_str(string &str,int len)
{
    int hash[256];
    memset(hash,0,sizeof(hash));
    for(char c:str)
    {
        ++hash[c];
    }
    bool isfound = false;
    for(int i=0; i<len;i++)
    {
        if(hash[str[i]]==1)
        {
            cout<<str[i]<<endl;
            isfound = true;
            break;
        }
    }
    if(!isfound)
    {
        cout<<"none"<<endl;
    }
}

int main()
{
    string str;
    getline(cin, str);
    int len=str.length();
    first_str(str,len);
    return 0;
}