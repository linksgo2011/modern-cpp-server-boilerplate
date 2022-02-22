#include <iostream>

using namespace std;

// 函数声明
int max(int num1, int num2);

// 函数返回两个数中较大的那个数
int max(int num1, int num2 = 20) {
    // 局部变量声明
    int result;

    if (num1 > num2)
        result = num1;
    else
        result = num2;

    return result;
}

int main() {
    int ret;
    // 普通练习
    ret = max(100);
    cout << "Max value is : " << ret << endl;


    /** 闭包（Closure） 规则
[]      // 沒有定义任何变量。使用未定义变量会引发错误。
[x, &y] // x以传值方式传入（默认），y以引用方式传入。
[&]     // 任何被使用到的外部变量都隐式地以引用方式加以引用。
[=]     // 任何被使用到的外部变量都隐式地以传值方式加以引用。
[&, x]  // x显式地以传值方式加以引用。其余变量以引用方式加以引用。
[=, &z] // z显式地以引用方式加以引用。其余变量以传值方式加以引用。
     */
    auto method = [](int x, int y) -> int {
        int z = x + y;
        return z + x;
    };
    auto result = method(10, 20);
    cout << result << endl;

    return 0;
}