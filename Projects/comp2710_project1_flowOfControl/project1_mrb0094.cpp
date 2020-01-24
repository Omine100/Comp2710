/*
 * FILE NAME: project1_mrb0094.cpp
 * AUTHOR: Matthew Browning
 * AU ID: mrb0094
 * ABOUT: This program prints repayment for a loan w/ interest.
 * COMPILE: Compile project1_mrb0094.cpp and run.
 * HELP: Basic information provided by Professor Li.
 * 	 Talking through project with Ezra Hill from class.
 */

#include <iostream>
using namespace std;

int main() {
	//VARIABLE DECLARATION
	double amountLoan;
	double amountInterestRate;
	double amountMonthlyPayment;
	double balance;
	double interest = 0.0;
	double totalInterest = 0.0;
	double principal = 0.0;
	int currentMonth = 0;

	//CURRENCY FORMATTING
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	//USER INPUT
	cout << "\nLoan Amount: ";
	cin >> amountLoan;
	while (amountLoan <= 0) {
		cout << "Loan must be a positive value: ";
		cin >> amountLoan;
	}
	cout << "Interest Rate (% per year): ";
	cin >> amountInterestRate;
	while (amountInterestRate <= 0) {
		cout << "Interest rate must be a positive value: ";
		cin >> amountInterestRate;
	}
	
	//GET PROPER INTEREST RATES FOR CALCULATIONS
	amountInterestRate = amountInterestRate / 12;
	amountInterestRate = amountInterestRate / 100;
	
	//USER INPUT CONT.
	cout << "Monthly Payments: ";
	cin >> amountMonthlyPayment;
	while (amountMonthlyPayment <= 0 || amountMonthlyPayment <= (amountLoan * amountInterestRate)) {
		cout << "Monthly payment must be positive and large enough to pay off loan: ";
		cin >> amountMonthlyPayment;
	}
	cout << endl;

	//VARIABLE INITIALIZATION
	balance = amountLoan;
	interest = balance * amountInterestRate;

	//AMORTIZATION TABLE
	cout << "*****************************************************************\n"
	     << "\tAmortization Table\n"
	     << "*****************************************************************\n"
	     << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal" <<
	     endl;

	cout << "0\t$" << amountLoan << "\tN/A\tN/A\tN/A\t\tN/A" <<
	     endl;
	
	//LOOP TO FILL TABLE
	while (balance > 0) {
		currentMonth++;
		interest = balance * amountInterestRate;
		totalInterest = totalInterest + interest;

		if (amountMonthlyPayment > (balance + interest)) {
			amountMonthlyPayment = balance + interest;
		}

		principal = amountMonthlyPayment - interest;
		balance = balance - principal;
		
		cout << currentMonth << "\t$" << balance << "   \t$" << amountMonthlyPayment << "\t" << amountInterestRate * 100 << "\t$" << interest << "\t\t$" << principal << 
		     endl;
	}
	cout << "*****************************************************************\n"
	     << "\nIt takes " << currentMonth << " months to pay off the loan."
	     << "\nTotal interest paid is: $" << totalInterest <<
	     endl; 
}
