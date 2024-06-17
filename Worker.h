#pragma once
#include "common.h"
using namespace std;
class Worker
{
public:
	Worker();
	Worker(int m_Id, const string& m_Name, int m_DptId);
	virtual void ShowInfo()=0;
	virtual string GetDeptName() = 0;
public:
	int m_Id;
	string m_Name;
	int m_DptId;
};