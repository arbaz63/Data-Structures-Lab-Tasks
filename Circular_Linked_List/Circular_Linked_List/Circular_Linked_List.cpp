//Added node.cpp file
#include "cNode.cpp"
#include <iostream>

using namespace std;

//Declared class list in which we defined methods we want to implement on Link List
class list {

	//Pointer which has the address of top 
	node *headNode;

	//pointer which points to the current Node
	node *currentNode;


	//To keep record of size of Link List
	int size;

public:

	//Default Constructor which Sets all pointers to NULL and size to zero
	list() {
		headNode = NULL;
		currentNode = NULL;
		size = 0;
	}

	//Function to insert a new node in the link list
	void insert(int number) {

		node *temp = new node();
		if (currentNode != NULL)//checking if the list is not empty
		{
			temp->setNextNode(currentNode->getNextNode());
			temp->setPreviousNode(currentNode);
			(currentNode->getNextNode())->setPreviousNode(temp);
			currentNode->setNextNode(temp); 
			currentNode = temp;
		}
		else {
			//if list is empty
			temp->setPreviousNode(temp);
			temp->setNextNode(temp);
			headNode = temp;
			currentNode = headNode;
		}
		currentNode->setValue(number);
		size++;
	}

	//function to insert a value at certain index
	void insertByPosition(int value, int position) {
		start();//moving to start of list
		if (position <= size) {
			for (int i = 0; i < position - 2; i++) {
				move();//moving to the next node in the list
			}
			insert(value); //inserting the value
		}
		else {
			cout << "The position " << position << " is not available in Link list. Node is inserted at the end" << endl;
			insertAtEnd(value);
		}
	}

	//Inserting a node after a value
	void insertAfterValue(int value, int valueOfNodeAfter) {
		start();//moving to start of list
		for (int i = 0; i < size; i++) {
			if (currentNode->getValue() == valueOfNodeAfter) {
				insert(value); //inserting the value at found position
				break;
			}
			move();//moving to the next node in the list
		}
	}

	//Function to insert a new node at the start of Link List
	void insertAtBegin(int number) {

		start();//moving to start of list
		if (headNode == NULL) {
			insert(number);//inserting the value at found position
		}
		else {
			node *temp = new node();
			temp->setPreviousNode(headNode->getPreviousNode());
			temp->setNextNode(headNode);
			headNode->setPreviousNode(temp);
			currentNode = temp;
			headNode = temp;
			currentNode->setValue(number);
			size++;
		}
	}

