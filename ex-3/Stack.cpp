#include "Stack.h"
#include <iostream>
#include "StackOverflowException.h"
#include "StackUnderflowException.h"

Stack::Stack(int maxSize) {
	this->maxSize = maxSize;
	currentSize = 0;
	stack = new int[maxSize];
}

Stack::~Stack() {
	delete[] stack;
}

void Stack::push(int newElement) {
	if (currentSize < maxSize) {
		stack[currentSize] = newElement;
		currentSize++;
	} else {
		//std::cout << "Stack overflow" << std::endl;
		throw StackOverflowException(maxSize);
	}
}

int Stack::pop() {
	
	int topMostElement = -HUGE_VAL;

	if (currentSize > 0) {
		topMostElement = stack[currentSize - 1];
		stack[currentSize - 1] = 0;
		currentSize--;
	} else {
		//std::cout << "Stack underflow" << std::endl;
		throw StackUnderflowException();
	}

	return topMostElement;
}

int Stack::peek() {

	int topMostElement = -HUGE_VAL;

	if (currentSize > 0) {
		topMostElement = stack[currentSize - 1];
	} else {
		//std::cout << "Stack underflow" << std::endl;
		throw StackUnderflowException();
	}

	return topMostElement;
}

int Stack::getCurrentSize() {
	return currentSize;
}

int Stack::getMaxSize() {
	return maxSize;
}

int Stack::getSpaceLeft() {
	return maxSize - currentSize;
}
