/*
 * FILE NAME: project2_mrb0094.cpp
 * AUTHOR: Matthew Browning
 * AU ID: mrb0094
 * ABOUT: This program simulates a duel between three people and calculates odds.
 * COMPILE: Compile project2_mrb0094.cpp and run.
 * HELP: Basic information provided by Professor Li and talk through with Ezra Hill from class.
*/

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>
using namespace std;

//WINNING VARIABLES
int aaronWins1 = 0, bobWins = 0, charlieWins = 0, aaronWins2 = 0;

//MAIN
int main() {
	//DECLARATION FOR CONTINUE
	void Press_any_key();

	//VARIABLE INITIALIZATION
	const int TOTAL_RUNS = 10000;

	//TEST PROTOTYPES
	void test_at_least_two_alive(void);
	void test_Aaron_shoots1(void);
	void test_Bob_shoots(void);
	void test_Charlie_shoots(void);
	void test_Aaron_shoots2(void);
	void duel_strat1(void);
	void duel_strat2(void);

	//UNIT DESCRIPTIONS AND TESTING
	cout << "*** Welcome to Matthew's Duel Simulator ***";
	srand(time(0));
	test_at_least_two_alive();
	Press_any_key();
	test_Aaron_shoots1();
	Press_any_key();
	test_Bob_shoots();
	Press_any_key();
	test_Charlie_shoots();
	Press_any_key();
	test_Aaron_shoots2();
	Press_any_key();

	//STRATEGY 1 TESTS
	cout << "Ready to test strategy 1 (run 10000 times):";
	Press_any_key();
	for (int i = 0; i < TOTAL_RUNS; i++) {
		duel_strat1();
	}
	cout << "Aaron won " << aaronWins1 << "/10000 duels or " << static_cast<double>(aaronWins1) / TOTAL_RUNS * 100 << "%\n";
	cout << "Bob won " << bobWins << "/10000 duels or " << static_cast<double>(bobWins) / TOTAL_RUNS * 100 << "%\n";
	cout << "Charlie won " << charlieWins << "/10000 duels or " << static_cast<double>(charlieWins) / TOTAL_RUNS * 100 << "%\n";

	//STRATEGY 2 TESTS
	cout << "\nReady to test strategy 2 (run 10000 times):";
	Press_any_key();
	bobWins = 0, charlieWins = 0, aaronWins2 = 0;
	for (int i = 0; i < TOTAL_RUNS; i++) {
		duel_strat2();
	}
	cout << "Aaron won " << aaronWins2 << "/10000 duels or " << static_cast<double>(aaronWins2) / TOTAL_RUNS * 100 << "%\n";
	cout << "Bob won " << bobWins << "/10000 duels or " << static_cast<double>(bobWins) / TOTAL_RUNS * 100 << "%\n";
	cout << "Charlie won " << charlieWins << "/10000 duels or " << static_cast<double>(charlieWins) / TOTAL_RUNS * 100 << "%\n";

	//STRATEGY COMPARISON
	aaronWins2 > aaronWins1 ? cout << "\nStrategy 2 is better than strategy 1" : cout << "Strategy 1 is better than strategy 2";
}

//CONTINUE TEXT
void Press_any_key() {
	cout << "\nPress Enter to continue...";
	cin.ignore().get(); //Pause command for Linux Terminal
}

//IMPLEMENTATION OF FUNCTION AT_LEAST_TWO_ALIVE
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
	if (A_alive) {
		if (B_alive || C_alive) {
				return true;
		}
	} else if (B_alive) {
		if (C_alive) {
			return true;
		}
	}
	return false;
}

//IMPLEMENTATION OF FUNCTION AARON_SHOOTS1
void Aaron_shoots1(bool& B_alive, bool& C_alive) {
	int probability_aaron = 33;
	int result = rand()%100 + 1;

	if (result <= probability_aaron) {
		C_alive ? C_alive = false : B_alive = false;
	}
}

//IMPLEMENTATION OF FUNCTION BOB_SHOOTS
void Bob_shoots(bool& A_alive, bool& C_alive) {
	int probability_bob = 50;
	int result = rand()%100 + 1;

	if (result <= probability_bob) {
		C_alive ? C_alive = false : A_alive = false;
	}
}

//IMPLEMENTATION OF FUNCTION CHARLIE_SHOOTS
void Charlie_shoots(bool& A_alive, bool& B_alive) {
	B_alive ? B_alive = false : A_alive = false;
}

//IMPLEMENTATION OF FUNCTION AARON_SHOOTS2
void Aaron_shoots2(bool& B_alive, bool& C_alive) {
	int probability_aaron = 33;
	int result = rand()%100 + 1;

	if ((!B_alive || !C_alive) && (result <= probability_aaron)) {
		C_alive ? C_alive = false : B_alive = false;
	}
}

//DUEL STRATEGY1
void duel_strat1(void) {
	bool a_alive = true, b_alive = true, c_alive = true;

	while (at_least_two_alive(a_alive, b_alive, c_alive)) {
		if (a_alive) {
			Aaron_shoots1(b_alive, c_alive);
		} 
		if (b_alive) {
			Bob_shoots(a_alive, c_alive);
		} 
		if (c_alive) {
			Charlie_shoots(a_alive, b_alive);
		}
	}

	if (a_alive) {
		aaronWins1++;
	} else if (b_alive) {
		bobWins++;
	} else {
		charlieWins++;
	}
}

