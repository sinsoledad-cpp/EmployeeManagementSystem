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
    cout << "ְ�����: " << m_Id
        << "\tְ������: " << m_Name
        << "\t��λ: " << this->GetDeptName()
        << "\t��λְ��: ����˾��������" << endl;
}

string Boss::GetDeptName()
{
    return "�ܲ�";
}
