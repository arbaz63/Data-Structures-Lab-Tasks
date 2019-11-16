#pragma once
#include <iostream>
#include "node.h"


class rideWithPriority
{
	node* front, * rear;
public:
	int count;
	rideWithPriority(); //default consructor
	rideWithPriority& addRiders(node *& ptr);	//function to insert an element in the queue
	node* dequeue();//Function to remove a node from queue
	bool isEmpty() const; //Fnction to check if priority queue is empty
	~rideWithPriority();//desructor
};

