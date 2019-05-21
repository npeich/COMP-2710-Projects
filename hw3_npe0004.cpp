# include <iostream>
# include <stdlib.h>
# include <assert.h>
# include<cstdlib>
using namespace std;

//Natalie Eichorn
//npe0004
//hw3_npe0004.cpp

/*Program determines the winner of duels based on probability and different
strategies.  The winner is the Greatest Puzzle Solver of All Time!*/
//Help = class slides, class textbook, online c++ compiler (cpp.sh/).



//--GLOBAL VARIABLE DECLARATION------------------------------------------
const int A_HIT = 33;
const int B_HIT = 50;
const int C_HIT = 100;

bool A_alive = true;
bool B_alive = true;
bool C_alive = true;	

const int TOTAL_DUELS = 10000;



double A_win = 0;
double A_win2 = 0;
double B_win = 0;
double C_win = 0;

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
void Aaron_shoots1(bool& B_alive, bool& C_alive);
void Bob_shoots(bool& A_alive, bool& C_alive);
void Charlie_shoots(bool& A_alive, bool& B_alive);
void Aaron_shoots2(bool& B_alive, bool& C_alive);
void test_at_least_two_alive(void);



int main() {
srand(100);
//---PRINTS OUT USER INTERFACE-------------------------------------------
	cout << "*** Welcome to the Duel Simulator ***" << endl;

	test_at_least_two_alive();

	cout << "Press Enter to continue...";
	cin.get();

	cout << "Ready to test strategy 1 (run 10000 times):" << endl;
	cout << "Press Enter to continue...";
	cin.get();


//---RUNS DUEL-----------------------------------------------------------
	//---STRATEGY 1------------------------------------------------------
	for (int i = 0; i < TOTAL_DUELS; i++) {
		//reset variables to true each time to run duel correctly
		A_alive = true;
		B_alive = true;
		C_alive = true;

		while (at_least_two_alive(A_alive, B_alive, C_alive)) {
			if (A_alive) {
				Aaron_shoots1(B_alive, C_alive);
			}
			if (B_alive) {
				Bob_shoots(A_alive, C_alive);
			}
			if (C_alive) {
				Charlie_shoots(A_alive, B_alive);
			}
		}

		//gives points to winner at the end of duel
		if (A_alive) {
			A_win++;
			//cout << "A WIN" << endl;
		}
		else if (B_alive) {
			B_win++;
			//cout << "B WIN" << endl;
		}
		else if (C_alive) {
			C_win++;
			//cout << "C WIN" << endl;
		}
	}

	cout << "Aaron won " << A_win << "/" << TOTAL_DUELS << " dules or " << 
		((A_win/TOTAL_DUELS) * 100) << "%" << endl;
	cout << "Bob won " << B_win << "/" << TOTAL_DUELS << " dules or " << 
		((B_win/TOTAL_DUELS) * 100) << "%" << endl;
	cout << "Charlie won " << C_win << "/" << TOTAL_DUELS << " dules or " << 
		((C_win/TOTAL_DUELS) * 100) << "%\n" << endl;



	//---STRATEGY 2------------------------------------------------------
	cout << "Ready to test strategy 2 (run 10000 times):" << endl;
	cout << "Press Enter to continue...";
	cin.get();

	for (int i = 0; i < TOTAL_DUELS; i++) {
	//reset variables to true each time to run duel correctly
	A_alive = true;
	B_alive = true;
	C_alive = true;

		while (at_least_two_alive(A_alive, B_alive, C_alive)) {
			if (A_alive) {
				Aaron_shoots2(B_alive, C_alive);
			}
			if (B_alive) {
				Bob_shoots(A_alive, C_alive);
			}
			if (C_alive) {
				Charlie_shoots(A_alive, B_alive);
			}
		}

		//gives points to winner at the end of duel
		if (A_alive) {
			A_win2++;
			//cout << "A WIN" << endl;
		}
		else if (B_alive) {
			B_win++;
			//cout << "B WIN" << endl;
		}
		else if (C_alive) {
			C_win++;
			//cout << "C WIN" << endl;
		}
	}

	cout << "Aaron won " << A_win2 << "/" << TOTAL_DUELS << " dules or " << 
		((A_win2/TOTAL_DUELS) * 100) << "%" << endl;
	cout << "Bob won " << B_win << "/" << TOTAL_DUELS << " dules or " << 
		((B_win/TOTAL_DUELS) * 100) << "%" << endl;
	cout << "Charlie won " << C_win << "/" << TOTAL_DUELS << " dules or " << 
		((C_win/TOTAL_DUELS) * 100) << "%" << endl;



//---DETERMINE BEST STRATEGY---------------------------------------------------
	if (A_win2 > A_win) {
		cout << "\nStrategy 2 is better than strategy 1." << endl;
	}
	else {
		cout << "\nStrategy 1 is better than strategy 2." << endl;
	}

}



//===================================================================================



bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
	/* Input: A_alive indicates whether Aaron is alive */
	/* B_alive indicates whether Bob is alive */
	/* C_alive indicates whether Charlie is alive */
	/* Return: true if at least two are alive */
	/* otherwise return false */

	if ( (A_alive && B_alive) || (A_alive && C_alive) || (C_alive && B_alive) || (A_alive && B_alive && C_alive)) {
		return true;
	}
	return false;
}

void Aaron_shoots1(bool& B_alive, bool& C_alive) {
/* Strategy 1: Use call by reference
* Input: B_alive indicates whether Bob alive or dead
* C_alive indicates whether Charlie is alive or dead
* Return: Change B_alive into false if Bob is killed.
* Change C_alive into false if Charlie is killed.
*/
	int shoot;
	shoot = rand()%100;
	//cout << "A % = " << shoot << endl;

	if (shoot <= A_HIT) {
		//cout << "will hit target"<< endl;
		//kills C
		if (C_alive) {
			C_alive = false;
			//cout << "C KILLED" << endl;
		}
		//C already dead, kills B
		else if (B_alive) {
			B_alive = false;
			//cout << "B KILLED" << endl;
		}
	}
}

void Bob_shoots(bool& A_alive, bool& C_alive) {
/* Call by reference
* Input: A_alive indicates if Aaron is alive or dead
* C_alive indicates whether Charlie is alive or dead
* Return: Change A_alive into false if Aaron is killed.
* Change C_alive into false if Charlie is killed.
*/
	int shoot;
	shoot = rand()%100;
	//cout << "B % = " << shoot << endl;

	if (shoot <= B_HIT) {
		//cout << "will hit target"<< endl;
		//kills C
		if (C_alive) {
			C_alive = false;
			//cout << "C KILLED" << endl;
		}
		//C already dead, kills A
		else if (A_alive) {
			A_alive = false;
			//cout << "A KILLED" << endl;
		}
	}
}

void Charlie_shoots(bool& A_alive, bool& B_alive) {
/* Call by reference
* Input: A_alive indicates if Aaron is alive or dead
* B_alive indicates whether Bob is alive or dead
* Return: Change A_alive into false if Aaron is killed.
* Change B_alive into false if Bob is killed.
*/
	//always hits target
	int shoot;
	shoot = rand()%100;
	//cout << "C % = " << shoot << endl;
	if (shoot <= C_HIT) {
		//cout << "will hit target" << endl;
		//kills B
		if (B_alive) {
			B_alive = false;
			//cout << "B KILLED" << endl;
		}
		//B already dead, kills A
		else if (A_alive) {
			A_alive = false;
			//cout << "A KILLED" << endl;
		}
	}	
}

void Aaron_shoots2(bool& B_alive, bool& C_alive) {
/* Strategy 2: Use call by reference
* Input: B_alive indicates whether Bob alive or dead
* C_alive indicates whether Charlie is alive or dead
* Return: Change B_alive into false if Bob is killed.
* Change C_alive into false if Charlie is killed.
*/
	int shoot;
	shoot = rand()%100;
	if (!(B_alive && C_alive)) {
		if (shoot <= 33) {
			if (C_alive) {
				C_alive = false;
			}
			else if (B_alive) {
				B_alive = false;
			}
		}
	}
}

//---TEST DRIVER-------------------------------------------
void test_at_least_two_alive(void) {
	cout << "Unit Testing 1: Function – at_least_two_alive()\n";

	cout << "Case 1: Aaron alive, Bob alive, Charlie alive\n";
	assert(true == at_least_two_alive(true, true, true));
	cout << "Case passed ...\n";

	cout << "Case 2: Aaron dead, Bob alive, Charlie alive\n";
	assert(true == at_least_two_alive(false, true, true));
	cout << "Case passed ...\n";
	
	cout << "Case 3: Aaron alive, Bob dead, Charlie alive\n";
	assert(true == at_least_two_alive(true, false, true));
	cout << "Case passed ...\n";
	
	cout << "Case 4: Aaron alive, Bob alive, Charlie dead\n";
	assert(true == at_least_two_alive(true, true, false));
	cout << "Case passed ...\n";
	
	cout << "Case 5: Aaron dead, Bob dead, Charlie alive\n";
	assert(true == !at_least_two_alive(false, false, true));
	cout << "Case passed ...\n";
	
	cout << "Case 6: Aaron dead, Bob alive, Charlie dead\n";
	assert(true == !at_least_two_alive(false, true, false));
	cout << "Case passed ...\n";
	
	cout << "Case 7: Aaron alive, Bob dead, Charlie dead\n";
	assert(true == !at_least_two_alive(true, false, false));
	cout << "Case passed ...\n";
	
	cout << "Case 8: Aaron dead, Bob dead, Charlie dead\n";
	assert(true == !at_least_two_alive(false, false, false));
	cout << "Case passed ...\n";
}

