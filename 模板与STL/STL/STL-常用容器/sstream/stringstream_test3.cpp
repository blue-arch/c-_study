#include <sstream>
#include <iostream>
 
using namespace std;
 
int main()
{
    stringstream sstream;
    int first, second;
 
    // �����ַ���
    sstream << "456";
    // ת��Ϊint����
    sstream >> first;
    cout << first << endl;
 
    // �ڽ��ж������ת��ǰ������������clear()
    sstream.clear();
 
    // ����boolֵ
    sstream << true;
    // ת��Ϊint����
    sstream >> second;
    cout << second << endl;
 
    return 0;
}