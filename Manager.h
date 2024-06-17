#pragma once
#include "common.h"
using namespace std;
class Manager :public Worker
{
public:
	Manager(int id, string name, int idi);
	virtual void ShowInfo();
	virtual string GetDeptName();
};