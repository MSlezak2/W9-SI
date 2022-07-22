#include <iostream>
#include <map>

int fibonacciNumberIterative(int n, int& noAddOps);
int fibonacciNumberNaiveRecursive(int n, int& noAddOps);
int fibonacciNumberMemoizationRecursive(int n, int& noAddOps, std::map<int, int>& cache);
int fibonacciNumberTailRecursive(int n, int& noAddOps, int& acc);
bool testFibonacciNumberIterative();
bool testFibonacciNumberNaiveRecursive();
bool testFibonacciNumberMemoizationRecursive();

bool simpleTest() {
	bool isCorrect = true;
	int trash;

	if (fibonacciNumberIterative(0, trash) != 0) {
		isCorrect = false;
	}
	if (fibonacciNumberIterative(1, trash) != 1) {
		isCorrect = false;
	}
	if (fibonacciNumberIterative(5, trash) != 5) {
		isCorrect = false;
	}
	
	return isCorrect;
}

int main() {

	bool test = simpleTest();

	std::cout << std::endl << "Iterative approach:\t" << testFibonacciNumberIterative() 
		<< "\tO(n)" << std::endl << std::endl;

	std::cout << std::endl << "Naive recursive approach:\t" << testFibonacciNumberNaiveRecursive()
		<< "\tO(n^2)" << std::endl << std::endl;

	std::cout << std::endl << "Memoization recursive approach:\t" << testFibonacciNumberMemoizationRecursive()
		<< "\tO(?)" << std::endl << std::endl;

	return 0;
}

int fibonacciNumberIterative(int n, int& noAddOps) {

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
			noAddOps++;
		}
	}

	return nextNumber;
}

int fibonacciNumberNaiveRecursive(int n, int& noAddOps) {

	int number = 0;

	if (n == 0) {
		number = 0;
	} else if (n == 1) {
		number = 1;
	} else {
		number = fibonacciNumberNaiveRecursive(n - 1, noAddOps) + fibonacciNumberNaiveRecursive(n - 2, noAddOps);
		noAddOps++;
	}

	return number;
}

int fibonacciNumberMemoizationRecursive(int n, int& noAddOps, std::map<int, int>& cache) {
	
	int number = 0;

	if (n == 0) {
		number = 0;
	} else if (n == 1) {
		number = 1;
	} else {
		if (cache.find(n) != cache.end()) { // has it already been calculated?
			number = cache.at(n);
		} else {
			number = fibonacciNumberMemoizationRecursive(n - 1, noAddOps, cache) + fibonacciNumberMemoizationRecursive(n - 2, noAddOps, cache);
			cache.insert({n,number});
			noAddOps++;
		}
	}

	return number;
}

int fibonacciNumberTailRecursive(int n, int& noAddOps, int& acc) {

	if (n == 0) {
		return 0;
	} else if (n == 1) {
		return 1;
	} else {
		noAddOps++;
		return fibonacciNumberTailRecursive(n - 1, noAddOps, acc);
	}
}

bool testFibonacciNumberIterative() {

	int testInput[] = { 0,1,2,3,4,5,6,7,8,9,10,20,30 };
	int targetOutput[] = { 0,1,1,2,3,5,8,13,21,34,55,6765,832040 };
	int currentNumber;
	bool testResult = true;
	int noAdditionOps = 0;

	for (int i = 0; i < sizeof testInput / sizeof testInput[0]; i++) {
		noAdditionOps = 0;
		currentNumber = fibonacciNumberIterative(testInput[i], noAdditionOps);
		testResult = testResult && (currentNumber == targetOutput[i]);
		std::cout << "n: " << testInput[i] << "\tFibonacci number: " << currentNumber << "\tNumber of addition operations: " << noAdditionOps << std::endl;
	}

	return testResult;

}

bool testFibonacciNumberNaiveRecursive() {

	int testInput[] = { 0,1,2,3,4,5,6,7,8,9,10,20,30 };
	int targetOutput[] = { 0,1,1,2,3,5,8,13,21,34,55,6765,832040 };
	bool testResult = true;
	int noAdditionOps = 0;
	int currentNumber;

	for (int i = 0; i < sizeof testInput / sizeof testInput[0]; i++) {
		noAdditionOps = 0;
		currentNumber = fibonacciNumberNaiveRecursive(testInput[i], noAdditionOps);
		testResult = testResult && (currentNumber == targetOutput[i]);
		std::cout << "n: " << testInput[i] << "\tFibonacci number: " << currentNumber << "\tNumber of addition operations: " << noAdditionOps << std::endl;
	}

	return testResult;
}

bool testFibonacciNumberMemoizationRecursive() {

	int testInput[] = { 0,1,2,3,4,5,6,7,8,9,10,20,30 };
	int targetOutput[] = { 0,1,1,2,3,5,8,13,21,34,55,6765,832040 };
	bool testResult = true;
	int noAdditionOps = 0;
	std::map<int, int> cache;
	int currentNumber;

	for (int i = 0; i < sizeof testInput / sizeof testInput[0]; i++) {
		cache.clear();
		currentNumber = fibonacciNumberMemoizationRecursive(testInput[i], noAdditionOps, cache);
		testResult = testResult && (currentNumber == targetOutput[i]);
		std::cout << "n: " << testInput[i] << "\tFibonacci number: " << currentNumber << "\tNumber of addition operations: " << noAdditionOps << std::endl;
	}

	return testResult;
}
