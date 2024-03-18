#include <iostream>
#include "Student.h"
#include <stdio.h>
#include <algorithm> // 包含用于排序的头文件
#define MAX 2
int main()
{
    Student student[MAX];     // 定义学生类数组
    std::string name, number; // 姓名，学号
    int rank;                 // 排名
    int avg_arr[MAX];
    std::cout << "输入学生的信息" << std::endl;

    // 设置各种信息
    for (int i = 0; i < MAX; i++)
    {
        int score[subject]; // 六科分数数组
        std::cout << "输入学生的姓名学号" << std::endl;
        std::cin >> name >> number;   // 输入姓名，学号
        student[i].set(name, number); // 设置姓名，学号这些
        std::cout << "输入学生的六科成绩" << std::endl;
        for (int j = 0; j < subject; j++)
        {
            std::cin >> score[j]; // 输入成绩
        }
        student[i].set_arr(score, subject); // 设置学生成绩
        avg_arr[i] = student[i].cal_avg();  // 平均分数组，每一个学生的，还没排序
    }
    // 按平均分排序，并设定排名,从小到大排列
    std::sort(avg_arr, avg_arr + MAX, std::greater<int>()); // 传首地址和末地址，排列方式
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            if (student[j].cal_avg() == avg_arr[i])
            {
                student[j].set_rank(i + 1);
                break;
            }
        }
    }
    // 设置各种信息

    // 得到学生各种信息
    std::string number1; // 因为学号是唯一判定标准
    std::cout << "输入你想查询的学生的信息(要输入学号查询)" << std::endl;
    std::cin >> number1;
    int flag = 0;                 // 弄一个标志，判断是否在数组内
    for (int i = 0; i < MAX; i++) // 遍历学生类数组，查看是否存在该学号的学生
    {
        if (student[i].get_number() == number1) // 用学号判断输入的学生是否存在
        {
            std::cout << student[i].get_name() << "\t"      // 打印姓名
                      << student[i].get_number() << "\t"    // 打印学号
                      << student[i].get_rank() << "\t"      // 打印排名
                      << student[i].get_avg() << std::endl; // 打印平均分
            student[i].get_arr();                           // 打印六科成绩
            flag = 1;
        }
    }
    if (flag == 0)
    {
        std::cout << "你输入的学号不符合或者是没有这个学生" << std::endl;
    }
    system("pause");
    return 0;
}