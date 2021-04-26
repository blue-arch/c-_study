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

	//利用delete释放堆区数据
	delete p;

	//cout << *p << endl; //报错，释放的空间不可访问

	system("pause");

	return 0;
}
//堆区开辟数组
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
// 	//释放数组 delete 后加 []
// 	delete[] arr;

// 	system("pause");

// 	return 0;
// }

