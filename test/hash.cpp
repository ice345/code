#include <iostream>
#include <cstring>
using namespace std;

void sumOfunique(char str[], int len) 
{
    int hash[256]; // 将哈希表大小设置为 ASCII 字符的范围,这个256也是刚好对应ascii码的256个

    memset(hash, 0, sizeof(hash));
    for (int i = 0; i < len; i++) 
    {
        hash[str[i]]++; // 对字符的频率进行计数，能实现这样是因为字符会自动转为ascii码，这也刚好对应要256个，不然没法对应起来
    }

    bool foundUnique = false;
    for (int i = 0; i < len; i++) 
    {
        if (hash[str[i]] == 1) 
        { // 找到第一个频率为1的字符
            cout << str[i];
            foundUnique = true;
            break;
        }
    }

    if (!foundUnique) 
    {
        cout << "none"; // 如果没有唯一的字符，输出 "none"
    }
    cout << endl;
}

int main() 
{
	//cin >> size; 会读取一个整数值，但它会留下一个换行符在输入缓冲区中，然后 cin.getline() 会立即读取这个换行符，导致似乎跳过了你的输入。
    int size;
    cout<<"pleast enter the size that you want"<<endl;
    cin>>size;
    cin.ignore();
    cout<<"please enter the string that you want"<<endl;
    char *str = new char[size];

    cin.getline(str,size);

    sumOfunique(str, size);//str其实就是首地址，数组名就是首地址
    delete []str;
    return 0;
}
