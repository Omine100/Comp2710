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
    
    read_file(firstFile, firstNumbers);
}

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