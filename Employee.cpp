#pragma once
#include "common.h"
using namespace std;
Employee::Employee(int id,string name,int did)
{
    m_Id = id;
    m_Name = name;
    m_DptId = did;
}
void Employee::ShowInfo()
{
    cout << "职工编号: " << m_Id
        << "\t职工姓名: " << m_Name
        << "\t岗位: " << this->GetDeptName()
        << "\t岗位职责: 完成经理交给的任务" << endl;
}
string Employee::GetDeptName()
{
    return "员工";
}

