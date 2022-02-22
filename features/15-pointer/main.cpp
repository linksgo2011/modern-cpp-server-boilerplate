#include <iostream>

using namespace std;

void getPointerExercise() {
    int var1;
    char var2[10];

    cout << "var1 变量的地址： ";
    cout << &var1 << endl;

    cout << "var2 变量的地址： ";
    cout << &var2 << endl;
}

void assignPointerExercise(){
    int  var = 20;   // 实际变量的声明
    int  *ip;        // 指针变量的声明

    ip = &var;       // 在指针变量中存储 var 的地址

    cout << "Value of var variable: ";
    cout << var << endl;

    // 输出在指针变量中存储的地址
    cout << "Address stored in ip variable: ";
    cout << ip << endl;
}

int main() {
    getPointerExercise();
    assignPointerExercise();

    return 0;
}