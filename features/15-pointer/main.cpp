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
    int var1;

}

int main() {
    getPointerExercise();
    assignPointerExercise();

    return 0;
}