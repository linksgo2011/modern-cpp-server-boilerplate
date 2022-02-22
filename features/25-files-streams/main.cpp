#include <fstream>
#include <iostream>

using namespace std;

void writeDataTofileExercise() {
    char data[100];
    ofstream outfile;
    outfile.open("test.txt");

    cout << "write to the file" << endl;
    cout << "Enter your name: ";
    cin.getline(data, 100);

    outfile << data << endl;

    cout << "Enter your age: ";
    cin >> data;
    cin.ignore();

    outfile << data << endl;

    outfile.close();
}

void readDataFromfileExercise() {
    char buffer[100];
    ifstream infile;
    infile.open("test.txt");

    infile >> buffer;
    cout << buffer << endl;
}

int main() {
    writeDataTofileExercise();
    readDataFromfileExercise();
    return 0;
}