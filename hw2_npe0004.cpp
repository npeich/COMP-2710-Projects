#include <iostream>
#include <cmath>
using namespace std;

//Natalie Eichorn
//npe0004
//hw2_npe0004.cpp
/*Program calculates how long it will take to pay something off while
accounting for how much the user wants to pay per month and interest rates.*/
//Help = class slides, class textbook, online c++ compiler (cpp.sh/).

int main() {

	double loan = 0.0;
	double rate = 0.0; //per month so needs to divide by 12!
	double payment = 0.0;

	/*this function figures out how many months it takes to pay off the loan
	and the total interest paid*/
	void totals(double startAmt, double interest, double payment, double rate);


//-----COLLECTING USER DATA------------------------------------------------------
	cout << "Loan Amount: ";
	cin >> loan;

	cout << "Interest Rate (\% per year): ";
	cin >> rate;
	rate = rate/1200;

	cout << "Monthly Payments: ";
	cin >> payment;


//-----FORMATTING OUTPUT----------------------------------------------------------
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << "******************************************************" << endl
		 << "       Amortization Table" << endl
		 << "******************************************************" << endl;

	cout << "Month   Balance   Payment   Rate   Interest   Principal" << endl;
	cout << "0       $" << loan << "     N/A     N/A       N/A      N/A" << endl;

	totals(loan, rate, payment, rate);
}


//------FUNCTION TO DETERMINE PAYMENTS/INTEREST/FORMATTING PER MONTH--------------
void totals(double startAmt, double interest, double payment, double rate) {

	double interestOnStart = 0.0;
	double remaining = 0.0;
	int month = 0;
	double totalInterest = 0.0;


	while (startAmt > 0) {
		month++;
		interestOnStart = startAmt * interest; //interest in this case is the rate per month
		totalInterest += interestOnStart;
		remaining = payment - interestOnStart;
		startAmt -= remaining;

		if (payment < interestOnStart) {
			cout << "...\t...\t...\t...\t..."<< endl;
			break;
		}

		else {
			if (startAmt < 0) {
				payment = startAmt += remaining;
				remaining = payment;
				payment += interestOnStart;
				startAmt = 0.0;
			}

			cout << month << "\t$" << startAmt << "\t$" << payment << "\t" << rate * 100 << "\t$" 
				<< interestOnStart << "\t$" << remaining << endl;
		}
	}


	if (payment < interestOnStart) {
		cout << "******************************************************" << endl;
		cout << "Please make sure that monthly payments are more than monthly interest." << endl;
	}
	else {
		cout << "******************************************************" << endl;
		cout << "\nIt takes " << month << " months to pay off the loan." << endl;
		cout << "Total interest paid is: $" << totalInterest << endl;
	}
}

