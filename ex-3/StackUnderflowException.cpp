#include "StackUnderflowException.h"

StackUnderflowException::StackUnderflowException() {
    errorMessage = "Stack underflow!";
}

const char* StackUnderflowException::what() const {
    return errorMessage.c_str();
}
