#include <iostream>
using namespace std;


void partScopeExercise(){
    // 局部变量声明
    int a, b;
    int c;

    // 实际初始化
    a = 10;
    b = 20;
    c = a + b;

    cout << c;
}


// 全局变量声明
int g;

int globalExercise()
{
    // 局部变量声明
    int a, b;

    // 实际初始化
    a = 10;
    b = 20;
    g = a + b;

    cout << g;

    return 0;
}

int main ()
{
    partScopeExercise();
    globalExercise();
    return 0;
}