#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

// 比较函数用于排序
int compareStrings(const void* a, const void* b) 
{
    return strcmp(*(const char**)a, *(const char**)b);
}

// 函数用于对字符串数组进行排序
void sortStrings(char* strings[], int n) 
{
    qsort(strings, n, sizeof(char*), compareStrings);
}

int main() 
{
    const int size = 10;
    char* strings[size];

    cout << "Enter 10 strings:" << endl;
    for (int i = 0; i < size; ++i) 
    {
        strings[i] = new char[100]; // 假设每个字符串最大长度为 100
        cin >> strings[i];
    }

    sortStrings(strings, size);

    cout << "Sorted strings:" << endl;
    for (int i = 0; i < size; ++i) 
    {
        cout << strings[i] << endl;
        delete[] strings[i]; // 释放每个字符串的内存
    }

    return 0;
}
