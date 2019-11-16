#pragma once
#include <string>
#include <iostream>
using namespace std;
class node
{
	int data;
	node* nextNode;
	string registrationNumber;
	string remarks;
public:

	node();	//default constructor
	node& setData(int number);	//Function to set data in the node
	int getData();	//Function to get data of a node
	void setNextNode(node* ptr); //Function to set next node
	node* getNextNode(); //Function to get node
	void setName(string reg);
	void setRemarks();
	void print() const; //Function to print data of a node
	void printName() const;
	void printRemarks() const;
};
