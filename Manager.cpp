#pragma once
#include "common.h"
using namespace std;
Manager::Manager(int id, string name, int idi)
{
	m_Id = id;
	m_Name = name;
	m_DptId = idi;
}
void Manager::ShowInfo()
{
	cout << "ְ�����: " << m_Id
		<< "\tְ������: " << m_Name
		<< "\t��λ: " << GetDeptName()
		<< "\t��λְ��: ����ϰ彻��������" << endl;
}
string Manager::GetDeptName()
{
	return "����";
}
