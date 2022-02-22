#include <iostream>

using namespace std;

double division(int a, int b) {
    if (b == 0) {
        throw "Division by zero condition!";
    }
    return (a / b);
}

void basicExercise() {
    int x = 50;
    int y = 0;
    double z = 0;

    try {
        z = division(x, y);
        cout << z << endl;
    } catch (const char *msg) {
        cerr << msg << endl;
    }
}

struct MyException : public exception {
    const char *what() const throw() {
        return "C++ Exception";
    }

};

void definedExceptionExercise() {
    try {
        throw MyException();
    }
    catch (MyException &e) {
        std::cout << "MyException caught" << std::endl;
        std::cerr << e.what() << std::endl;
    }
    catch (std::exception &e) {
        //其他的错误
    }
}

int main() {
    basicExercise();
    definedExceptionExercise();
    return 0;
}