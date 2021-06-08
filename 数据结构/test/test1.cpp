#include<iostream>
using namespace std;
#include<vector>

void test( vector<int> &a) {
    a[4] = 9;
}

void print(vector<int> &a) {
    for(int i = 0; i < a.size(); ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

}

int main() {
    vector<int> a(10, 1);
    test(a);
    print(a);
    system("pause");
    return 0;
}