#include "boss.h"

Boss::Boss(string DeptName, string Name, int Id)
{
    this->m_Id=Id;
    this->m_Name=Name;
    this->m_DeptName=DeptName;
}


void Boss::showInfo()
{
    std::cout<<"职工编号为："<<this->m_Id
        <<"\t职工姓名为:"<<(this->m_Name)
        <<"\t职工部门名称为:"<<(this->m_DeptName)
        <<"\t岗位职责是:管理公司所有事务"<<endl;
}

string Boss::getDeptName()
{
    return m_DeptName;
}

Boss::~Boss()
{
}