//This program is a main for list.cpp and node.cpp

#include "Circular_Linked_List.cpp"
#include <iostream>

using namespace std;

int main()
{
	//Declared an object of list type
	list linkList;

	//inserting nodes in the link list
	linkList.insert(60);
	linkList.insert(70);
	linkList.insert(80);
	linkList.insert(90);
	cout << "\nNow my Link List is" << endl;
	linkList.print();
	cout << "\nThe size of the list is " << linkList.getSize() << endl;
	cout << "\nPrinting the linkList Backword\n";
	linkList.printReverse();
	cout << "\nThe size of the list is " << linkList.getSize() << endl;
	//inserting a node having value of 50 at the start of the Link List
	linkList.insertAtBegin(50);
	
	cout << "\nNow after adding 50 at the beginning my Link List is" << endl;
	linkList.print();
	cout << "\nThe size of the list is " << linkList.getSize() << endl;
	//inserting a node having value of 40 at the start of the Link List
	linkList.insertAtBegin(40);
	cout << "\nNow after adding 40 at the beginning my Link List is" << endl;
	linkList.print();
	cout << "\nThe size of the list is " << linkList.getSize() << endl;
	//inserting a node having value of 30 at the start of the Link List
	linkList.insertAtBegin(30);
	cout << "\nNow after adding 30 at the beginning my Link List is" << endl;
	linkList.print();
	cout << "\nThe size of the list is " << linkList.getSize() << endl;
	//inserting a node having value of 100 at the end of the Link List
	linkList.insertAtEnd(100);
	cout << "\nNow after adding 100 at the end my Link List is" << endl;
	linkList.print();
	linkList.insert(110);
	linkList.insert(120);
	linkList.insert(130);
	linkList.insert(140);
	linkList.insert(150);
	cout << "\nThe size of the list is " << linkList.getSize() << endl;
	cout << "\nPrinting the linkList Backword\n";
	linkList.printReverse();

	//Updated a node having value of 70 at the 5th index in the list by new value 71/*

	linkList.updateValueByIndex(71, 5);
	cout << "\nNow after Updating a node having value of 70 at the 5th index in the list by new value 71 my Link List is" << endl;
	linkList.print();
	cout << "\nThe size of the list is " << linkList.getSize() << endl;

	//Updating a node having previous value of 80 in the list by new value 81
	linkList.updateValue(81, 80);
	cout << "Now after Updating a node having previous value of 150 in the list by new value 151 my Link List is" << endl;
	linkList.updateValue(151, 150);
	linkList.print();

	//Deleting a node from link list
	cout << "\nList after deleting a node" << endl;
	linkList.deleteNode(100);

	linkList.print();

	//Deleting first node from list
	cout << "\n";
	linkList.deleteNode(30);
	linkList.print();

	//Calculating sum of all the Values present in link list
	cout << "\nSum of values present in the list is: " << linkList.sumValue() << endl;

	//Inserting a node at given position
	cout << "After inserting a node at given position" << endl;
	linkList.insertByPosition(41, 2);
	linkList.print();

	//After inserting a node after given value  
	cout << "After inserting a node after given value" << endl;
	linkList.insertAfterValue(160, 151);
	linkList.print();

	//Deleting a node from link list
	cout << "\nList after deleting a node" << endl;
	linkList.deleteNodeByPosition(1);

	linkList.print();
	
	system("pause");
}