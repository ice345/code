/**
 * @brief 主函数实现
 * @details worker.h头文件就是一个多态实现各员工的功能
 * @param 编译命令：g++ employee_management_system.cpp workerManager.cpp employee.cpp manager.cpp boss.cpp -o employee_management_system
 * @param 想要使用gdb调试的话：g++ -g employee_management_system.cpp workerManager.cpp employee.cpp manager.cpp boss.cpp -o employee_management_system
*/


#include <iostream>
using namespace std;
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

void test(WorkerManager* wm)
{
    wm->test_1();
}

int main()
{
    // 实例化管理者对象
    WorkerManager wm;

    test(&wm);

    int choice = 0; // 创建用户选择变量
    while(true)
    {
        // 调用展示菜单成员函数
        wm.showMenu();
        cout << "请输入您的选择：" << endl;
        cin >> choice; // 接收用户选择
        switch(choice)
        {
            case 0: // 退出系统
                wm.exitSystem();
                break;
            case 1: // 增加职工
                wm.addEmp();
                break;
            case 2: // 显示职工
                wm.showEmp();
                break;
            case 3: // 删除职工
                wm.delEmp();
                break;
            case 4: // 修改职工
                wm.modEmp();
                break;
            case 5: // 查找职工
                wm.findEmp();
                break;
            case 6: // 排序职工
                wm.sortEmp();
                break;
            case 7: // 清空文档
                wm.cleanFile();
                break;
            default:
                system("cls"); // 清屏
                break;
        }
    }


    system("pause");
    return 0;
}