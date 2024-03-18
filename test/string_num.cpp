#include <iostream>
using namespace std;
#include <string>
#include <vector>
int count_string_number(const string &str)
{
    int total = 0;
    vector<string> string_num;
    for (int i = 0; i < str.length();i++)
    {
        string str_num;
        if(str[i]>='0'&&str[i]<='9')
        {
            while(i<str.length() && str[i]>='0'&&str[i]<='9')
            {
                str_num+=str[i];
                i++;
            }
            string_num.push_back(str_num);
            ++total;
        }
    }
    for(int i = 0; i < string_num.size();i++)
    {
        cout << string_num[i];
        cout<<" ";
    }
    cout<<endl;
    return total;
}

int main()
{
    string str;
    cout<<"请输入任意想输入的："<<endl;
    cin>>str;
    cout<<count_string_number(str)<<endl;
    return 0;
}