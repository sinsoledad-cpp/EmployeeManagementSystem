#pragma once
#include "common.h"
using namespace std;
WorkerManger::WorkerManger()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		m_EmpNum = 0;
		m_EmpArray = NULL;
		m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空!" << endl;
		m_EmpNum = 0;
		m_FileIsEmpty = true;
		m_EmpArray = NULL;
		ifs.close();
		return;
	}
	int num = get_EmpNum();
	cout << "职工人数为: " << num << endl;
	m_EmpNum = num;
	m_EmpArray = new Worker * [m_EmpNum];
	init_Emp();
	for (int i = 0; i < m_EmpNum; i++)
	{
		cout << "职工编号: " << m_EmpArray[i]->m_Id<<" "
			<< "职工姓名: " << m_EmpArray[i]->m_Name<<" "
			<< "部门编号: " << m_EmpArray[i]->m_DptId<< endl;
	}
	ifs.close();
}
void WorkerManger::Show_Menu()
{
	cout << "职工管理系统" << endl;
	cout << "0.退出管理系统" << endl;
	cout << "1.增加职工信息" << endl;
	cout << "2.显示职工信息" << endl;
	cout << "3.删除离职职工" << endl;
	cout << "4.修改职工信息" << endl;
	cout << "5.查找职工信息" << endl;
	cout << "6.按照编号排序" << endl;
	cout << "7.清空所有文档" << endl;
}
void WorkerManger::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	//system("pause");
	exit(0);
}
void WorkerManger::Add_Emp()
{
	cout << "请输入添加职工数量: " << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize = m_EmpNum + addNum;
		Worker** newSpace = new Worker * [newSize];
		if (m_EmpArray != NULL)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				newSpace[i] = m_EmpArray[i];
			}
		}
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;
			cout << "请输入第" << i + 1 << "个新职工编号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工姓名" << endl;
			cin >> name;
			cout << "请选择该职工岗位: " << endl;
			cout << "1.普通职工" << endl;
			cout << "2.普通经理" << endl;
			cout << "3.普通老板" << endl;
			cin >> dSelect;
			Worker *worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break; 			
			case 3:
				worker = new Boss(id, name, 3);
				break; 
			default:
				break;
			}
			newSpace[m_EmpNum + i] = worker;
		}
		delete[] m_EmpArray;
		m_EmpArray = newSpace;
		m_EmpNum = newSize;
		m_FileIsEmpty = false;
		cout << "成功添加" << addNum << "名新职工" << endl;
		Save();
	}
	else
	{
		cout << "输入数据有误" << endl;
	}
	system("pause");
	system("cls");
}
void WorkerManger::Save() const
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < m_EmpNum; i++)
	{
		ofs << m_EmpArray[i]->m_Id << " "
			<< m_EmpArray[i]->m_Name << " "
			<< m_EmpArray[i]->m_DptId << endl;
	}
	ofs.close();
}
int WorkerManger::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	return num;
}
void WorkerManger::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker* worker = NULL;
		if (did == 1)
		{
			worker = new Employee(id, name, did);
		}
		else if(did==2)
		{
			worker = new Manager(id, name, did);
		}
		else
		{
			worker = new Boss(id, name, did);
		}
		m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}
void WorkerManger::Show_Emp()
{
	if(m_FileIsEmpty)
	{
		cout << "文件不存在或者为空!" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			m_EmpArray[i]->ShowInfo();
		}
	}
	system("pause");
	system("cls");
}
int WorkerManger::IsExist(int id) const
{
	int index = -1;
	for (int i = 0; i < m_EmpNum; i++)
	{
		if (m_EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}
void WorkerManger::Del_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空!" << endl;
	}
	else
	{
		cout << "请输入想要删除职工编号:" << endl;
		int id = 0;
		cin >> id;
		int index = IsExist(id);
		if (index != -1)
		{
			for (int i = index; i < m_EmpNum; i++)
			{
				m_EmpArray[i] = m_EmpArray[i + 1];
			}
			m_EmpNum--;
			Save();
			cout << "删除成功!" << endl;
		}
		else
		{
			cout << "删除失败,未找到该职工" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkerManger::Mod_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空!" << endl;
	}
	else
	{
		cout << "请输入想要修改职工编号:" << endl;
		int id = 0;
		cin >> id;
		int ret = IsExist(id);
		if (ret != -1)
		{
			delete m_EmpArray[ret];
			int newid = 0;
			string newname = "";
			int newdSelect = 0;
			cout << "查到: " << id << "请输入第新职工编号" << endl;
			cin >> newid;
			cout << "请输入新姓名" << endl;
			cin >> newname;
			cout << "请选择该职工岗位: " << endl;
			cout << "1.普通职工" << endl;
			cout << "2.普通经理" << endl;
			cout << "3.普通老板" << endl;
			cin >> newdSelect;
			Worker* worker = NULL;
			switch (newdSelect)
			{
			case 1:
				worker = new Employee(newid, newname, newdSelect);
				break;
			case 2:
				worker = new Manager(newid, newname, newdSelect);
				break;
			case 3:
				worker = new Boss(newid, newname, newdSelect);
				break;
			default:
				break;
			}
			m_EmpArray[ret] = worker;
			Save();
			cout << "修改成功! " << endl;
		}
		else
		{
			cout << "修改失败,未找到该职工" << endl;
		}
		system("pause");
		system("cls");
	}
}
void WorkerManger::Find_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空!" << endl;
	}
	else
	{
		cout << "请输入查找方式: " << endl;
		cout << "1.按职工编号查找" << endl;
		cout << "2.按职工姓名查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "请输入查找的职工编号:" << endl;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "查找成功!该职工信息如下: " << endl;
				m_EmpArray[ret]->ShowInfo();
			}
			else
			{
				cout << "查找失败,查无此人" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "请输入查找的姓名: " << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功,职工编号为: " << m_EmpArray[i]->m_Id
						<< "号职工信息如下: " << endl;
					m_EmpArray[i]->ShowInfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "查找失败,查无此人!" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}
void WorkerManger::Sort_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空! " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式: " << endl;
		cout << "1.按职工号进行升序" << endl;
		cout << "2.按职工号进行降序" << endl;
		int select;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++)
		{
			int MinOrMax = i;
			for (int j = i + 1; j < m_EmpNum; j++)
			{
				if (select == 1)
				{
					if (m_EmpArray[MinOrMax]->m_Id > m_EmpArray[j]->m_Id)
					{
						MinOrMax = j;
					}
				}
				if (select == 2)
				{
					if (m_EmpArray[MinOrMax]->m_Id < m_EmpArray[j]->m_Id)
					{
						MinOrMax = j;
					}
				}
			}
			if (i != MinOrMax)
			{
				Worker* temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[MinOrMax];
				m_EmpArray[MinOrMax] = temp;
			}
		}
		cout << "排序成功!排序后的结果为: " << endl;
		Save();
		Show_Emp();

	}
}
void WorkerManger::Clean_File()
{
	cout << "确认清空? " << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (m_EmpArray != NULL)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				delete m_EmpArray[i];
				m_EmpArray[i] = NULL;
			}
			delete[] m_EmpArray;
			m_EmpArray = NULL;
			m_EmpNum = 0;
			m_FileIsEmpty = true;
		}
		cout << "清空成功!" << endl;
	}
	system("pause");
	system("cls");
}
WorkerManger::~WorkerManger()
{
	if (m_EmpArray != NULL)
	{
		delete[] m_EmpArray;
		m_EmpArray = NULL;
	}
}