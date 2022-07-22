#pragma once

class SinglyLinkedList {
public:
	SinglyLinkedList();
	~SinglyLinkedList();
	int getHead();
	int getLength();
	SinglyLinkedList getTail();
	void append(int newNumber);
	void insert(int index, int newNumber);
	void remove(int index);
	void displayAll();

private:
	struct Node {
		int data;
		Node* nextNode;
	};
	int length;
	Node* head;
	Node* last;

	Node* createNewNode(int newNumber);
	Node* iterate(Node* currentNode);
};

