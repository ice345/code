#include <iostream>
using namespace std;

int lastPerson(int n) 
{
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) 
    {
        arr[i] = i + 1; // 初始化数组为 1 ~ n 的序号
    }

    int count = 0; // 记录报数
    int index = 0; // 数组索引
    int left = n;  // 剩余人数

    while (left > 1) 
    {
        if (arr[index] != 0) //忽略掉已经设定为0的人即已经退出了的
        {
            count++; // 报数
            if (count == 3) //到3就退人即设定为0
            {
                arr[index] = 0; // 退出圈子
                count = 0;
                left--;
            }
        }
        index = (index + 1) % n; // 循环移动数组索引
    }

    int result = 0;
    for (int i = 0; i < n; ++i) 
    {
        if (arr[i] != 0) 
        {
            result = arr[i]; // 找到最后留下的人的序号
            break;
        }
    }

    delete[] arr; // 释放数组内存
    return result;
}

int main() 
{
    int n;
    cout << "Enter the number of people: ";
    cin >> n;

    int result = lastPerson(n);
    cout << "The last person originally stood at position: " << result << endl;

    return 0;
}
