#include <iostream>
using namespace std;
#include <cstring>
int sumOfUnique(int *nums, int n)
{
    int hash[101];
    int i, sum = 0;
    memset(hash, 0, sizeof(hash)); // 将hash设为0
    for (i = 0; i < n; ++i)
    {
        ++hash[nums[i]];
    } // 读取num，映射到hash上
    for (i = 0; i < n; ++i)
    {
        if (hash[nums[i]] == 1)
        {
            sum += nums[i];
        }
    } // 读取hash，其实总量也不多于n
    return sum;
}

int main()
{
    int num[5];
    for (int i = 0; i < 5; ++i)
    {
        cin >> num[i];
    }
    int result=sumOfUnique(num,5);
    return 0;
}
