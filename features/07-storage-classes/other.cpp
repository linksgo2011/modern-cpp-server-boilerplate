#include <iostream>

extern int externCount;

void externExercise(){
    std::cout << "Count is " << externCount << std::endl;
}