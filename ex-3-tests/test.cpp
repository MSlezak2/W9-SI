#include "pch.h"
#include "../ex-3/Stack.h"
#include "../ex-3/StackOverflowException.h"
#include "../ex-3/StackUnderflowException.h"

TEST(StackConstructorTest, ConstructorAssignsTheSize) {
	Stack stack(10);
	EXPECT_EQ(10, stack.getMaxSize());
}

TEST(StackConstructorTest, StackIsInitiallyEmpty) {
	Stack stack(10);
	EXPECT_EQ(0, stack.getCurrentSize());
}

TEST(StackPushTest, PushElement) {
	Stack stack(2);
	int initialSize = stack.getCurrentSize();
	stack.push(10);
	int finalSize = stack.getCurrentSize();
	EXPECT_EQ(1, finalSize - initialSize);
	EXPECT_EQ(10, stack.peek());
}

TEST(StackPushTest, PushOneTooMuchElement) {
	Stack stack(2);
	int initialSize = stack.getCurrentSize();
	stack.push(10);
	stack.push(11);
	EXPECT_THROW(stack.push(12), StackOverflowException) << "Exception hasn't been thrown";
	int finalSize = stack.getCurrentSize();
	EXPECT_EQ(2, finalSize - initialSize) << "The size isn't right";
	EXPECT_EQ(11, stack.peek()) << "The top-most element isn't right";
}

TEST(StackPopTest, PopElement) {
	Stack stack(2);
	stack.push(10);
	stack.push(11);
	int initialSize = stack.getCurrentSize();
	int element = stack.pop();
	int finalSize = stack.getCurrentSize();
	EXPECT_EQ(1, initialSize - finalSize);
	EXPECT_EQ(11, element);
}

TEST(StackPopTest, PopFromEmptyStack) {
	Stack stack(2);
	EXPECT_THROW(stack.pop(), StackUnderflowException) << "Exception hasn't been thrown";
	EXPECT_EQ(0, stack.getCurrentSize()) << "The size isn't right";
	
}

TEST(StackPeekTest, PeekElement) {
	Stack stack(2);
	stack.push(10);
	stack.push(11);
	int initialSize = stack.getCurrentSize();
	int element = stack.peek();
	int finalSize = stack.getCurrentSize();
	EXPECT_EQ(0, initialSize - finalSize);
	EXPECT_EQ(11, element);
}

TEST(StackPeekTest, PeekFromEmptyStack) {
	Stack stack(2);
	EXPECT_THROW(stack.peek(), StackUnderflowException) << "Exception hasn't been thrown";
	EXPECT_EQ(0, stack.getCurrentSize()) << "The size isn't right";
}