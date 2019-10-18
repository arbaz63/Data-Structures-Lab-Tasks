
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

	//function to insert a value at certain index
	void insertByPosition(int value, int position) {
		start();
		if (position <= size) {
			for (int i = 0; i < position - 2; i++) {
				move();
			}
			insert(value);
		}
		else {
			cout << "The position " << position << " is not available in Link list. Node is inserted at the end" << endl;
			insertAtEnd(value);
		}
	}


	void insertAfterValue(int value, int valueOfNodeAfter) {
		start();
		for (int i = 0; i < size; i++) {
			if (currentNode->getValue() == valueOfNodeAfter) {
				insert(value);
				break;
			}
			move();
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

	//Function to get Value of Last current Node
	int getLast() {
		return lastCurrentNode->getValue();
	}

	//Function to move at the start of the Link List
	void start() {
		lastCurrentNode = 0;
		currentNode = headNode;
	}

	void end() {
		start();
		for (int i = 0; i < size; ++i) {
			move();
		}
	}


	//Function to move to next Node
	void move() {
		if (currentNode->getNextNode() != 0) {
			lastCurrentNode = currentNode;
			currentNode = currentNode->getNextNode();
		}
	}


	void moveReverse() {
		end();
		if (currentNode == headNode) {
			currentNode = lastCurrentNode;

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
				cout << get() <<" ";
				if (i < (size - 1)) {
					move();
				}
			}
			cout << endl;
		}
	}

	//Function to delete a node from list

	void deleteNode(int valueOfNode) {

		start();

		for (int i = 0; i < size; i++) {

			if (currentNode->getValue() == valueOfNode) {

				if (currentNode->getNextNode() != NULL) {

					if (currentNode == headNode) {

						if (size == 1) {
							headNode = NULL;
							delete currentNode;
							currentNode = headNode;
							lastCurrentNode = 0;
							break;
						}
						else {
							node *ptr;
							ptr = currentNode;
							currentNode = currentNode->getNextNode();
							headNode = currentNode;
							delete ptr;
							break;
						}
					}
					else {
						lastCurrentNode->setNextNode(currentNode->getNextNode());
						delete currentNode;
						currentNode = lastCurrentNode;
						break;
					}
				}
				else {
					lastCurrentNode->setNextNode(0);
					delete currentNode;
					currentNode = lastCurrentNode;
					break;
				}
			}

			move();
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
	




};
