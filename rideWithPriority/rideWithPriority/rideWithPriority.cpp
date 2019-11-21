#include "rideWithPriority.h"
#include <iostream>
using namespace std;

//default constructor
rideWithPriority::rideWithPriority() :front(NULL), rear(NULL) {}

//Inserting a new node in the queue with priority
rideWithPriority& rideWithPriority::addRiders(node *&ptr)
{
	if (!front) { //if queue is empty
		front = rear = ptr;
		rear->setNextNode(NULL);
		ptr = NULL;
		count++;
		return *this;
	}
	else if (front->getPriority() < ptr->getPriority()) //when priority of new node is greater then front of priority queue
	{
		ptr->setNextNode(front);
		front = ptr;
		ptr = NULL;
		count++;
		return *this;
	}
	else if (rear->getPriority() >= ptr->getPriority()) {//when priority of new node is less or equal to front of priority queue

		rear->setNextNode(ptr);
		rear = rear->getNextNode();
		rear->setNextNode(NULL);
		ptr = NULL;
		count++;
		return *this;
	}
	else { //if priority is in between front and front
		node* rptr, * bptr;
		bptr = rptr = front;
		while (rptr->getPriority() >= ptr->getPriority()) {
			bptr = rptr;
			rptr = rptr->getNextNode();
		}
		ptr->setNextNode(rptr);
		bptr->setNextNode(ptr);
		ptr = NULL;
		count++;
	}
	return *this;
}

//Function to remove a node from from priority queue
node* rideWithPriority::dequeue()
{
	node* ptr;
	ptr = front;
	if (front->getNextNode() == NULL) //if only one node is present in the queue
	{
		rear = NULL;
	}
	front = front->getNextNode();
	ptr->setNextNode(NULL);
	count--;
	return ptr;
}


//Function to check if stack is empty
bool rideWithPriority::isEmpty() const {
	if (front == NULL) {//if it is empty returning true
		return true;
	}
	else {//if it is not empty returning false
		return false;
	}
}


rideWithPriority::~rideWithPriority()
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
