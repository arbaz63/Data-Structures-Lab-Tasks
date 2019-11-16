#include "marking.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

//default constructor
marking::marking() :front(NULL), rear(NULL),count(0),regNo("") {}

//Function to submit an assignment
marking& marking::submitAssignment(string regNumber)
{
	node* ptr = new node();
	ptr->setName(regNumber); //setting name
	marks(ptr); //setting marks
	if (front == NULL) //if queue is empty
	{
		front = rear = ptr;
		front->setNextNode(NULL);
	}
	else //if queue is not empty
	{
		rear->setNextNode(ptr);
		rear = rear->getNextNode();
	}

	rear->setNextNode(NULL);
	ptr = NULL;
	count++;
	return *this;
}

//Function to set marks
void marking::marks(node*& ptr)
{
	if (count < 5)	ptr->setData(10);//When the students are less then five

	else if (count >4 && count <= 7) ptr->setData(7); //When a student is submitting assignment at 6th to 8th number
	else if (count > 7 && count <= 9) ptr->setData(5);//When a student is submitting assignment at 9th  to 10th number
	else //if student is submitting assignment after 10 students submitted
	{
		ptr->setData(0);
		ptr->setRemarks();
	}
}

//Function to remove a node from queue
node* marking::dequeue()
{
	node* ptr;
	ptr = front;
	if (front->getNextNode() == NULL)
	{
		rear = NULL;
	}
	front = front->getNextNode();
	ptr->setNextNode(NULL);
	return ptr;
}

//Function to check if stack is empty
bool marking::isEmpty() const {
	if (front == NULL) {//if STACK is empty returning true
		return true;
	}
	else {//if STACK is not empty returning false
		return false;
	}
}


//Function to print all the elements present in the QUEUE
void marking::print() const {
	if (isEmpty()) { //Checking if the QUEUE is empty
		cout << "There is no element." << endl;
	}
	else {
		node* ptr; //Declaring a runner pointer to move through
		ptr = front;
		cout << left << setw(25) << "Registration Number" << setw(16) << "Marks" << setw(15) << "Remarks" << endl;
		for (int i = 0; i < count; i++)
		{

			cout << left << setw(25);
			ptr->printName();
			cout << setw(16);
			ptr->print();
			cout << setw(15);
			if (i > 9) ptr->printRemarks();
			cout<< endl;
			ptr = ptr->getNextNode();
		}
		cout << "\n\n";
	}
}


