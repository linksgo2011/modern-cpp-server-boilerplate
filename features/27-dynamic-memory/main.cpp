#include <iostream>

using namespace std;

void basicExercise() {
    double *pvalue = NULL; // 初始化为 null 的指针
    pvalue = new double;   // 为变量请求内存

    *pvalue = 29494.99;     // 在分配的地址存储值
    cout << "Value of pvalue : " << *pvalue << endl;

    delete pvalue;         // 释放内存
}

void arrayMemoExercise() {
    int **array;
    int m = 10;
    int n = 10;
    array = new int *[m];
    for (int i = 0; i < m; i++) {
        array[i] = new int[n];
    }
    for (int i = 0; i < m; i++) {
        delete[] array[i];
    }
    delete[] array;
}

class Box {
public:
    Box() {
        cout << "调用构造函数！" << endl;
    }

    ~Box() {
        cout << "调用析构函数！" << endl;
    }
};

void objectMemoExercise() {
    Box *myBoxArray = new Box[4];

    delete[] myBoxArray; // 删除数组
}

int main() {
    basicExercise();
    arrayMemoExercise();
    objectMemoExercise();

    return 0;
}