#include <iostream>

using namespace std;

namespace my_space {
    void helloInSpace() {
        cout << "Hello in space!" << endl;
    }
}

namespace my_space {
    void helloInSpace2() {
        cout << "Hello in space!" << endl;
    }
}

int main() {
    my_space::helloInSpace();
    my_space::helloInSpace2();
    return 0;
}