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

//FUNCTION DECLARATION: read_vector DECLARATION
void read_vector(vector<int>);

//FUNCTION DECLARATION: sort_file DECLARATION
vector<int> sort_vector(vector<int>);

//FUNCTION DECLARATION: write_file DECLARATION
void write_file(string, vector<int>);

//METHOD: START OF THE PROJECT
int main() {
    //VARIABLE DECLARATION
    string firstFile;
    string secondFile;
    string sortedFile;
    vector<int> firstNumbers;
    vector<int> secondNumbers;
    vector<int> sortedNumbers;
    
    //USER: WELCOME
    cout << "*** Welcome to Matthew's sorting program ***";

    //USER: FIRST FILE MECHANICS
    cout << "\nEnter the first input file name: ";
    getline(cin, firstFile);
    if (check_file(firstFile)) {
        firstNumbers = read_file(firstFile, firstNumbers);
        sort_vector(firstNumbers);
    } else {
        cout << "\nFile does not exist.";
    }

    //USER: SECOND FILE MECHANICS
    cout << "\nEnter the second input file name: ";
    getline(cin, secondFile);
    if (check_file(secondFile)) {
        secondNumbers = read_file(secondFile, secondNumbers);
        sort_vector(secondNumbers);
    } else {
        cout << "\nFile does not exist.";
    }

    //USER: THIRD FILE MECHANICS
    for (int i = 0; i < firstNumbers.size(); i++) {
        sortedNumbers.push_back(firstNumbers[i]);
    }
    for (int i = 0; i < secondNumbers.size(); i++) {
        sortedNumbers.push_back(secondNumbers[i]);
    }
    sortedNumbers = sort_vector(sortedNumbers);
    read_vector(sortedNumbers);
    cout << "\nEnter the output file name: ";
    getline(cin, sortedFile);
    write_file(sortedFile, sortedNumbers);
    cout << "*** Please check the new file - " << sortedFile << " ***";
    cout << "\n*** Goodbye. ***";
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

    cout << "The list of " << numbers.size() << " numbers in file " << fileName << " is:\n";
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << "\n";
    }

    return numbers;
}

//METHOD: READS A GIVEN VECTOR
void read_vector(vector<int> numbers) {
    cout << "\nThe sorted list of " << numbers.size() << " numbers is: ";
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << " ";
    }
}

//METHOD: SORTS A GIVEN FILE AND RETURNS A VECTOR
vector<int> sort_vector(vector<int> numbers) {
    int min;
    int temp;

	for (int i = 0; i < numbers.size(); i++) {
		min = i;
		for (int j = i + 1; j < numbers.size(); j++) {
			if (numbers[j] < numbers[min]) {
				min = j;
			}
		}

		temp = numbers[min];
		numbers[min] = numbers[i];
		numbers[i] = temp;
	}

    return numbers;
}

void write_file(string fileName, vector<int> numbers) {
    ofstream outputFile;
    outputFile.open(fileName);
    
    if (outputFile.fail()) {
        cout << "\nFailed to write to file.";
    } else {
        for (int i = 0; i < numbers.size(); i++) {
            outputFile << numbers[i] << "\n";
        }
    }

    outputFile.close();
}