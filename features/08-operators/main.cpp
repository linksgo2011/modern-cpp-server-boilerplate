#include <iostream>

using namespace std;


void basicExercise() {
    int a = 21;
    int b = 10;
    int c;

    c = a + b;
    cout << "Line 1 - c 的值是 " << c << endl;
    c = a - b;
    cout << "Line 2 - c 的值是 " << c << endl;
    c = a * b;
    cout << "Line 3 - c 的值是 " << c << endl;
    c = a / b;
    cout << "Line 4 - c 的值是 " << c << endl;
    c = a % b;
    cout << "Line 5 - c 的值是 " << c << endl;

    int d = 10;   //  测试自增、自减
    c = d++;
    cout << "Line 6 - c 的值是 " << c << endl;

    d = 10;    // 重新赋值
    c = d--;
    cout << "Line 7 - c 的值是 " << c << endl;
}

void compareExercise() {
    int a = 21;
    int b = 10;
    int c;

    if (a == b) {
        cout << "Line 1 - a 等于 b" << endl;
    } else {
        cout << "Line 1 - a 不等于 b" << endl;
    }
    if (a < b) {
        cout << "Line 2 - a 小于 b" << endl;
    } else {
        cout << "Line 2 - a 不小于 b" << endl;
    }
    if (a > b) {
        cout << "Line 3 - a 大于 b" << endl;
    } else {
        cout << "Line 3 - a 不大于 b" << endl;
    }
    /* 改变 a 和 b 的值 */
    a = 5;
    b = 20;
    if (a <= b) {
        cout << "Line 4 - a 小于或等于 b" << endl;
    }
    if (b >= a) {
        cout << "Line 5 - b 大于或等于 a" << endl;
    }
}

void logicExercise(){
    int a = 5;
    int b = 20;
    int c ;

    if ( a && b )
    {
        cout << "Line 1 - 条件为真"<< endl ;
    }
    if ( a || b )
    {
        cout << "Line 2 - 条件为真"<< endl ;
    }
    /* 改变 a 和 b 的值 */
    a = 0;
    b = 10;
    if ( a && b )
    {
        cout << "Line 3 - 条件为真"<< endl ;
    }
    else
    {
        cout << "Line 4 - 条件不为真"<< endl ;
    }
    if ( !(a && b) )
    {
        cout << "Line 5 - 条件为真"<< endl ;
    }
}

void bitExercise(){
    unsigned int a = 60;      // 60 = 0011 1100
    unsigned int b = 13;      // 13 = 0000 1101
    int c = 0;

    c = a & b;             // 12 = 0000 1100
    cout << "Line 1 - c 的值是 " << c << endl ;

    c = a | b;             // 61 = 0011 1101
    cout << "Line 2 - c 的值是 " << c << endl ;

    c = a ^ b;             // 49 = 0011 0001
    cout << "Line 3 - c 的值是 " << c << endl ;

    c = ~a;                // -61 = 1100 0011
    cout << "Line 4 - c 的值是 " << c << endl ;

    c = a << 2;            // 240 = 1111 0000
    cout << "Line 5 - c 的值是 " << c << endl ;

    c = a >> 2;            // 15 = 0000 1111
    cout << "Line 6 - c 的值是 " << c << endl ;
}

void assignExercise(){
    int a = 21;
    int c ;

    c =  a;
    cout << "Line 1 - =  运算符实例，c 的值 = : " <<c<< endl ;

    c +=  a;
    cout << "Line 2 - += 运算符实例，c 的值 = : " <<c<< endl ;

    c -=  a;
    cout << "Line 3 - -= 运算符实例，c 的值 = : " <<c<< endl ;

    c *=  a;
    cout << "Line 4 - *= 运算符实例，c 的值 = : " <<c<< endl ;

    c /=  a;
    cout << "Line 5 - /= 运算符实例，c 的值 = : " <<c<< endl ;

    c  = 200;
    c %=  a;
    cout << "Line 6 - %= 运算符实例，c 的值 = : " <<c<< endl ;

    c <<=  2;
    cout << "Line 7 - <<= 运算符实例，c 的值 = : " <<c<< endl ;

    c >>=  2;
    cout << "Line 8 - >>= 运算符实例，c 的值 = : " <<c<< endl ;

    c &=  2;
    cout << "Line 9 - &= 运算符实例，c 的值 = : " <<c<< endl ;

    c ^=  2;
    cout << "Line 10 - ^= 运算符实例，c 的值 = : " <<c<< endl ;

    c |=  2;
    cout << "Line 11 - |= 运算符实例，c 的值 = : " <<c<< endl ;
}


void otherExercise(){
    // size of
    cout << "Size of char : " << sizeof(char) << endl;
    cout << "Size of int : " << sizeof(int) << endl;
    cout << "Size of short int : " << sizeof(short int) << endl;
    cout << "Size of long int : " << sizeof(long int) << endl;
    cout << "Size of float : " << sizeof(float) << endl;
    cout << "Size of double : " << sizeof(double) << endl;
    cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;

    //  Condition

    // 局部变量声明
    int x, y = 10;
    x = (y < 10) ? 30 : 40;
    cout << "value of x: " << x << endl;
}

void commaExercise() {
    int i, j;

    j = 10;
    i = (j++, j + 100, 999 + j);

    cout << i << endl;
}

void memberExercise() {
    struct Employee {
        char first_name[16];
        int age;
    } emp;

    emp.age = 10;
    (&emp)->age = 10;

    cout << emp.age << endl;
}

void castingExercise(){
    double a = 21.09399;
    float b = 10.20;
    int c ;

    c = (int) a;
    cout << "Line 1 - Value of (int)a is :" << c << endl ;

    c = (int) b;
    cout << "Line 2 - Value of (int)b is  :" << c << endl ;
}

void pointerExercise(){
    int  var;
    int  *ptr;
    int  val;

    var = 3000;

    // 获取 var 的地址
    ptr = &var;

    // 获取 ptr 的值
    val = *ptr;
    cout << "Value of var :" << var << endl;
    cout << "Value of ptr :" << ptr << endl;
    cout << "Value of val :" << val << endl;
}

int main() {
    basicExercise();
    compareExercise();
    logicExercise();
    bitExercise();
    assignExercise();
    otherExercise();
    commaExercise();
    memberExercise();
    castingExercise();
    pointerExercise();
    return 0;
}