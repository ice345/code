#pragma once
#include <string>
#define subject 6
// 学生类
class Student
{
public:
    Student();
    void set(const std::string &name, const std::string &number); // 设定学号，姓名
    // Student(const std::string & name,const std::string & number);
    // 这种也可以赋值，按理这种函数重载是赋值最常用的，但这是明确了对象这样定义才方便
    // 就是我知道有一个对象，我就直接auto 谁=Student(...);这样
    std::string get_name();              // 得到姓名
    std::string get_number();            // 得到学号
    int get_avg();                       // 得到平均分
    void set_arr(int score[], int size); // 设定六科成绩
    void get_arr();                      // 得到六科成绩，通过打印的方法
    ~Student();                          // 析构
    int cal_avg();                       // 这个就不用传参了，因为本身我就是用头文件中的SCORE[]的
    void set_rank(int rank);             // 设定排名
    int get_rank();                      // 得到排名
private:
    std::string NAME;
    std::string NUMBER;
    int SCORE[subject];
    int AVG;
    int RANK;
};