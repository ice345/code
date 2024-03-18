#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    vector<int> num;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        int m;
        cin >> m;
        num.push_back(m);
    }

    auto it = num.begin();
    while (num.size() > 1) 
    {
        it = num.erase(it + 2); // 每三个元素删除一个

//实际上，std::vector 中的 erase 函数会删除指定位置的元素，并返回一个指向被删除元素之后位置的迭代器。(是会自动，但这里因为可能会超出末尾，所以需要自己手动设定之后的位置)
//因此，it = num.erase(it + 2); 将会删除 it + 2 处的元素，并将迭代器 it 移动到被删除元素之后的位置

        if (it == num.end()) 
        {  // 如果到达末尾，从头开始继续删除
            it = num.begin();
        }
        else if(it+2>num.end())
        {
            it=num.begin()+(it+2-num.end());
        }
    }
    for(int i = 0; i < num.size();i++)
    {
        cout<<"最后一个元素是:"<<num[i];
    }
    return 0;
}
