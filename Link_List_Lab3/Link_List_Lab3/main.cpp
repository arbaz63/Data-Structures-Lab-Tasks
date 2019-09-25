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
	//inserting a node having value of 1100 at the end of the Link List
	linkList.insertAtEnd(1100);
	cout << "/nNow after adding 50 at the end my Link List is" << endl;
	linkList.print();
}