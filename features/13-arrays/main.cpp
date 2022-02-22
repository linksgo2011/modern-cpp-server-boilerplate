#include <iostream>

using namespace std;

#include <iomanip>

using std::setw;

void basicExercise() {
    int n[10]; // n 是一个包含 10 个整数的数组

    // 初始化数组元素
    for (int i = 0; i < 10; i++) {
        n[i] = i + 100; // 设置元素 i 为 i + 100
    }
    cout << "Element" << setw(13) << "Value" << endl;

    // 输出数组中每个元素的值
    for (int j = 0; j < 10; j++) {
        cout << setw(7) << j << setw(13) << n[j] << endl;
    }
}

void twoDimensional() {
    // 一个带有 5 行 2 列的数组
    int a[5][2] = {{0, 0},
                   {1, 2},
                   {2, 4},
                   {3, 6},
                   {4, 8}};

    // 输出数组中每个元素的值
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "a[" << i << "][" << j << "]: ";
            cout << a[i][j] << endl;
        }
    }
}

int main() {
    basicExercise();
    twoDimensional();

    return 0;
}