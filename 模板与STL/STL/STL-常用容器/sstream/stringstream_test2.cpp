#include <string>
#include <sstream>
#include <iostream>
 
using namespace std;
 
int main()
{
    stringstream sstream;
 
    // ������ַ������� sstream ��
    sstream << "first" << " " << "string,";
    sstream << " second string";
    cout << "strResult is: " << sstream.str() << endl;
 
    // ��� sstream
    sstream.str("");
    sstream << "third string";
    cout << "After clear, strResult is: " << sstream.str() << endl;
 
    return 0;
}