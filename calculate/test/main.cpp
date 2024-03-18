#include <iostream>
#include <string>
#include "demo.h"
int main()
{
    double num_1, num_2, result; // 定义操作数和结果
    char op;                     // 定义运算符
    char select;
    while (1)
    {
        std::cout << "请输入你的选择,输入y代表继续计算,输入n表示你退出计算" << std::endl;
        std::cin >> select; // 弄选择
        if (select == 'y')
        {
            // 输值操作
            std::cout << "请输入第一个操作数：" << std::endl;
            std::cin >> num_1;
            std::cout << "请输入你想进行的运算：+ - * / ,除数为0会重新输值计算" << std::endl;
            std::cin >> op;
            std::cout << "请输入第二个操作数：" << std::endl;
            std::cin >> num_2;
            // 带入函数
            result = cal_number(num_1, op, num_2); // 进行计算数值,不符合就重新计算（在函数体内包含循环）
            // 液晶化操作
            std::string result_str = std::to_string(result); // 转换为string类
            displayLCD(result_str);                          // 对结果液晶化
        }
        else if (select == 'n')
        {
            std::cout << "你选择退出计算" << std::endl;
            break;
        }
    }
    std::cin.get();
    return 0;
}
