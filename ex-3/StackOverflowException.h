#pragma once
#include <stdexcept>

class StackOverflowException : public std::exception {
public:
	StackOverflowException(int maxSize);
	virtual const char* what() const override;

private:
	std::string errorMessage;
};

