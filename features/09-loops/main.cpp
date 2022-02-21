#include <iostream>

using namespace std;

void whileExercise() {
    // 局部变量声明
    int a = 10;

    // while 循环执行
    while (a < 20) {
        cout << "a 的值：" << a << endl;
        a++;
    }
}

void forExercise() {
    // for 循环执行
    for (int a = 10; a < 20; a = a + 1) {
        cout << "a 的值：" << a << endl;
    }
}

void doWhileExercise() {
    // 局部变量声明
    int a = 10;

    // do 循环执行
    do {
        cout << "a 的值：" << a << endl;
        a = a + 1;
    } while (a < 20);
}

void nestedExercise() {
    int i, j;
    for (i = 2; i < 100; i++) {
        for (j = 2; j <= (i / j); j++) {
            if (!(i % j)) {
                break; // 如果找到，则不是质数
            }
        }
        if (j > (i / j)) {
            cout << i << " 是质数\n";
        }
    }
}

void breakExercise() {
    // 局部变量声明
    int a = 10;
    // do 循环执行
    do {
        cout << "a 的值：" << a << endl;
        a = a + 1;
        if (a > 15) {
            // 终止循环
            break;
        }
    } while (a < 20);
}

void continueExercise() {
    // 局部变量声明
    int a = 10;

    // do 循环执行
    do {
        if (a == 15) {
            // 跳过迭代
            a = a + 1;
            continue;
        }
        cout << "a 的值：" << a << endl;
        a = a + 1;
    } while (a < 20);
}

int main() {
    whileExercise();
    forExercise();
    doWhileExercise();
    nestedExercise();
    breakExercise();
    continueExercise();
    return 0;
}