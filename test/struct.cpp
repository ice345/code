#include <iostream>
#include <string>
using namespace std;
// 定义结构体
struct hero
{
    string name;
    int age;
    string sex;
};
void bubblesort(struct hero heroarray[], int len)
{
    int temp = 0;
    string name1;
    string sex1;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (heroarray[j].age > heroarray[j + 1].age) // 用年龄判断
            {
                temp = heroarray[j].age;
                heroarray[j].age = heroarray[j + 1].age;
                heroarray[j + 1].age = temp; // 换年龄

                name1 = heroarray[j].name;
                heroarray[j].name = heroarray[j + 1].name;
                heroarray[j + 1].name = name1; // 换姓名

                sex1 = heroarray[j].sex;
                heroarray[j].sex = heroarray[j + 1].sex;
                heroarray[j + 1].sex = sex1; // 换性别
            }
        }
    }
};
void printer(struct hero heroarray[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << heroarray[i].name << "\t " << heroarray[i].age
            << "\t " << heroarray[i].sex;
        cout << endl;
    }
};
int main()
{
    struct hero heroarray[3] =
        {
            {"昴", 24, "girl"},
            {"潘国熙", 19, "girl"},
            {"梁俊斌", 23, "boy"}};                     // 定义结构体数组
    int len = sizeof(heroarray) / sizeof(heroarray[0]); // 元素个数
    bubblesort(heroarray, len);                         // 传的是数组地址，数组名可以是地址
    printer(heroarray, len);
    return 0;
}