#include "StackOverflowException.h"
#include <string>

StackOverflowException::StackOverflowException(int maxSize) {
    errorMessage = "Stack overflow! Max capacity of the stack: ";
    errorMessage += std::to_string(maxSize);
}

const char* StackOverflowException::what() const {
    //TODO: How to do it without std::string? using C-strings only?
    return errorMessage.c_str();
}
