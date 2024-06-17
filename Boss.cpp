#pragma once
#include "common.h"
using namespace std;
Boss::Boss(int id, string name, int idi)
{
    m_Id = id;
    m_Name = name;
    m_DptId = idi;
}

void Boss::ShowInfo()
{
    cout << "职工编号: " << m_Id
        << "\t职工姓名: " << m_Name
        << "\t岗位: " << this->GetDeptName()
        << "\t岗位职责: 管理公司所有事物" << endl;
}

string Boss::GetDeptName()
{
    return "总裁";
}
