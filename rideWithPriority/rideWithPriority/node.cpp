//Implementation file of node class

#pragma once
#include <iostream>
#include "node.h"
using namespace std;


//default constructor
node::node()
{
	nextNode = NULL;
	data = 0;
}



//Function used to set data passed by the user in node of STACK
node& node::setData(int number)
{
	this->data = number;
	return *this;
}

/*
Function used to get data and return it from a node of STACK
*/
int node::getData()
{
	return data;
}

//Function to set next node
void node::setNextNode(node* ptr)
{
	nextNode = ptr;
}
//Function to get next node
node* node::getNextNode()
{
	return nextNode;
}

//Fuction to priority of node
void node::setPriority(int p)
{
	priority = p;
}

//Function to get priority of node
int node::getPriority()
{
	return priority;
}

//Function to print priority  of the node
void node::printPriority()
{
	cout << priority;
}

//Print function is used to print all the elements of the STACK
void node::print() const
{
	cout << data;
}