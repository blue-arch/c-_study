#include <string>
#include <sstream>
#include <iostream>
#include <stdio.h>
 
using namespace std;
 
int main()
{
    stringstream sstream;
    string strResult;
    int nValue = 1000;
 
    // ��int���͵�ֵ������������
    sstream << nValue;
    // ��sstream�г�ȡǰ������int���͵�ֵ������string����
    sstream >> strResult;
 
    cout << "[cout]strResult is: " << strResult << endl;
    printf("[printf]strResult is: %s\n", strResult.c_str());
 
    return 0;
}