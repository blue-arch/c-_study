#pragma once
# include<iostream>
using namespace std;
#include "worker.h"
#include <fstream>
#define FILENAME "empFile.txt"

//ͷ�ļ���ֻ������������ʵ��
class WorkerManager
{
public:
	WorkerManager();
	~WorkerManager();

	//չʾ�˵�
	void Show_Menu();
	//�˳�����
	void exitSystem();
    void save();

    //��־�ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;
	//ͳ������
	int get_EmpNum();

	//��ʼ��Ա��
	void init_Emp();

	///���ְ��
	//��ӳ�Ա����
	int m_EmpNum;//��¼�ļ�����������
	Worker ** m_EmpArray;//Ա�������ָ��
	//��ӳ�Ա����
	void Add_Emp();

};

