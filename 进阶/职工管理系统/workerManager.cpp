#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
//包含头文件

//头文件中只负责声明，不负责实现
//源文件中负责实现
WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//1.文件不存在情况
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl; //测试输出
		this->m_EmpNum = 0;  //初始化人数
		this->m_FileIsEmpty = true; //初始化文件为空标志
		this->m_EmpArray = NULL; //初始化数组
		ifs.close(); //关闭文件
		return;
	}

	//2.文件存在，并且没有记录
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空!" << endl;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}

	//3.文件存在且保存职工数据
	int num =  this->get_EmpNum();
	cout << "职工个数为：" << num << endl;  //测试代码
	this->m_EmpNum = num;  //更新成员属性 

	//根据职工数创建数组
	this->m_EmpArray = new Worker *[this->m_EmpNum];
	//初始化职工
	init_Emp();

	//测试代码
	for (int i = 0; i < m_EmpNum; i++)
	{
		cout << "职工号： " << this->m_EmpArray[i]->m_Id
			<< " 职工姓名： " << this->m_EmpArray[i]->m_Name
			<< " 部门编号： " << this->m_EmpArray[i]->m_DeptId << endl;
	}

    
}
WorkerManager::~WorkerManager()
{
	cout << "析构函数的实现" << endl;
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

//保存文件功能实现
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//用输出的方式打开文件，既写文件

	//将每个人数据写入到文件中
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	//关闭文件
	ofs.close();
}

void WorkerManager::Show_Menu()
{
	cout << "*********************************************************" << endl;
	cout << "******************欢迎使用职工管理系统*******************" << endl;
	cout << "******************0.退出管理程序*******************" << endl;
	cout << "******************1.增加职工信息*******************" << endl;
	cout << "******************2.显示职工信息*******************" << endl;
	cout << "******************3.删除职工信息*******************" << endl;
	cout << "******************4.修改职工信息*******************" << endl;
	cout << "******************5.查找职工信息*******************" << endl;
	cout << "******************6.按照编号排序*******************" << endl;
	cout << "******************7.清空所有文档*******************" << endl;
	cout << "*********************************************************" << endl;
}
void WorkerManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//添加职工
void WorkerManager::Add_Emp()
{
	cout << "请输入增加职工数量：" << endl;
	int addNum = 0;//保存用户的输入数量
	cin >> addNum;

	if (addNum > 0)
	{
		//计算新空间大小
		int newsize = this->m_EmpNum + addNum;//新空间人数=原来记录人数+新增人数
		//开辟新空间
		Worker** newSpace = new Worker * [newsize];
		//将原来空间下的数据，拷贝到新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i<this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;//职工编号
			string name;//职工姓名
			int dSelect;//部门选择
			cout << "请输入第" << i + 1 << "个新职工的编号：" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工的姓名：" << endl;
			cin >> name;
			cout << "请选择该职工岗位"  << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >>dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
			case 2:
				worker = new Manager(id, name, 2);
			case 3:
				worker = new Boss(id, name, 3);
			default:
				break;
			}

			//将创建职工职责，保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}
		//释放原有空间
		delete[] this->m_EmpArray;
		//更改新空间的指向
		this->m_EmpArray = newSpace;
		//更新新的职工人数
		this->m_EmpNum = newsize;

        //提示添加成功
		//调用save函数保存到文件中
		this->save();
		//更新职工不为空标志
		this->m_FileIsEmpty = false;
		//提示添加成功
		cout << "成功添加" << addNum << "名新职工" << endl;
	}
	else
	{
		cout << "输入数据有误" << endl;
	}
	//按任意键，清屏回到上级目录
	system("pause");
	system("clear");
}

int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
        //记录人数
		num++;
	}
	ifs.close();

	return num;
}

void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker * worker = NULL;
		//根据不同的部门Id创建不同对象
		if (dId == 1)  // 1普通员工
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2) //2经理
		{
			worker = new Manager(id, name, dId);
		}
		else //总裁
		{
			worker = new Boss(id, name, dId);
		}
		//存放在数组中
		this->m_EmpArray[index] = worker;
		index++;
	}
}