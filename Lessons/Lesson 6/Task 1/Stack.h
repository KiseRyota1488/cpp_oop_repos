#pragma once
class Stack
{
	static const int MAX_SIZE = 10;

	enum { EMPTY = -1 };

	int stack[MAX_SIZE];

	int top = EMPTY;

public:
	

	void push(int);

	bool pop(int&);

	void clear();

	bool isEmpty() const;

	bool isFull() const;

	int getCount() const;

};

