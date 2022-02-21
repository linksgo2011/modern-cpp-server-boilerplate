#include <iostream>

using namespace std;

void ifExercise() {
    // 局部变量声明
    int a = 10;

    // 使用 if 语句检查布尔条件
    if (a < 20) {
        // 如果条件为真，则输出下面的语句
        cout << "a 小于 20" << endl;
    }
    cout << "a 的值是 " << a << endl;
}

void switchExercise(){
    // 局部变量声明
    char grade = 'D';

    switch(grade)
    {
        case 'A' :
            cout << "很棒！" << endl;
            break;
        case 'B' :
        case 'C' :
            cout << "做得好" << endl;
            break;
        case 'D' :
            cout << "您通过了" << endl;
            break;
        case 'F' :
            cout << "最好再试一下" << endl;
            break;
        default :
            cout << "无效的成绩" << endl;
    }
    cout << "您的成绩是 " << grade << endl;
}

int main() {
    ifExercise();
    switchExercise();
    return 0;
}