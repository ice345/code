#include <iostream>
#include <string>
#include <cmath>
using namespace std;
const int basic=3;
string three_basic(int num,string str)
{
    if(num<=basic)
    {
        str+=to_string(num%basic);
    }
    else
    {
        str+=to_string(num%basic);
        num=num/basic;
        return three_basic(num,str);
    }
    return str;
}

int main()
{
    int num;
    cout<<"请输入一个你想转换的数字"<<endl;
    cin >> num;
    string str;
    string result=three_basic(abs(num),str);
    if(num>=0)
    {
        for(int i=result.length()-1;i>=0;i--)
        {
            if(result[i]!='2')
            {
                cout<<result[i];
            }
            else
            {
                cout<<"1Z";
            }
        }
        cout<<endl;
    }
    if(num<0)
    {
        for(int i=result.length()-1;i>=0;i--)
        {
            if(result[i]=='2')
            {
                cout<<"Z0";
            }
            else if(result[i]=='1')
            {
                cout<<'Z';
            }
            else cout<<result[i];
        }
    }
    return 0;
}