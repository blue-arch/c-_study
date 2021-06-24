#include <sstream>
#include <iostream>
 
using namespace std;
 
int main()
{
    stringstream sstream;
    int first, second;
 
    // 插入字符串
    sstream << "456";
    // 转换为int类型
    sstream >> first;
    cout << first << endl;
 
    // 在进行多次类型转换前，必须先运行clear()
    sstream.clear();
 
    // 插入bool值
    sstream << true;
    // 转换为int类型
    sstream >> second;
    cout << second << endl;
 
    return 0;
}