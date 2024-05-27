#pragma once //防止头文件重复包含使得重复编译
#include <iostream>
using namespace std;
#include <cstring>

// 职工抽象类
class Worker
{
public:
    // 显示个人信息
    virtual void showInfo() = 0;

    // 获取岗位名称
    virtual string getDeptName() = 0;

    int m_Id; //职工编号
    string m_Name; //职工姓名指针，尽量不要在类内使用string
    string m_DeptName; //职工所在部门名称
};