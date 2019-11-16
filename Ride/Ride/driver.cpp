#include <iostream>
#include "ride.h"
using namespace std;

const int SIZE = 5;
int COUNTER = 18;
int main() 
{
	ride q1[SIZE];
	int numOfRiders;
	int option;
	int i = 0, j=0,k=0;
	do {
		cout << "Choose one of the following option: " << endl;
		cout << "1" << "\t" << "To add riders" << endl;
		cout << "2" << "\t" << "To start Ride" << endl;
		cout << "3" << "\t" << "To get number of riders in current ride" << endl;
		cout << "4" << "\t" << "To exit program" << endl;
		cout << "Please choose one option: ",
			cin >> option;


		//*************************************************************************************************************************************************************
		//Using Switch statement to call a function.
		//*************************************************************************************************************************************************************	
		switch (option) {
		case 1: {

			cout << "Enter number of riders" << endl;
			cin >> numOfRiders;


			for (; i < SIZE; i++) {


				for (j=0; j < numOfRiders; j++) {
					node* ptr = new node();
					q1[i].addRiders(ptr);
					if (q1[i].count == COUNTER) break;
				}


				numOfRiders = numOfRiders - (j + 1);
				if (numOfRiders + 1 == 0) break;


			}
		}
			  break;

		case 2: {

			if (q1[k].count == COUNTER) {
				cout << "The ride has been started" << endl;
				k++;

			}
			else {
				cout << "There are not enough riders so the ride cannot be started" << endl;
			}
		}
			  break;
		case 3: {
			cout << "The number of riders in the current ride is " << q1[k].count << endl;
		}
			  break;
		case 4:
		{
			cout << "Your program is terminated...!!!" << endl << endl;
			break;
		}

		}
	} while (option != 4);

	return 0;
}