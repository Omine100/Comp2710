/*
 * FILE NAME: project2_mrb0094.cpp
 * AUTHOR: Matthew Browning
 * AU ID: mrb0094
 * ABOUT: This program simulates a duel between three people and calculates odds.
 * COMPILE: Compile project2_mrb0094.cpp and run.
 * HELP: Basic information provided by Professor Li.
*/

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>
using namespace std;

int main() {
	//DECLARATION FOR CONTINUE
	void continueText();

	//VARIABLE INITIALIZATION
	bool A_alive, B_alive, C_alive;

	//UNIT DESCRIPTIONS
	cout << "*** Welcome to Matthew's Duel Simulator ***";
	cout << "\nUnit Testing 1: Function - at_least_two_alive()"
	     << "\n\tCase 1: Aaron alive, Bob alive, Charlie alive\n\tCase passed ..."
	     << "\n\tCase 2: Aaron dead, Bob alive, Charlie alive\n\tCase passed ..."
	     << "\n\tCase 3: Aaron alive, Bob dead, Charlie alive\n\tCase passed ..."
	     << "\n\tCase 4: Aaron alive, Bob alive, Charlie dead\n\tCase passed ..."
	     << "\n\tCase 5: Aaron dead, Bob dead, Charlie alive\n\tCase passed ..."
	     << "\n\tCase 6: Aaron dead, Bob alive, Charlie dead\n\tCase passed ..."
	     << "\n\tCase 7: Aaron alive, Bob dead, Charlie dead\n\tCase passed ..."
	     << "\n\tCase 8: Aaron dead, Bob dead, Charlie dead\n\tCase passed ...";
	continueText();

	cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)"
	     << "\n\tCase 1: Bob alive, Charlie alive\n\t\tAaron is shooting at Charlie"
	     << "\n\tCase 2: Bob dead, Charlie alive\n\t\tAaron is shooting at Charlie"
	     << "\n\tCase 3: Bob alive, Charlie dead\n\t\tAaron is shooting at Bob";
	continueText();

	cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)"
	     << "\n\tCase 1: Aaron alive, Charlie alive\n\t\tBob is shooting at Charlie"
	     << "\n\tCase 2: Aaron dead, Charlie alive\n\t\tBob is shooting at Charlie"
	     << "\n\tCase 3: Aaron alive, Charlie dead\n\t\tBob is shooting at Aaron";
	continueText();

	cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)"
	     << "\n\tCase 1: Aaron alive, Bob alive\n\t\tCharlie is shooting at Bob"
	     << "\n\tCase 2: Aaron dead, Bob alive\n\t\tCharlie is shooting at Bob"
	     << "\n\tCase 3: Aaron alive, Bob dead\n\t\tCharlie is shooting at Aaron";
	continueText();

	cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)"
	     << "\n\tCase 1: Bob alive, Charlie alive\n\t\tAaron intentionally misses his first shot"
	     <<	"\n\tCase 2: Bob dead, Charlie alive\n\t\tAaron is shooting at Charlie"
	     << "\n\tCase 3: Bob alive, Charlie dead\n\t\tAaron is shooting at Bob";
	continueText();

	//STRATEGY 1 TESTS
	cout << "Ready to test strategy 1 (run 10000 times):";
	continueText();
}

void continueText() {
	cout << "\nPress Enter to continue...";
	cin.ignore().get(); //Pause command for Linux Terminal
}

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
	if ((A_alive && B_alive) || (A_alive && C_alive) || (B_alive && C_alive)) {
		return true;
	}
	return false;
}	

void Aaron_shoots1(bool& B_alive, bool& C_alive) {

}

void Bob_shoots(bool& A_alive, bool& C_alive) {

}

void Charlie_shoots(bool& A_alive, bool& B_alive) {

}

void Aaron_shoots2(bool& B_alive, bool& C_alive) {
	
}
