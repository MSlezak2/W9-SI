#include <iostream>
#include "Stack.h"
#include "StackOverflowException.h"
#include "StackUnderflowException.h"

int main() {

	Stack stack(5);


	
	try {
		stack.push(1);
		stack.push(2);
		stack.push(3);
		stack.push(4);
		stack.push(5);
		stack.push(6);
	} catch (const StackOverflowException& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << stack.peek() << std::endl;
		std::cout << stack.pop() << std::endl;
		std::cout << stack.pop() << std::endl;
		std::cout << stack.pop() << std::endl;
		std::cout << stack.pop() << std::endl;
		std::cout << stack.pop() << std::endl;
		std::cout << stack.pop() << std::endl;
		std::cout << stack.peek() << std::endl;
	} catch (const StackUnderflowException& e) {
		std::cout << e.what() << std::endl;
	}
	
}