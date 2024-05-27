#include "employee.h"
#include <cstring> // Include the <cstring> header file

Employee::Employee(string DeptName, string Name,int Id)
{
    this->m_Id=Id;
    this->m_Name=Name;
    this->m_DeptName=DeptName;
}

void Employee::showInfo()
{
    std::cout<<"职工编号为："<<this->m_Id
        <<"\t职工姓名为:"<<(this->m_Name)
        <<"\t职工部门名称为:"<<(this->m_DeptName)
        <<"\t岗位职责是:完成经理分配的任务"<<endl;
}

string Employee::getDeptName()
{
    return m_DeptName;
}

Employee::~Employee()
{
}