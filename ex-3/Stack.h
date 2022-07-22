#pragma once
class Stack {
public:
	Stack(int maxSize);
	~Stack();
	void push(int newElement);
	int pop();
	int peek();
	int getCurrentSize();
	int getSpaceLeft();

private:
	int* stack;
	int maxSize;
	int currentSize;
	//TODO: Throw exceptions: 'stack overflow' and 'stack underflow'
};

