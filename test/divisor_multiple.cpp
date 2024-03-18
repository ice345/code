#include <iostream>
using namespace std;

int gcd(int x, int y)
{
    if (y == 0)
    {
        return x;
    }
    return gcd(y, x % y); // 如果是12，18，这样还可以交换位置，卧槽，不然就算下去
}

int lcm(int x, int y)
{
    return (x * y) / gcd(x, y);
}

int main()
{
    int x, y;
    cout << "请输入两个数字 x 和 y：" << endl;
    cin >> x >> y;

    int greatest_common_divisor = gcd(x, y);
    int least_common_multiple = lcm(x, y);

    cout << "最大公约数是：" << greatest_common_divisor << endl;
    cout << "最小公倍数是：" << least_common_multiple << endl;

    return 0;
}
