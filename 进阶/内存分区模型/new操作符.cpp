#include<iostream>
using namespace std;
int* func()
{
	int* a = new int(10);
	return a;
}

int main() {

	int *p = func();

	cout << *p << endl;
	cout << *p << endl;

	//����delete�ͷŶ�������
	delete p;

	//cout << *p << endl; //�����ͷŵĿռ䲻�ɷ���

	system("pause");

	return 0;
}
//������������
// int main() {

// 	int* arr = new int[10];

// 	for (int i = 0; i < 10; i++)
// 	{
// 		arr[i] = i + 100;
// 	}

// 	for (int i = 0; i < 10; i++)
// 	{
// 		cout << arr[i] << endl;
// 	}
// 	//�ͷ����� delete ��� []
// 	delete[] arr;

// 	system("pause");

// 	return 0;
// }

