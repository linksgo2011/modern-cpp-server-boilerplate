#include <iostream>

using namespace std;

#define PI 3.14159

void defineExercise() {
    cout << "Value of PI :" << PI << endl;
}

#define MIN(a, b) (a<b ? a : b)

void parameterMicroExercise() {
    int i, j;
    i = 100;
    j = 30;
    cout << "较小的值为：" << MIN(i, j) << endl;
}


#define DEBUG true;

void conditionExercise() {
    int x = 10;
#ifdef DEBUG
    cerr << "Variable x = " << x << endl;
#endif
}

#define concat(a, b) a ## b

void contactExercise() {
    int xy = 100;

    // concat x y token
    cout << concat(x, y);
}

void preDefinedTokens() {
    cout << "Value of __LINE__ : " << __LINE__ << endl;
    cout << "Value of __FILE__ : " << __FILE__ << endl;
    cout << "Value of __DATE__ : " << __DATE__ << endl;
    cout << "Value of __TIME__ : " << __TIME__ << endl;
}

int main() {
    defineExercise();
    parameterMicroExercise();
    conditionExercise();
    contactExercise();
    preDefinedTokens();

    return 0;
}