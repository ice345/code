#include <iostream>
#include "Student.h"

// 我好像如果在这用了inline就不行了，好像要在头文件那才可inline，可能是因为要在同一个文件才能inline
// 这是为什么呢，我不是很理解（其实inline也不是很好，复杂的内敛展开，编译器还不一定接受）

// 构造函数
Student::Student(){};

// 析构函数
Student::~Student(){};

// 对学生姓名和学号进行设定

void Student::set(const std::string &name, const std::string &number)
{
    NAME = name;
    NUMBER = number;
};

// 返回学生学号
std::string Student::get_number()
{
    return NUMBER;
};

// 得到姓名
std::string Student::get_name()
{
    return NAME;
};

// 设置六科成绩的整个数组
void Student::set_arr(int score[], int size)
{
    for (int i = 0; i < size; i++)
    {
        SCORE[i] = score[i];
    };
};

// 得到六科成绩,既然返回一个数组难，我直接在这写一个函数，让其打印就行
void Student::get_arr()
{
    std::cout << "这是学生六科的成绩：" << std::endl;
    for (int i = 0; i < subject; i++)
    {
        std::cout << SCORE[i] << "\t";
    }
};

// 这是求平均分
int Student::cal_avg()
{
    int total = 0;
    for (int i = 0; i < subject; i++)
    {
        total += SCORE[i];
    }
    AVG = total / subject;
    return AVG;
};

// 得到平均分
int Student::get_avg()
{
    return AVG;
};

// 设置排名
void Student::set_rank(int rank)
{
    RANK = rank;
};

// 返回排名
int Student::get_rank()
{
    return RANK;
};