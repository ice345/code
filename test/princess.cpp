#include <iostream>
using namespace std;
int main() // 一个闯关小游戏
{
    cout << "please enter the number of the game" << endl;
    int n, i;
    cin >> n;   // 闯关数量
    int arr[n]; // vector<int> arr(n);虽然可以运行，但一开始的代码是有问题的，应像后面的那样改
    for (i = 0; i < n; i++)
    {
        cin >> arr[i]; // 输入每一关怪物的战力值
    }
    int q;
    cout << "please enter the number of opportunities:" << endl;
    cin >> q; // 可以闯关的数量
    int sum = 0;
    for (int j = 0; j < q; j++)
    {
        cout << "请输入骑士的战力b" << endl;
        int b; // 骑士战力
        cin >> b;
        for (i = 0; i < n; i++)
        {
            if (b > arr[i])
                sum += 1;
        }
        cout << sum << endl; // 输出骑士可以闯的关卡数
        sum = 0;
    }
    return 0;
}