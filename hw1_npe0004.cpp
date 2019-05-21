#include <iostream>
#include <cmath>
using namespace std;

//Natalie Eichorn
//npe0004
//hw1_npe0004.cpp
//Program takes in amount of sweetener to kill a mouse, the mouse's weight,
//and the weight of the dieter to determine how much diet soda they can drink
//without dying.
//I did not recieve any help.

int main() {

	const double DEADLY_FRACTION = .001;
	double fatalM = 0, fatalH = 0, mouseW = 0, humanW = 0;

	cout << "Please input the weight of the mouse in kg ";
	cin >> mouseW;

	cout << "Please input the fatal amount of sweetener for mouse in kg ";
	cin >> fatalM;

	cout << "Please input the weight of your dear friend in kg ";
	cin >> humanW;

	fatalH = (fatalM * humanW) / (mouseW * DEADLY_FRACTION);

	cout << "The fatal amount of Coke for your friend is: " << fatalH << " kg";
	cout <<endl;
}