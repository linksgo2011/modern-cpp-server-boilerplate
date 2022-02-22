#include <iostream>
#include <pthread.h>

using namespace std;

// 线程的方法必须按照这样来
void *say_hello(void *args) {
    // 数据类型转换一下，完成传参
    int *number = (int *) args;
    cout << "Hello from thread！" << *number << endl;
    return 0;
}

int parameter = 10;

void basicThreadExercise() {
    pthread_t handler;
    pthread_create(&handler, NULL, say_hello, &parameter);
}

#include<thread>

void classThreadExercise() {
    thread t1 = thread([](int x) {
        for (int i = 0; i < x; i++)
            cout << "线程使用 lambda 表达式作为可调用参数\n";
    }, 1);
}

int main() {
    basicThreadExercise();
    classThreadExercise();

    cout << "Hello from main！" << endl;

    //等各个线程退出后，进程才结束，否则进程强制结束了，线程可能还没反应过来；
    pthread_exit(NULL);
}