#pragma once
#include <iostream>
#include "node.h"
using namespace std;
class queue
{
	node* front, * rear;
public:
	queue(); //default consructor
	queue& enqueue(node*& ptr);	//function to insert a node in the queue
	node* dequeue(); //Function to remove a node from the queue
	int getFront(); //Function to get the value of front node of queue
	int getRear(); //Function to get the value of rear node of queue
	bool isEmpty() const; //function to check if the queue is empty
	void print() const; //Function to print the elements of te queue
	~queue();
};

