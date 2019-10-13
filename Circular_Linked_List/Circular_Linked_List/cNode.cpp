
#include <iostream>

using namespace std;

//Declaring a node class
class node {

	//Declaring private data members
	int value;
	node *nextNode;
	node *previousNode;
public:


	node() {
		nextNode = NULL;
		previousNode = NULL;
		value = 0;	
	}

	void setPreviousNode(node *pNode) {
		previousNode = pNode;
	}
	node * getPreviousNode() {
		return previousNode;
	}

	//declaring a function which sets the value in the node
	void setValue(int v) {
		value = v;
	}

	//Function used to move to next Node
	void setNextNode(node *nn) {
		nextNode = nn;
	}

	//Declared a function which returns the value stored in a node
	int getValue() {
		return value;
	}

	//Getting nextNode
	node *getNextNode() {
		return nextNode;
	}
};