#include<iostream>
using namespace std;
int main() {

	int a = 10;

	int * p;
	p = &a; //ָ��ָ������a�ĵ�ַ

	cout << *p << endl; //* ������
	cout << sizeof(p) << endl;
	cout << sizeof(char *) << endl;
	cout << sizeof(float *) << endl;
	cout << sizeof(double *) << endl;

	system("pause");

	return 0;
}
