#pragma once
class node
{
	int data;
	node* nextNode;
public:

	node();	//default constructor
	node(int d); //parameterized constructor//Function to set data in the node of a STACK
	node& setData(int number);	//Function to set data in the node
	int getData();	//Function to get data of a node
	void setNextNode(node* ptr); //Function to set next node
	node* getNextNode(); //Function to get node
	void print() const; //Function to print data of a node
};

