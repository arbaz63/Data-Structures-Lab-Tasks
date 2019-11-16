#include "ride.h"
#include <iostream>
using namespace std;

//Default constructor
ride::ride() :count(0),front(NULL), rear(NULL) {}

//Inserting a new node in the queue
ride& ride::addRiders(node *&ptr)
{
		if (front == NULL) //If queue is empty
		{
			front = rear = ptr;
			front->setNextNode(NULL);
		}
		else //if queue is not empty
		{
			rear->setNextNode(ptr);
			rear = rear->getNextNode();
		}
		count++;
		rear->setNextNode(NULL);
		ptr = NULL;
	
	return *this;
}

//Function to remove a node from queue
node* ride::dequeue()
{
	node* ptr;
	ptr = front;
	if (front->getNextNode() == NULL) //If there is only one node in the queue
	{
		rear = NULL;
	}
	front = front->getNextNode();
	ptr->setNextNode(NULL);
	return ptr;
}



int ride::getCount() {
	return count;
}

//Function to check if stack is empty
bool ride::isEmpty() const {
	if (front == NULL) {//if STACK is empty returning true
		return true;
	}
	else {//if STACK is not empty returning false
		return false;
	}
}



//Function to print all the elements present in the QUEUE
void ride::print() const {
	if (isEmpty()) { //Checking if the QUEUE is empty
		cout << "There is no element." << endl;
	}
	else {
		cout << "All the elements in the queue are: ";
		node* ptr; //Declaring a runner pointer to move through
		ptr = front;
		while (ptr) {
			ptr->print();
			ptr = ptr->getNextNode();
		}
		cout << "\n\n";
	}
}

ride::~ride()
{
	node* ptr = front;

	rear = NULL;                                              // rear is going to NULL and we can make remaining code.

	while (ptr)
	{
		ptr = ptr->getNextNode();
		delete front;
		front = ptr;                                           // In last loop front will become Null. 
	}
}