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
	cout << "职工编号: " << m_Id
		<< "\t职工姓名: " << m_Name
		<< "\t岗位: " << GetDeptName()
		<< "\t岗位职责: 完成老板交给的任务" << endl;
}
string Manager::GetDeptName()
{
	return "经理";
}
