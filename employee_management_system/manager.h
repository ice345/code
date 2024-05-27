#pragma once
#include <iostream>
#include <string>
#include "worker.h"

class Manager : public Worker
{
public:
    // 构造函数创建个人信息
    Manager(string m_DeptName ,string m_Name ,int m_Id);

    // 展示个人信息
    virtual void showInfo();

    // 获取职工部门名称
    virtual string getDeptName();

    // 析构函数
    ~Manager();
};
