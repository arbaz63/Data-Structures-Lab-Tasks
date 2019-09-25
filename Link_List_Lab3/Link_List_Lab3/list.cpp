//This Program contains the list class. We declared insert, insert at end, insert at beginning, update value by index,
//update value by using previous value and print the link list

//Added node.cpp file
#include "node.cpp"
#include <iostream>

using namespace std;

//Declared class list in which we defined methods we want to implement on Link List
class list {

	//Pointer which has the address of top 
	node *headNode;

	//pointer which points to the current Node
	node *currentNode;

	//pointer which points to the Last Current Node
	node *lastCurrentNode;

	//To keep record of size of Link List
	int size;

public:

	//Default Constructor which Sets all pointers to NULL and size to zero
	list() {
		headNode = NULL;
		currentNode = NULL;
		lastCurrentNode = NULL;
		size = 0;
	}

	//Function to insert a new node in the link list
	void insert(int number) {
		if (currentNode != NULL)
		{
			if (currentNode->getNextNode() == 0) {
				node *temp = new node();
				currentNode->setNextNode(temp);
				lastCurrentNode = currentNode;
				currentNode = temp;
				currentNode->setValue(number);
				currentNode->setNextNode(0);
				size++;
			}
			else {
				node *temp = new node();
				temp->setNextNode(currentNode->getNextNode());
				currentNode->setNextNode(temp);
				lastCurrentNode = currentNode;
				currentNode = temp;
				currentNode->setValue(number);
				size++;

			}
		}
		else {
			node *temp = new node();
			headNode = temp;
			currentNode = headNode;
			lastCurrentNode = 0;
			currentNode->setValue(number);
			currentNode->setNextNode(0);
			size++;
		}
	}

	//Function to insert a new node at the start of Link List
	void insertAtBegin(int number) {

		start();
		node *temp = new node();
		temp->setNextNode(currentNode);
		currentNode = temp;
		headNode = temp;
		currentNode->setValue(number);
		lastCurrentNode = 0;
		size++;
	}

	//Function to insert a new node at the end of Link List
	void insertAtEnd(int number) {
		start();
		for (int i = 0; i < size; i++) {
			move();
		}
		node *temp = new node();
		currentNode->setNextNode(temp);
		lastCurrentNode = currentNode;
		currentNode = temp;
		currentNode->setValue(number);
		currentNode->setNextNode(0);
		size++;

	}

	//Function to update value of a node by using index of that node
	void updateValueByIndex(int newValue, int index) {
		start();
		for (int i = 0; i < index - 1; i++) {
			move();
		}
		currentNode->setValue(newValue);
	}


	//Function to get size of Link List
	int getSize() {
		return size;
	}

	//Function to get value of a specific node
	int get() {
		return currentNode->getValue();
	}

	//Function to get Value of Last current Node
	int getLast() {
		return lastCurrentNode->getValue();
	}

	//Function to move at the start of the Link List
	void start() {
		lastCurrentNode = 0;
		currentNode = headNode;
	}


	//Function to move to next Node
	void move() {
		if (currentNode->getNextNode() != 0) {
			lastCurrentNode = currentNode;
			currentNode = currentNode->getNextNode();
		}
	}

	//Function to print all the Nodes in the Link List
	void print() {
		start();
		for (int i = 0; i < size; i++) {
			cout << get() << endl;
			move();
		}
	}
};