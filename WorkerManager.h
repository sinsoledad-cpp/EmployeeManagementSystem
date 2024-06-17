#pragma once
#include "common.h"
using namespace std;
class WorkerManger
{
	friend class Worker;
public:
	WorkerManger();
	void Show_Menu();
	void ExitSystem();
	void Add_Emp();
	void Save() const;
	int get_EmpNum();
	void init_Emp();
	void Show_Emp();
	int IsExist(int id) const;
	void Del_Emp();
	void Mod_Emp();
	void Find_Emp();
	void Sort_Emp();
	void Clean_File();
	~WorkerManger();
public:
	int m_EmpNum;
	Worker** m_EmpArray;
	bool m_FileIsEmpty;
};