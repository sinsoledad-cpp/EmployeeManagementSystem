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
    cout << "ְ�����: " << m_Id
        << "\tְ������: " << m_Name
        << "\t��λ: " << this->GetDeptName()
        << "\t��λְ��: ��ɾ�����������" << endl;
}
string Employee::GetDeptName()
{
    return "Ա��";
}

