#include "SinglyLinkedList.h"
#include <iostream>

//void test() {
//	SinglyLinkedList list;
//
//	list.displayAll();
//	//list.insert(1, 9);
//	//list.insert(0, 7);
//	list.append(1);
//}

int main() {

	//test();

	SinglyLinkedList list = SinglyLinkedList();

	list.displayAll();
	//list.insert(1, 9);
	//list.insert(0, 7);
	list.append(1);
	list.append(2);
	list.append(3);
	list.append(4);
	list.append(5);
	//list.insert(1,8);
	//list.insert(5, 9);
	list.remove(1);
	list.displayAll();

	SinglyLinkedList tail = list.getTail();
	std::cout << std::endl;
	tail.displayAll();

	return 0;
}