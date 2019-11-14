#include <iostream>
#include "queue.h"
using namespace std;

int main() {
	queue que;

	//checking front and rear when queue is empty
	cout << que.getFront() << endl;
	cout << que.getRear() << endl;

	//inserting nodes in the queue
	node* node1 = new node();
	node1->setData(100);
	que.enqueue(node1);
	cout << "Now declaring a node and setting data using setData fuction\n";
	que.print();
	node* node2 = new node();
	node2->setData(200);
	que.enqueue(node2);
	node* node3 = new node();
	node3->setData(300);
	que.enqueue(node3);

	//Printing all the elements in the queue
	que.print();
	que.dequeue();
	cout << que.getFront() << endl;
	cout << que.getRear() << endl;

	system("pause");
}