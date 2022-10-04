#pragma once
#include <stdexcept>

class StackUnderflowException : public std::exception {
public:
	StackUnderflowException();
	virtual const char* what() const override;

private:
	std::string errorMessage;
};

