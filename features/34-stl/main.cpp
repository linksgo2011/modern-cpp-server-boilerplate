#include <iostream>
#include <vector>

using namespace std;

void vectorExercise() {
    // 创建一个向量存储 int
    vector<int> vec;
    cout << "before  size = "  << vec.size() << endl;

    for(int i = 0; i < 5; i++){
        vec.push_back(i);
    }

    cout << "after size = " << vec.size() << endl;
}

void iteratorExercise(){
    vector<int> vec;
    for(int i = 0; i < 5; i++){
        vec.push_back(i);
    }

    vector<int>::iterator v = vec.begin();
    while( v != vec.end()) {
        cout << "value of v = " << *v << endl;
        v++;
    }
}

int main() {
    vectorExercise();
    iteratorExercise();
}