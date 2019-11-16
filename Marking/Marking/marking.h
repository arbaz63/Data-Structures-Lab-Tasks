#pragma once
#include <iostream>
#include <string>
#include "node.h"
using namespace std;

class marking
{
	node* front, * rear;
	int count;
	string regNo;
public:
	marking(); //default consructor
	marking& submitAssignment(string regNumber); // function to submit an assignment
	void marks(node*& ptr); //Function to set marks
	node* dequeue(); //Function to remove a student from queue
	bool isEmpty() const; //function to check if queue is empty
	void print() const; //function to print all the students with numbers
};
