#include<iostream>
#include <list>
#include <queue>
using namespace std;

#include <algorithm>
#include <vector>

void test01()
{
	vector<int>v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//���ֲ���
	bool ret = binary_search(v.begin(), v.end(),2);
	if (ret)
	{
		cout << "�ҵ���" << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}
}

int main() {

	test01();

	system("pause");

	return 0;
}
