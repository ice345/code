#include <iostream>
#include <string>
#include <vector>
#include "demo.h"
bool flag;  // 定义一个flag（bool），用来判断是否运算过程中是否出错
double end; // 定义结果
double cal_number(double num_1, char op, double num_2)
{
    while (1) // 循环（出错就循环），正确就跳出
    {
        switch (op)
        {
            case '+':
                end = num_1 + num_2;
                flag = true;
                break;
            case '-':
                end = num_1 - num_2;
                flag = true;
                break;
            case '*':
                end = num_1 * num_2;
                flag = true;
                break;
            case '/':
                if (num_2 == 0)
                {
                    // std::cout<<"注意!除数不能为0!"<<std::endl;
                    flag = false;
                    break;
                }
                else
                {
                    end = num_1 / num_2;
                    flag = true;
                    break;
                }
            default:
            {
                // std::cout<<"你输入的操作符号有误,请重新输入"<<std::endl;
                flag = false;
                break;
            }
        }
        if (flag == false)
        {
            system("clear");
            std::cout << "你输入的操作符号有误或者除数为0,请重新输入" << std::endl;
            std::cout << "请重新输入第一个操作数：" << std::endl;
            std::cin >> num_1;
            std::cout << "请重新输入操作符号：" << std::endl;
            std::cin >> op;
            std::cout << "请重新输入第二个操作数：" << std::endl;
            std::cin >> num_2;
        }
        else
            break;
    }
    return end; //返回结果
};

// 这个液晶化显示操作，它是对数字每一位都会遍历，然后从上到下模拟液晶化，所以到最后输完了所有位的一行就会换行
void displayLCD(const std::string &number)
{
    for (int i = 0; i < 5; ++i)
    {
        for (char digit : number)
        {
            int index; // 定义一个下标，以此判断遍历这个数字后，该位是什么，从而去到液晶化数字那索引
            // 用多个判断来判断如何操作更稳妥
            if (isdigit(digit)) // 这要判断，因为这也是一种情况，否则将其放在后面（这样可以不用加if），让后面的代码先运行
            {
                index = digit - '0'; // 将字符转换为对应的数字索引
            }
            else if (digit == '.')
            {
                index = 10; // 小数点对应的索引
            }
            else if (digit == '-')
            {
                index = 11; // 负号对应的索引
            }
            else
            {
                continue; // 如果是无效字符，跳过处理（这是重要的，否则会出现bug，无法正确显示）
            }
            // 这是用&引用操作，相当于起别名，通过它对lcdCharacters中的一行直接操作（是一维vector，类型是string）。不加&就会重新复制操作，既会占内存，又可能会出bug
            const std::vector<std::string> &lcdDigit = lcdCharacters[index];
            // 索引操作
            std::cout << lcdDigit[i] << "  ";
        }
        std::cout << std::endl;
    }
}

// 下面就是没用多个if判断，就出现错位等情况

// void displayLCD(const std::string& number)
// {
//     // bool is_negative=(number[0]=='-');
//     // std::string displaynumber=number;
//     // if(is_negative)
//     // {
//     //     displaynumber=number.substr(1);
//     // }
//     for(int i=0;i<5;i++)
//     {
//         for(char digit:number)
//         {
//             // int index;
//             // if(is_negative && i==2)
//             // {
//             //     index=11;
//             // }
//             // else if(digit =='.')
//             // {
//             //     index=10;
//             // }
//             // else
//             // {
//             //     index=digit-'0';
//             // }
//             int index=digit-'0';
//             const std::vector<std::string>& sub_lcdCharacter=lcdCharacters[index];
//             std::cout<<sub_lcdCharacter[i]<<"  ";
//         }
//         std::cout<<std::endl;
//     }
// };
