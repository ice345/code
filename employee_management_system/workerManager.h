/**
 * @brief 职工管理系统头文件
 * @details 这个主要实现的是人机交互菜单界面，职工增删改查功能，文件的读写功能
*/

#pragma once //防止头文件重复包含使得重复编译
#include <iostream>
#include <fstream>
#include <string>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#define DATA_FILENAME "empFile.txt" //数据文件名称
#define ADMIN_FILENAME "adminFile.txt" //管理员文件名称


class WorkerManager
{
public:
    //构造函数
    WorkerManager();

    // 展示菜单
    void showMenu();

    // 退出系统
    void exitSystem();

    // 增加职工
    void addEmp();

    // 显示职工
    void showEmp();

    // 删除职工
    void delEmp();

    // 修改职工
    void modEmp();

    // 查找职工
    void findEmp();

    // 排序职工
    void sortEmp();

    // 清除文件
    void cleanFile();

    // 写入数据到文件
    void save();

    // 获取职工人数
    int get_EmpNum();

    // 是否存在该职工
    int isExist(int id);

    // 初始化员工
    void init_Emp();

    void test_1();

    //析构函数
    ~WorkerManager();

private:
    int m_EmpNum; //职工人数
    Worker **m_EmpArray; //存放职工的数组指针
    bool m_FileIsEmpty; //文件是否为空
};