#include "SinglyLinkedList.h"
#include <iostream>

SinglyLinkedList::SinglyLinkedList() {
	head = nullptr;
	last = nullptr;
	length = 0;
}

SinglyLinkedList::~SinglyLinkedList() {
	/*Node* currentNode;
	Node* nextNode = head;

	for (int i = 0; i < length - 1; i++) {
		currentNode = nextNode;
		nextNode = iterate(nextNode);
		delete currentNode;
	}*/
	////TODO: The problem is that destructor is being invoked in getTail() method
	// Should I change that method so it returns pointer to List ("new" etc.) or 
	// is there another, better solution?
}

int SinglyLinkedList::getHead() {
	// TODO: Handle situation when list is empty (exception or sth)
	return head->data;
}

int SinglyLinkedList::getLength() {
	return length;
}

SinglyLinkedList SinglyLinkedList::getTail() {
	SinglyLinkedList tail;
	Node* currentNode = head;

	for (int i = 0; i < length - 1; i++) {
		currentNode = iterate(currentNode);
		tail.append(currentNode->data);
	}

	return tail;
}

void SinglyLinkedList::append(int newNumber) {
	Node* newNodePtr = createNewNode(newNumber);

	if (last != nullptr) { // if list is not empty, it means we should update the last element's pointer
		last->nextNode = newNodePtr;
	} else { // if it is, the new element becomes the head of the list
		head = newNodePtr;
	}
	last = newNodePtr;

	length++;
}

void SinglyLinkedList::insert(int index, int newNumber) {
	if (index >= 0 && index <= length) {
		
		Node* newNodePtr = createNewNode(newNumber);

		if (index == 0) { // insert at the beginning
			newNodePtr->nextNode = head;
			head = newNodePtr;
			if (length == 0) {
				last = newNodePtr;
			}
		} else if (index == length) { // insert at the end 
			last->nextNode = newNodePtr;
			last = newNodePtr;
		} else { // insert in the middle
			Node* currentNode = head;
			Node* previousNode;
			for (int i = 0; i < index - 1; i++) {
				currentNode = iterate(currentNode);
			}
			previousNode = currentNode;
			currentNode = iterate(currentNode);
			newNodePtr->nextNode = currentNode;
			previousNode->nextNode = newNodePtr;
		}

		length++;
	} else {
		//TODO: Maybe throw exception or sth?
		std::cout << "Index is out of bounds" << std::endl;
	}
}

void SinglyLinkedList::remove(int index) {
	if (index >= 0 && index < length) {
		if (index == 0 && index == length - 1) { // remove the only element
			delete head;
			head = nullptr;
			last = nullptr;
		} else if (index == 0) { // remove from the beginning
			Node* nextNode = head->nextNode;
			delete head;
			head = nextNode;
		} else if (index == length - 1) { // remove from the end 
			delete last;
			Node* currentNode = head;
			for (int i = 0; i < length - 2; i++) {
				currentNode = iterate(currentNode);
			}
			last = currentNode;
			last->nextNode = nullptr;
		} else { // remove from the middle
			Node* currentNode = head;
			Node* previousNode; 
			Node* nextNode;
			for (int i = 0; i < index - 1; i++) {
				currentNode = iterate(currentNode);
			}
			previousNode = currentNode;
			currentNode = iterate(currentNode);
			nextNode = iterate(currentNode);
			delete currentNode;
			previousNode->nextNode = nextNode; 
		}

		length--;
	} else {
		std::cout << "Index is out of bounds" << std::endl;
	}
}

void SinglyLinkedList::displayAll() {
	if (length > 0) {
		Node* currentNode = head;
		std::cout << currentNode->data << std::endl;
		while (currentNode->nextNode != nullptr) {
			currentNode = currentNode->nextNode;
			std::cout << currentNode->data << std::endl;
		}
	} else {
		std::cout << "The list is empty" << std::endl;
	}
}

SinglyLinkedList::Node* SinglyLinkedList::createNewNode(int newNumber) {
	Node* newNodePtr = new Node();
	newNodePtr->data = newNumber;
	newNodePtr->nextNode = nullptr;

	return newNodePtr;
}

SinglyLinkedList::Node* SinglyLinkedList::iterate(Node* currentNode) {
	Node* nextNode = nullptr;

	if (currentNode->nextNode != nullptr) {
		nextNode = currentNode->nextNode;
	} else {
		std::cout << "There are no elements (nodes) left" << std::endl;
	}

	return nextNode;
}
