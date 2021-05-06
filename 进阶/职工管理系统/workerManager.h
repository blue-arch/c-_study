#pragma once
# include<iostream>
using namespace std;
#include "worker.h"
#include <fstream>
#define FILENAME "empFile.txt"

//头文件中只做声明，不做实现
class WorkerManager
{
public:
	WorkerManager();
	~WorkerManager();

	//展示菜单
	void Show_Menu();
	//退出功能
	void exitSystem();
    void save();

    //标志文件是否为空
	bool m_FileIsEmpty;
	//统计人数
	int get_EmpNum();

	//初始化员工
	void init_Emp();

	///添加职工
	//添加成员属性
	int m_EmpNum;//记录文件中人数个数
	Worker ** m_EmpArray;//员工数组的指针
	//添加成员函数
	void Add_Emp();

};

