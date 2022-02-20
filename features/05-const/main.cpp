//
// Created by Ning Lin  on 2022/2/20.
//
#include <iostream>

using namespace std;

void intConstExercise() {
    int a = 85;         // 十进制
    cout << a << endl;
    int b = 0213;       // 八进制
    cout << b << endl;
    int c = 0x4b;       // 十六进制
    cout << c << endl;
    int d = 30;         // 整数
    cout << d << endl;
    int e = 30u;        // 无符号整数
    cout << e << endl;
    int f = 30l;        // 长整数
    cout << f << endl;
    int g = 30ul;       // 无符号长整数
    cout << g << endl;
}

void floatConstExercise() {
    float a = 3.14159;       // 合法的
    cout << a << endl;
    float b = 314159E-5L;    // 合法的
    cout << b << endl;
}

void stringConstExercise() {
    string greeting = "hello, runoob";
    cout << greeting;
    cout << "\n";     // 换行符
    string greeting2 = "hello, \
                       runoob";
    cout << greeting2 << endl;
}

#define NAME 10;

void defineExercise() {
    cout << NAME;
    int area;
    const int WIDTH = 10;
    const int LENGTH = 10;
    area = LENGTH * WIDTH;
    cout << area << endl;
}

int main() {
    intConstExercise();
    floatConstExercise();
    stringConstExercise();
    defineExercise();
    defineExercise();
    return 0;
}