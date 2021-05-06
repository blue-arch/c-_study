#include<iostream>
using namespace std;
#include "workerManager.h"
#include "workerManager.cpp"
// #include "worker.cpp"
#include "worker.h"
#include "employee.cpp"
#include "employee.h"
#include "manager.h"
#include "manager.cpp"
#include "boss.cpp"
#include "boss.h"


void test()
{
	Worker * worker = NULL;
	worker = new Employee(1, "����", 1);
	worker->showInfo();
	delete worker;
	
	worker = new Manager(2, "����", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "����", 3);
	worker->showInfo();
	delete worker;
}


int main() {

    // test();
	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		//չʾ�˵�
		wm.Show_Menu();
		cout << "����������ѡ��:" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0: //�˳�ϵͳ
            wm.exitSystem();
			break;
		case 1: //���ְ��
            wm.Add_Emp();
			break;
		case 2: //��ʾְ��
			break;
		case 3: //ɾ��ְ��
			break;
		case 4: //�޸�ְ��
			break;
		case 5: //����ְ��
			break;
		case 6: //����ְ��
			break;
		case 7: //����ļ�
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}