	//Function to insert a new node at the end of Link List
	void insertAtEnd(int number) {
		end();
		node *temp = new node();
		temp->setNextNode(currentNode->getNextNode());
		currentNode->setNextNode(temp);
		temp->setPreviousNode(currentNode);
		currentNode = temp;
		currentNode->setValue(number);
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

	//Function to update value of a node by using previous value of that node
	void updateValue(int newValue, int previousValue) {
		start();
		for (int i = 0; i < size; i++) {
			if (currentNode->getValue() == previousValue) {
				currentNode->setValue(newValue);
				break;
			}
			move();
		}
	}

	//Function to get size of Link List
	int getSize() {
		return size;
	}

	//Function to get value of a specific node
	int get() {
		return currentNode->getValue();
	}



	//Function to move at the start of the Link List
	void start() {
		currentNode = headNode;
	}

	void end() {
		start();
		for (int i = 0; i < size; i++) {
			if (i < (size - 1)) {
				move();
			}
		}
	}

	//Function to move to next Node
	void move() {
		if (currentNode->getNextNode() != 0) {
			currentNode = currentNode->getNextNode();
		}
	}

	//moving  a node back in the list
	void moveReverse() {
		if (currentNode->getPreviousNode() != 0) {
			currentNode = currentNode->getPreviousNode();
		}
	}

	//Function to print all the Nodes in the Link List
	void print() {
		if (headNode == NULL) {
			cout << "/nLink List is empty/n";
		}
		else {
			start();
			for (int i = 0; i < size; i++) {
				cout << get() << " ";
				if (i < (size - 1)) {
					move();
				}
			}
		}
		cout << endl << endl;
	}

	//Printing the list in reverse order
	void printReverse() {
		if (headNode == NULL) {
			cout << "/nLink List is empty/n";
		}
		else {
			start();
			end();
			for (int i = size; i > 0; i--) {
				cout << get() << " ";
				if (i > 1) {
					moveReverse();
				}
			}
		}
	}

	//Function to delete a node from list

	void deleteNode(int valueOfNode) {

		start();

		for (int i = 0; i < size; i++) {

			if (currentNode->getValue() == valueOfNode) {//if the value is found which is to be deleted

					if (currentNode == headNode) {//if the node to be deleted is head node

						if (size == 1) { //if there is only one element in list
							headNode = NULL;
							delete currentNode;
							currentNode = headNode;
							headNode->setNextNode(0);
							headNode->setPreviousNode(0);
							break;
						}
						else {//if there is not only one element in list
							headNode = currentNode->getNextNode();
							headNode->setPreviousNode(currentNode->getPreviousNode());
							currentNode->setPreviousNode(0);
							currentNode->setNextNode(0);
							delete currentNode;
							currentNode = headNode;
							break;
						}
					}
					else { //deleting a node in between of two nodes
						node *ptr;
						ptr = currentNode;
						(currentNode->getPreviousNode())->setNextNode(currentNode->getNextNode());
						currentNode = currentNode->getPreviousNode();
						(currentNode->getNextNode())->setPreviousNode(currentNode);
						delete ptr;
						break;
					}
			}

			move();
		}
		size--;
	}

	//deleting a node by position
	void deleteNodeByPosition(int index) {

		start();

		for (int i = 1; i < index; i++) {
			move();
		}
	

			if (currentNode == headNode) {

				if (size == 1) {
					headNode = NULL;
					delete currentNode;
					headNode->setNextNode(0);
					headNode->setPreviousNode(0);
					currentNode = headNode;
				}
				else {
					headNode = currentNode->getNextNode();
					headNode->setPreviousNode(currentNode->getNextNode());
					currentNode->setPreviousNode(0);
					currentNode->setNextNode(0);
					delete currentNode;
					currentNode = headNode;
				}
			}
			else {
				node *ptr;
				ptr = currentNode;
				(currentNode->getPreviousNode())->setNextNode(currentNode->getNextNode());
				currentNode = currentNode->getPreviousNode();
				(currentNode->getNextNode())->setPreviousNode(currentNode);
				delete ptr;
			}
		

		size--;
	}
	//Printing the sum of all the values in linklist

	int sumValue() {
		int sum = 0;
		start();
		for (int i = 0; i < size; i++) {
			sum += currentNode->getValue();
			move();
		}
		return sum;
	}

	//Searching a value if it is present in the list
	void searchValue(int value) {
		start();
		bool flag = false;
		int index = 0;
		for (int i = 0; i < size; i++) {
			if (currentNode->getValue() == value) {
				flag = true;
				index = i;
			}
			move();
		}
		if (flag == true) {
			cout << "The value is present in the link list at index " << index << endl;
		}
		else {
			cout << "The value is not present in the link list" << endl;
		}
	}

	//Sorting of list in ascending order
	void ascendingSort() {
		start();
		node* ptr;
		for (int i = 0; i < size; ++i) {
			ptr = currentNode->getNextNode();
			for (int j = i + 1; j < size; ++j) {
				if (currentNode->getValue() < ptr->getValue()) {

					int temp;
					temp = currentNode->getValue();
					currentNode->setValue(ptr->getValue());
					ptr->setValue(temp);
				}
				ptr = ptr->getNextNode();
			}
			move();
		}
	}

	//sorting of list in descending order
	void descendingSort() {
		start();
		node* ptr;
		for (int i = 0; i < size; ++i) {
			ptr = currentNode->getNextNode();
			for (int j = i + 1; j < size; ++j) {
				if (currentNode->getValue() > ptr->getValue()) {

					int temp;
					temp = currentNode->getValue();
					currentNode->setValue(ptr->getValue());
					ptr->setValue(temp);
				}
				ptr = ptr->getNextNode();
			}
			move();
		}
	}

	// Destructor
	~list()
	{
		for (int i = 0; i < size; i++)
		{
			node* newNode = new node();
			newNode = currentNode;
			delete newNode;
			move();
		}
	}
};