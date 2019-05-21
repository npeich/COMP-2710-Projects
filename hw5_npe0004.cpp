#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

//Natalie Eichorn
//npe0004
//hw5_npe0004.cpp
/*
 * this program runs a fun trivia quiz! users enter their own questions and answer questions
 * provided by the program. this program was a great help in understanding nodes and linked
 * lists!
 */
//Help = office hours, class slides, class textbook, online c++ compiler (cpp.sh/).



//---TRIVIA STRUCTURE----------------------------------------------------
struct TriviaNode {
    string question;
    string answer;
    int points;
    TriviaNode* pointer;
};

//--DECLARATIONS--------------------------------------------------------
void initializeQ(TriviaNode *start);
void newQ(TriviaNode *s);
bool checkAnswer(string a, TriviaNode *n);
void askQ(TriviaNode *n, int total);
void Unit_Testing(TriviaNode *start);

bool cont = false;
int totalQs;
bool correct = true;


//---MAIN FUNCTION-------------------------------------------------------
int main() {

//#define UNIT_TESTING
#ifdef UNIT_TESTING
    TriviaNode *starter = new TriviaNode;
    initializeQ(starter);
    Unit_Testing(starter);
}
#else

    TriviaNode *starter = new TriviaNode;

    //creates hard coded ?s
    initializeQ(starter);

    cout << "*** Welcome to Natalie's trivia quiz game ***" << endl;

    //creates user ?s
    do {
        newQ(starter);
    } while (cont);

    //cout << "total ?s = " << totalQs << endl;

    //!do i have to do the for loop or is it ok that i used a function?
    //asks the user all created ?s
    cin.ignore(1);
    askQ(starter, totalQs);

    cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***";
}
#endif

//---INITIALIZES LINKED LIST------------------------------------------------------
void initializeQ(TriviaNode *s) {
    TriviaNode *Question1 = s;
    TriviaNode *Question2 = new TriviaNode;
    TriviaNode *Question3 = new TriviaNode;

    Question1->question = "How long was the shortest war on record? (Hint: how many minutes)";
    Question1->answer = "38";
    Question1->points = 100;
    Question1->pointer = Question2;

    Question2->question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
    Question2->answer = "Bank of Italy";
    Question2->points = 50;
    Question2->pointer = Question3;

    Question3->question = "What is the best-selling video game of all time? (Hint: Minecraft or Tetris)";
    Question3->answer = "Tetris";
    Question3->points = 20;
    Question3->pointer = NULL;

    totalQs = 3;
}

//---ADDS NEW QUESTIONS TO LINKED LIST-------------------------------------------
void newQ(TriviaNode *s) {
    string goOn;

    //gets to the end of the list
    while(s->pointer!=NULL) {
        s = s->pointer;
    }

    TriviaNode *userQ = new TriviaNode();

    cout << "Enter a question: ";
    cin >> userQ->question;

    cout << "Enter an answer: ";
    cin >> userQ->answer;

    cout << "Enter award points: ";
    cin >> userQ->points;

    s->pointer = userQ;

    cout << "Continue? (Yes/No): ";
    totalQs++;
    cin >> goOn;

    //breaks the do while loop in main function
    if (goOn.compare("no") == 0 || goOn.compare("No") == 0 || goOn.compare("NO") == 0) {
        cont = false;
    }
    else {
        cont = true;
    }
}

//---USED TO ASK THE USER QUESTIONS IN LIST --------------------------------------
void askQ(TriviaNode *n, int total) {
    int totalPoints = 0;
    string userA;

    //tests
    if(total == 0) {
        cout << "Warning - The number of trivia to be asked must equal to or larger than 1." << endl;
    }
    else if (total == 1) {
        cout << "\nQuestion: " << n->question;
        cout << "\nAnswer: ";
        getline(cin, userA);

        if (checkAnswer(userA, n)) {
            correct = true;
        } else {
            correct = false;
        }
        n = n->pointer;
        cout << endl;
    }
    else if (total == 3) {
        while (n->pointer != NULL) {
            n = n->pointer;
        }
        cout << "\nQuestion: " << n->question;
        cout << "\nAnswer: ";
        getline(cin, userA);
    }
    else if (total > totalQs) {
        cout << "Warning - There are only three trivia in the list." << endl;
    }

    //main
    else {

        for (int i = 0; i < total; i++) {
            cout << "\nQuestion: " << n->question;
            cout << "\nAnswer: ";
            getline(cin, userA);

            if (checkAnswer(userA, n)) {
                cout << "Your answer is correct. You receive " << n->points << " points." << endl;
                totalPoints += n->points;
                cout << "Your total points: " << totalPoints;
            } else {
                cout << "Your answer is wrong.  The correct answer is " << n->answer << endl;
                cout << "Your total points: " << totalPoints;
            }
            n = n->pointer;
            cout << endl;
        }
    }

}

//--CHECKS TO SEE IF ANSWER IS CORRECT------------------------------------------
bool checkAnswer(string a, TriviaNode *n) {
    if (n->answer.compare(a) == 0) {
        return true;
    }
    return false;
}

void Unit_Testing(TriviaNode *start) {

    cout << "*** This is a debug version ***" << endl;
    cout << "Unit Test Case 1: Ask no questions. The program should give a warning message." << endl;
    askQ(start, 0);

    cout << "\nUnit Test Case 2.1: Ask 1 question in the linked list. The tester enters an incorrect answer.";
    askQ(start, 1);
    if (!correct) {
        cout << "Case 2.1 passed..." << endl;
    }

    cout << "\nUnit Test Case 2.2: Ask 1 question in the linked list. The tester enters a correct answer.";
    askQ(start, 1);
    if (correct) {
        cout << "Case 2.2 passed..." << endl;
    }

    cout << "\nUnit Test Case 3: Ask the last trivia in the linked list.";
    askQ(start, 3);

    cout << "\nUnit Test Case 4: Ask 5 questions in the linked list." << endl;
    askQ(start, 5);

    cout << "\n*** End of the Debug Version ***";
}


