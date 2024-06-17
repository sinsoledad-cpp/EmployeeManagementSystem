#pragma once
#include "common.h"
using namespace std;
class Boss :public Worker
{
public:
	Boss(int id, string name, int idi);
	virtual void ShowInfo();
	virtual string GetDeptName();
};