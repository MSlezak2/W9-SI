#include "SinglyLinkedList.h"

int main() {

	SinglyLinkedList list;

	list.displayAll();
	list.insert(1, 9);
	list.insert(0, 7);
	list.append(1);
	list.append(2);
	list.append(3);
	list.insert(1,8);
	list.insert(5, 9);
	list.displayAll();

	return 0;
}