#include <iostream>

using namespace std;

class Box {
public:
    static string unit;
    double length;
    double breadth;
    double height;

    double getSize(void);

    // 构造函数
    Box();

    // 析构函数
    ~Box();

    Box(double length, double breadth, double height);

    void static setUnit(string unit) {
        Box::unit = unit;
    }

private:
    friend void friendClassExercise();
};

Box::Box() {
    cout << "Object is being created without arguments" << endl;
}


string Box::unit = "mm";

Box::Box(double length, double breadth, double height) {
    this->length = length;
    this->breadth = breadth;
    this->height = height;
    cout << "Object is being created" << endl;
}

Box::~Box() {
    cout << "Object is closing" << endl;
}

double Box::getSize() {
    return length * breadth * height;
}

void basicClassExercise() {
    Box box;
    box.height = 10;
    box.breadth = 20;
    box.height = 30;
    cout << box.getSize() << endl;
}

void constructorClassExercise() {
    Box box = Box(10, 20, 30);
    cout << box.getSize() << endl;
}

void friendClassExercise(Box box) {
    cout << "output from friend method" << endl;
    cout << box.height << endl;
}

void pointerClassExercise() {
    Box box = Box(10, 20, 30);
    cout << "access by pointer" << endl;
    cout << (&box)->getSize() << endl;
}

void staticMembersExercise() {
    Box::setUnit("cm");
    cout << "access by static member" << endl;
    cout << Box::unit << endl;
}

int main() {
    basicClassExercise();
    constructorClassExercise();
    Box box = Box(10, 20, 30);
    friendClassExercise(box);
    pointerClassExercise();
    staticMembersExercise();
    return 0;
}