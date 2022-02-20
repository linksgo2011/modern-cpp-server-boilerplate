#include <iostream>
#include "other.cpp"

using namespace std;

void autoExercise() {
    auto f = 3.14;      //double
    cout << f << endl;
    auto s("hello");  //const char*
    cout << s << endl;
    auto z = new auto(9); // int*
    cout << z << endl;
}

void registerExercise() {
    register int miles;
    miles = 10;
    cout << miles << endl;

}

static int count = 10; /* 全局变量 */

void staticExercise() {
    static int i = 5; // 局部静态变量
    i++;
    std::cout << "变量 i 为 " << i;
    std::cout << " , 变量 count 为 " << std::endl;
}

void threadLocalExercise(){
    // 使用 thread_local 说明符声明的变量仅可在它在其上创建的线程上访问。 变量在创建线程时创建，并在销毁线程时销毁。 每个线程都有其自己的变量副本。
    thread_local int count = 10;
    std::cout << " , 变量 count 为 " << std::endl;
}

//extern 修饰符通常用于当有两个或多个文件共享相同的全局变量或函数的时候，如下所示：
extern int externCount = 10;

int main() {
    autoExercise();
    registerExercise();
    staticExercise();
    staticExercise();

    externCount--;
    externExercise();
    threadLocalExercise();
    threadLocalExercise();
}