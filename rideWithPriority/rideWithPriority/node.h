#pragma once
class node
{
	int data;
	node* nextNode;
	int priority;
public:

	node();	//default constructor
	node& setData(int number);	//Function to set data in the node
	int getData();	//Function to get data of a node
	void setNextNode(node* ptr); //Function to set next node
	node* getNextNode(); //Function to get node
	void setPriority(int p);
	int getPriority();
	void printPriority();
	void print() const; //Function to print data of a node
};