#include <iostream>

using namespace std;

class printData {
public:
    void print(int i) {
        cout << "整数为: " << i << endl;
    }

    void print(double f) {
        cout << "浮点数为: " << f << endl;
    }

    void print(char c[]) {
        cout << "字符串为: " << c << endl;
    }
};

void basicExercise() {
    printData pd;

    // 输出整数
    pd.print(5);
    // 输出浮点数
    pd.print(500.263);
    // 输出字符串
    char c[] = "Hello C++";
    pd.print(c);
}


class Box {
public:

    double getVolume(void) {
        return length * breadth * height;
    }

    void setLength(double len) {
        length = len;
    }

    void setBreadth(double bre) {
        breadth = bre;
    }

    void setHeight(double hei) {
        height = hei;
    }

    // 重载 + 运算符，用于把两个 Box 对象相加
    Box operator+(const Box &b) {
        Box box;
        box.length = this->length + b.length;
        box.breadth = this->breadth + b.breadth;
        box.height = this->height + b.height;
        return box;
    }

private:
    double length;      // 长度
    double breadth;     // 宽度
    double height;      // 高度
};


void operatorOverloadingExercise() {
    Box box1;
    Box box2;
    Box box3;
    box1.setLength(6.0);
    box1.setBreadth(7.0);
    box1.setHeight(5.0);

    // Box2 详述
    box2.setLength(12.0);
    box2.setBreadth(13.0);
    box2.setHeight(10.0);

    box3 = box1 + box2;

    cout << box3.getVolume() << endl;
}

int main(void) {
    basicExercise();
    operatorOverloadingExercise();

    return 0;
}