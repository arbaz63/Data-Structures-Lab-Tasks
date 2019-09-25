//This program is a main for list.cpp and node.cpp

#include "list.cpp"
#include <iostream>


using namespace std;

int main()
{
	//Declared an object of list type
	list linkList;
	//inserting nodes in the link list
	linkList.insert(100);
	linkList.insert(150);
	linkList.insert(200);
	linkList.insert(1000);
	cout << "Now my Link List is" << endl;
	linkList.print();
	//inserting a node having value of 50 at the start of the Link List
	linkList.insertAtBegin(50);
	cout << "/nNow after adding 50 at the beginning my Link List is" << endl;
	linkList.print();
	//inserting a node having value of 5 at the start of the Link List
	linkList.insertAtBegin(5);
	cout << "/nNow after adding 5 at the beginning my Link List is" << endl;
	linkList.print();
	//inserting a node having value of 1100 at the end of the Link List
	linkList.insertAtEnd(1100);
	cout << "/nNow after adding 50 at the end my Link List is" << endl;
	linkList.print();
	//Updated a node having value of 200 at the 5th index in the list by new value 201
	linkList.updateValueByIndex(201, 5);
	//Printing the list after updation
	cout << "/nNow after Updating a node having value of 200 at the 5th index in the list by new value 201 my Link List is" << endl;
	linkList.print();
}