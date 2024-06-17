#pragma once
#include "common.h"
using namespace std;
WorkerManger::WorkerManger()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
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
		cout << "�ļ�Ϊ��!" << endl;
		m_EmpNum = 0;
		m_FileIsEmpty = true;
		m_EmpArray = NULL;
		ifs.close();
		return;
	}
	int num = get_EmpNum();
	cout << "ְ������Ϊ: " << num << endl;
	m_EmpNum = num;
	m_EmpArray = new Worker * [m_EmpNum];
	init_Emp();
	for (int i = 0; i < m_EmpNum; i++)
	{
		cout << "ְ�����: " << m_EmpArray[i]->m_Id<<" "
			<< "ְ������: " << m_EmpArray[i]->m_Name<<" "
			<< "���ű��: " << m_EmpArray[i]->m_DptId<< endl;
	}
	ifs.close();
}
void WorkerManger::Show_Menu()
{
	cout << "ְ������ϵͳ" << endl;
	cout << "0.�˳�����ϵͳ" << endl;
	cout << "1.����ְ����Ϣ" << endl;
	cout << "2.��ʾְ����Ϣ" << endl;
	cout << "3.ɾ����ְְ��" << endl;
	cout << "4.�޸�ְ����Ϣ" << endl;
	cout << "5.����ְ����Ϣ" << endl;
	cout << "6.���ձ������" << endl;
	cout << "7.��������ĵ�" << endl;
}
void WorkerManger::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	//system("pause");
	exit(0);
}
void WorkerManger::Add_Emp()
{
	cout << "���������ְ������: " << endl;
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
			cout << "�������" << i + 1 << "����ְ�����" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ������" << endl;
			cin >> name;
			cout << "��ѡ���ְ����λ: " << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.��ͨ����" << endl;
			cout << "3.��ͨ�ϰ�" << endl;
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
		cout << "�ɹ����" << addNum << "����ְ��" << endl;
		Save();
	}
	else
	{
		cout << "������������" << endl;
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
		cout << "�ļ������ڻ���Ϊ��!" << endl;
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
		cout << "�ļ������ڻ��¼Ϊ��!" << endl;
	}
	else
	{
		cout << "��������Ҫɾ��ְ�����:" << endl;
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
			cout << "ɾ���ɹ�!" << endl;
		}
		else
		{
			cout << "ɾ��ʧ��,δ�ҵ���ְ��" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkerManger::Mod_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��!" << endl;
	}
	else
	{
		cout << "��������Ҫ�޸�ְ�����:" << endl;
		int id = 0;
		cin >> id;
		int ret = IsExist(id);
		if (ret != -1)
		{
			delete m_EmpArray[ret];
			int newid = 0;
			string newname = "";
			int newdSelect = 0;
			cout << "�鵽: " << id << "���������ְ�����" << endl;
			cin >> newid;
			cout << "������������" << endl;
			cin >> newname;
			cout << "��ѡ���ְ����λ: " << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.��ͨ����" << endl;
			cout << "3.��ͨ�ϰ�" << endl;
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
			cout << "�޸ĳɹ�! " << endl;
		}
		else
		{
			cout << "�޸�ʧ��,δ�ҵ���ְ��" << endl;
		}
		system("pause");
		system("cls");
	}
}
void WorkerManger::Find_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��!" << endl;
	}
	else
	{
		cout << "��������ҷ�ʽ: " << endl;
		cout << "1.��ְ����Ų���" << endl;
		cout << "2.��ְ����������" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "��������ҵ�ְ�����:" << endl;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�!��ְ����Ϣ����: " << endl;
				m_EmpArray[ret]->ShowInfo();
			}
			else
			{
				cout << "����ʧ��,���޴���" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "��������ҵ�����: " << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ�,ְ�����Ϊ: " << m_EmpArray[i]->m_Id
						<< "��ְ����Ϣ����: " << endl;
					m_EmpArray[i]->ShowInfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "����ʧ��,���޴���!" << endl;
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
		cout << "�ļ������ڻ��߼�¼Ϊ��! " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ: " << endl;
		cout << "1.��ְ���Ž�������" << endl;
		cout << "2.��ְ���Ž��н���" << endl;
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
		cout << "����ɹ�!�����Ľ��Ϊ: " << endl;
		Save();
		Show_Emp();

	}
}
void WorkerManger::Clean_File()
{
	cout << "ȷ�����? " << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;
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
		cout << "��ճɹ�!" << endl;
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