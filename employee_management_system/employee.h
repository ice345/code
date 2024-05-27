#pragma once //避免重复包含，避免重复编译
#include <iostream>
#include <string>
#include  "worker.h"

class Employee : public Worker
{
public:
    // 构造函数创建个人信息
    Employee(string m_DeptName ,string m_Name ,int m_Id);

    // 显示个人信息
    virtual void showInfo();

    // 获取职工部门名称
    virtual string getDeptName();

    // 析构函数
    ~Employee();

};