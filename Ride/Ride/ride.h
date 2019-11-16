#pragma once
#include "node.h"
#include <iostream>
using namespace std;

class ride
{
	node* front, * rear;
	
public:
		int count;
		ride(); //default consructor
		ride& addRiders(node *& ptr);	//function to insert a node in the queue
		node* dequeue(); //Function to remove a node from the queue
		bool isEmpty() const; //function to check if the queue is empty
		void print() const; //Function to print the elements of te queue
		int getCount();
		~ride();
};

