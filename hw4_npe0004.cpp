#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

//Natalie Eichorn
//npe0004
//hw4_npe0004.cpp

/*This program will read lists of numbers from 2 files and combine and sort them in
 * ascending order to output in a new file.*/

/*Help = help session with TA/Dr Li, help with sorting logic, worked with Matthew Sherrill and Sterling Fuchsberger,
 * class slides, class textbook, online c++ compiler (cpp.sh/).*/


//---DECLARATIONS------------------------------------------------------------
int readfile(int inputArray[], ifstream& instream);
int sort(int inputArray[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]);
void writefile(int outputArray[], int outputArray_size);

const int MAX_SIZE = 100;


int main() {
//---VARIABLES----------------------------------------------------------------
	ifstream ins;
	ifstream ins2;
	ofstream out;

	int data;
	string fileName;

	int iArray1[MAX_SIZE];
	int iArray1_size;
	int iArray2[MAX_SIZE];
	int iArray2_size;
	int outputArray[MAX_SIZE];


	cout << "*** Welcome to Natalie Eichorn's sorting program ***" << endl;


//---OPENING FIRST FILE (as array of chars)----------------------------------
	cout << "Enter the first input file name: ";

	cin >> fileName;

	//check
	//cout << "you are reading " << fileName << endl;

    //opening file-----------------------------------
	ins.open((char*)fileName.c_str());

	if (ins.fail()) {
		cout << "file could not be opened!!" << endl;
		exit(1);
	}


	iArray1_size = readfile(iArray1, ins);

    cout << "The list of " << iArray1_size << " numbers in file " << fileName << " is:" << endl;

    for (int i = 0; i < iArray1_size; i++) {
        cout << iArray1[i] << endl;
    }

	ins.close();

//---OPENING SECOND FILE (as array of chars)--------------------------------
    cout << "\nEnter the second input file name: ";

    cin >> fileName;

    //check
    //cout << "you are reading " << fileName << endl;

    //opening file----------------------------------
    ins2.open((char*)fileName.c_str());

    if (ins2.fail()) {
        cout << "file could not be opened!!" << endl;
        exit(1);
    }


    iArray2_size = readfile(iArray2, ins2);

    cout << "The list of " << iArray2_size << " numbers in file " << fileName << " is:" << endl;

    for (int i = 0; i < iArray2_size; i++) {
        cout << iArray2[i] << endl;
    }

    ins2.close();

    cout << "" << endl;


//---SORT FUNCTION------------------------------------------------------------------

    int outsize = sort(iArray1, iArray1_size, iArray2, iArray2_size, outputArray);

    cout << "The sorted list of " << outsize << " numbers is: ";

    for (int j = 0; j < outsize; j++) {
        cout << outputArray[j] << " ";
    }

//---WRITE FUNCTION-----------------------------------------------------------------

    writefile(outputArray, outsize);

    return 0;
}

int readfile(int inputArray[], ifstream& instream) {
	int index = 0;

	instream >> inputArray[index];

	while (!instream.eof()) {
        index++;
		instream >> inputArray[index];
        //index++;
	}
    index++;
	instream >> inputArray[index];

	return index;
}


int sort(int inputArray[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]) {

    int newSize = inputArray1_size + inputArray2_size;
    //cout << "new size = " << newSize << endl;


//--adding to original list--------------------
    int counter = 0;
    for (int i = 0; i < inputArray1_size; i++) {
        outputArray[i] = inputArray[i];
        counter++;
        //cout << outputArray[i] << endl;
    }

    int k = 0;
    for (int j = counter; j < counter + inputArray2_size; j++) {
        outputArray[j] = inputArray2[k];
        k++;
        //cout << outputArray[j] << endl;
    }

//--sorting-------------------------------------

    int min;
    int holder;

    //--looping thru combined list--------------
        for (int k = 0; k < newSize - 1; k++) {
            min = k;

            for (int l = k + 1; l < newSize; l++)

                if (outputArray[l] < outputArray[min])
                    min = l;

                holder = outputArray[k];
                outputArray[k] = outputArray[min];
                outputArray[min] = holder;
        }

    /*cout << "\n\nsorted list = " << endl;

    for (int o = 0; o < newSize; o++) {
        cout << outputArray[o] << endl;
    }
    */

    return newSize;
}


void writefile(int outputArray[], int outputArray_size) {

    ofstream outs;

    outs.open("output.txt");

    for (int i = 0; i < outputArray_size; i++) {
        outs << outputArray[i] << endl;
    }

    outs.close();
    outs.clear();
}

