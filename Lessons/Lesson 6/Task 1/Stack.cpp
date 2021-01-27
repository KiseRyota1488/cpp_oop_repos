#include "Stack.h"

void Stack::push(int el)
{
	if (!isFull())
		stack[++top] = el;
}

bool Stack::pop(int& el)
{
	if (!isEmpty())
	{
		el = stack[top--];
		return true;
	}
	return false;
}

void Stack::clear()
{
	top = EMPTY;
}

bool Stack::isEmpty() const
{
	return top + 1 == MAX_SIZE;
}

bool Stack::isFull() const
{
	return top+1 == MAX_SIZE;
}

int Stack::getCount() const
{
	return top + 1;
}
