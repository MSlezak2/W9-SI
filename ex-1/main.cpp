#include <iostream>

int fibonacciNumberIterative(int n);
bool testFibonacciNumberIterative();

int main() {

	std::cout << std::endl << "Iterative approach:\t" << testFibonacciNumberIterative() 
		<< "\tO(n)" << std::endl;

	return 0;
}

int fibonacciNumberIterative(int n) {

	int noAdditionOperations = 0;
	int previousNumber = 0;
	int currentNumber = 1;
	int nextNumber;

	if (n == 0) {
		nextNumber = 0;
	} else if (n == 1) {
		nextNumber = 1;
	} else {
		for (int i = 2; i <= n; i++) {
			nextNumber = previousNumber + currentNumber;
			previousNumber = currentNumber;
			currentNumber = nextNumber;
			noAdditionOperations++;
		}
	}

	std::cout << "n: " << n << "\tNumber of addition operations: " << noAdditionOperations << std::endl;

	return nextNumber;
}

bool testFibonacciNumberIterative() {

	bool testResult = 
		0 == fibonacciNumberIterative(0) &&
		1 == fibonacciNumberIterative(1) &&
		1 == fibonacciNumberIterative(2) &&
		2 == fibonacciNumberIterative(3) &&
		3 == fibonacciNumberIterative(4) &&
		5 == fibonacciNumberIterative(5) &&
		8 == fibonacciNumberIterative(6) &&
		13 == fibonacciNumberIterative(7) &&
		21 == fibonacciNumberIterative(8) &&
		34 == fibonacciNumberIterative(9) &&
		55 == fibonacciNumberIterative(10);

	return testResult;
}
