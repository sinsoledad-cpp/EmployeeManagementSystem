#pragma once
#include "common.h"
using namespace std; 
class Employee :public Worker
{
public:
	Employee(int id, string name, int did);
	virtual void ShowInfo();
	virtual string GetDeptName();
};