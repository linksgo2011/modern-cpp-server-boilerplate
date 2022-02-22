#include <iostream>

using namespace std;

void basicExercise() {
    string name;
    cin >> name;

    cout << "Value of str is : " << name << endl;
    clog << "Value from log : " << name << endl;

    if (name == "zhangsan") {
        cerr << "incorrect username";
    }
}

int main() {
    basicExercise();
}