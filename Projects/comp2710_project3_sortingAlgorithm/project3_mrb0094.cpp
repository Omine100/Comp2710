/*
 * FILE NAME: project3_mrb0094.cpp
 * AUTHOR: Matthew Browning
 * AU ID: mrb0094
 * ABOUT: This program simulates a duel between three people and calculates odds.
 * COMPILE: Compile project3_mrb0094.cpp and run.
 * HELP: Basic information provided by Professor Li and talk through with Ezra Hill from class.
*/

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

//FUNCTION DECLARATION: check_file DECLARATION
bool check_file(string);

//FUNCTION DECLARATION: read_file DECLARATION
int read_file(int inputArray[], ifstream& inStream);

//METHOD: START OF THE PROJECT 
int main() {
    //VARIABLE DECLARATION
    string firstFile;
    string secondFile;
    int firstArray[100];
    int firstArray_size;
    int secondArray[100];
    int secondArray_size;

    cout << "*** Welcome to Matthew's sorting program ***\n"
         << "Enter the first input file name: ";
    getline(cin, firstFile);
    cout << "This is the fileName: " << firstFile;
}

int read_file(string fileName, int array[]) {
    string line;
    ifstream file (fileName);

    if (file.is_open()) {
        while (getline(file, line)) {
            array[1] == line.toInt();
        }
    }
}