//DUEL STRATEGY2
void duel_strat2(void) {
	bool a_alive = true, b_alive = true, c_alive = true;

	while (at_least_two_alive(a_alive, b_alive, c_alive)) {
		if (a_alive) {
			Aaron_shoots2(b_alive, c_alive);
		} 
		if (b_alive) {
			Bob_shoots(a_alive, c_alive);
		} 
		if (c_alive) {
			Charlie_shoots(a_alive, b_alive);
		}
	}

	if (a_alive) {
		aaronWins2++;
	} else if (b_alive) {
		bobWins++;
	} else {
		charlieWins++;
	}
}

//TESTING OF AT_LEAST_TWO_ALIVE
void test_at_least_two_alive(void) {
	cout << "\nUnit Testing 1: Function - at_least_two_alive()";
	
	cout << "\n\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
	assert(true == at_least_two_alive(true, true, true));
	cout << "\tCase passed ...";

	cout << "\n\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
	assert(true == at_least_two_alive(false, true, true));
	cout << "\tCase passed ...";

	cout << "\n\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
	assert(true == at_least_two_alive(true, false, true));
	cout << "\tCase passed ...";

	cout << "\n\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
	assert(true == at_least_two_alive(true, true, false));
	cout << "\tCase passed ...";

	cout << "\n\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
	assert(false == at_least_two_alive(false, false, true));
	cout << "\tCase passed ...";

	cout << "\n\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
	assert(false == at_least_two_alive(false, true, false));
	cout << "\tCase passed ...";
	
	cout << "\n\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
	assert(false == at_least_two_alive(true, false, false));
	cout << "\tCase passed ...";

	cout << "\n\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
	assert(false == at_least_two_alive(false, false, false));
	cout << "\tCase passed ...";
}

//TESTING OF AARON_SHOOTS1
void test_Aaron_shoots1(void) {
	cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)";

	bool B_alive = true, C_alive = true;

	cout << "\n\tCase 1: Bob alive, Charlie alive\n\t\tAaron is shooting at Charlie";
	Aaron_shoots1(B_alive, C_alive);
	assert(true == B_alive);

	cout << "\n\tCase 2: Bob dead, Charlie alive\n\t\tAaron is shooting at Charlie";
	B_alive = false, C_alive = true;
	Aaron_shoots1(B_alive, C_alive);
	assert(false == B_alive);

	cout << "\n\tCase 3: Bob alive, Charlie dead\n\t\tAaron is shooting at Bob";
	B_alive = true, C_alive = false;
	Aaron_shoots1(B_alive, C_alive);
	assert(false == C_alive);
}

//TESTING OF BOB_SHOOTS
void test_Bob_shoots(void) {
	cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)";

	bool A_alive = true, C_alive = true;

	cout << "\n\tCase 1: Aaron alive, Charlie alive\n\t\tBob is shooting at Charlie";
	Bob_shoots(A_alive, C_alive);
	assert(true == A_alive);

	cout << "\n\tCase 2: Aaron dead, Charlie alive\n\t\tBob is shooting at Charlie";
	A_alive = false, C_alive = true;
	Bob_shoots(A_alive, C_alive);
	assert(false == A_alive);

	cout << "\n\tCase 3: Aaron alive, Charlie dead\n\t\tBob is shooting at Aaron";
	A_alive = true, C_alive = false;
	Bob_shoots(A_alive, C_alive);
	assert(false == C_alive);
}

//TESTING OF CHARLIE_SHOOTS
void test_Charlie_shoots(void) {
	cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)";

	bool A_alive = true, B_alive = true;

	cout << "\n\tCase 1: Aaron alive, Bob alive\n\t\tCharlie is shooting at Bob";
	Charlie_shoots(A_alive, B_alive);
	assert(true == A_alive);
	assert(false == B_alive);

	cout << "\n\tCase 2: Aaron dead, Bob alive\n\t\tCharlie is shooting at Bob";
	A_alive = false, B_alive = true;
	Charlie_shoots(A_alive, B_alive);
	assert(false == A_alive);
	assert(false == B_alive);

	cout << "\n\tCase 3: Aaron alive, Bob dead\n\t\tCharlie is shooting at Aaron";
	A_alive = true, B_alive = false;
	Charlie_shoots(A_alive, B_alive);
	assert(false == A_alive);
	assert(false == B_alive);
}

//TESTING OF AARON_SHOOTS2
void test_Aaron_shoots2(void) {
	cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)";

	bool B_alive = true, C_alive = true;

	cout << "\n\tCase 1: Bob alive, Charlie alive\n\t\tAaron intentionally misses his first shot";
	Aaron_shoots2(B_alive, C_alive);
	assert(true == B_alive);
	assert(true == C_alive);

	cout << "\n\tCase 2: Bob dead, Charlie alive\n\t\tAaron is shooting at Charlie";
	B_alive = false, C_alive = true;
	Aaron_shoots2(B_alive, C_alive);
	assert(false == B_alive);

	cout << "\n\tCase 3: Bob alive, Charlie dead\n\t\tAaron is shooting at Bob";
	B_alive = true, C_alive = false;
	Aaron_shoots2(B_alive, C_alive);
	assert(false == C_alive);
}