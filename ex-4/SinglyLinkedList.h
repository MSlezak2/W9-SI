#pragma once

class SinglyLinkedList {
public:
	SinglyLinkedList();
	int getHead();
	int getLength();
	SinglyLinkedList getTail();
	void append(int newNumber);
	void insert(int index, int newNumber);
	void displayAll();

private:
	struct Node { // This structure is named "myDataType"
		int data;
		Node* nextNode;
	};
	int length;
	Node* head;
	Node* last;

	Node* createNewNode(int newNumber);
	Node* iterate(Node* currentNode);
};
