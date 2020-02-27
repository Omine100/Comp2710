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
#include <vector>
using namespace std;

//FUNCTION DECLARATION: check_file DECLARATION
bool check_file(string);

//FUNCTION DECLARATION: read_file DECLARATION
vector<int> read_file(string, vector<int>);

//FUNCTION DECLARATION: sort_file DECLARATION

//FUNCTION DECLARATION: write_file DECLARATION

//METHOD: START OF THE PROJECT 
int main() {
    //VARIABLE DECLARATION
    string firstFile;
    string secondFile;
    vector<int> firstNumbers;
    vector<int> secondNumbers;
    
    cout << "*** Welcome to Matthew's sorting program ***\n"
         << "Enter the first input file name: ";
    getline(cin, firstFile);
    cout << "This is the fileName: " << firstFile;
    
    if (check_file(firstFile)) {
        cout << "\nFile exists.";
        read_file(firstFile, firstNumbers);
    } else {
        cout << "\nFile does not exist.";
    }
}

//METHOD: CHECKS A GIVEN FILE TO SEE IF IT EXISTS
bool check_file(string fileName) {
    std::ifstream exists(fileName);
    
    return !exists ? false : true;
}

//METHOD: READS A GIVEN FILE AND RETURNS AN UNSORTED VECTOR
vector<int> read_file(string fileName, vector<int> numbers) {
    int currentNumber;

    ifstream in(fileName, ios::in);
    while (in >> currentNumber) {
        numbers.push_back(currentNumber);
    }
    in.close();

    cout << "Numbers:\n";
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << "\n";
    }

    return numbers;
}