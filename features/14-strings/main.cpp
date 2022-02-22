#include <iostream>

using namespace std;

void arrayStringExercise() {
    char site[7] = {'R', 'U', 'N', 'O', 'O', 'B', '\0'};

    cout << "菜鸟教程: ";
    cout << site << endl;
}

void strMethodsExercise() {
    char str1[13];
    char str2[10] = "google";
    strcpy(str1, str2);

    cout << "strcpy(str1, str2) " << str1 << endl;

    cout << "strcat(str1, str2) " << strcat(str1, str2) << endl;

    cout << "strlen(str1) " << strlen(str1) << endl;

    cout << "strcmp(str1,str2) " << strcmp(str1, str2) << endl;

    cout << "strchr(strchr,str2) " << strchr(str1, 'g') << endl;

    cout << "strstr(str1,str2) " << strstr(str1, str2) << endl;
}

void strClassExercise() {
    string str1 = "google";
    string str2;
    str2 = str1;

    cout << "str1 copy to str2: " << str2 << endl;
    cout << "length : " << str1.size() << endl;
}

int main() {
    arrayStringExercise();
    strMethodsExercise();
    strClassExercise();
    return 0;
}