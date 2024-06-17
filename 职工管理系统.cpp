#pragma once
#include "common.h"
using namespace std;
static void test00()
{
	Worker *worker = NULL;
	worker = new Employee(1, "张三", 1);
	worker->ShowInfo();
	delete worker;
}
static void test01()
{
	Worker *worker = NULL;
	worker = new Manager(2, "李四", 2);
	worker->ShowInfo();
	delete worker;

}
static void test02()
{
	Worker *worker = NULL;
	worker = new Boss(3, "王五", 3);
	worker->ShowInfo();
	delete worker;

}

int main()
{
	//test00();
	//test01();
	//test02();
	WorkerManger wm;
	int choice = 0;
	while (true)
	{
		wm.Show_Menu();
		cout << "请输入您的选择: " << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			wm.ExitSystem();
			break;
		case 1:
			wm.Add_Emp();
			break;
		case 2:
			wm.Show_Emp();
			break;
		case 3:
			wm.Del_Emp();
			break;
		case 4:
			wm.Mod_Emp();
			break;
		case 5:
			wm.Find_Emp();
			break;
		case 6:
			wm.Sort_Emp();
			break;
		case 7:
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}
	return 0;
}