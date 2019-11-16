#include <iostream>
#include "rideWithPriority.h"
using namespace std;

const int SIZE = 5;
int COUNTER = 18;
int main()
{
	rideWithPriority q1[SIZE];
	int numOfRiders;
	int priority;
	int option;
	int i = 0, j = 0, k = 0;
	do {
		cout << "Choose one of the following option: " << endl;
		cout << "1" << "\t" << "To add riders" << endl;
		cout << "2" << "\t" << "To start Ride" << endl;
		cout << "3" << "\t" << "To get number of riders in current ride" << endl;
		cout << "4" << "\t" << "To exit program" << endl;
		cout << "Please choose one option: ",
			cin >> option;


		switch (option) {
		case 1: {
			int m = 0;
			cout << "Enter number of riders" << endl;
			cin >> numOfRiders;
			cout << "Enter priority 1 if VIP family otherwise 0" << endl;
			cin >> priority;

			for (; i < SIZE; i++) {

				if ((q1[i].count + numOfRiders) >= 18 && (priority==1)) 
				
				{
					 m = (q1->count + numOfRiders) - 18;
				
					 node* rptr;
					for (int n = 0; n < m; n++)
					{
						rptr=q1[i].dequeue();
						q1[i + 1].addRiders(rptr);
					}
					
				}
				for (j = 0; j < numOfRiders; j++) {
					node* ptr = new node();
					ptr->setPriority(priority);
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