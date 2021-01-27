#pragma once
#include <iostream>

using namespace std;

struct Node
{
	int value;
	Node* pNext;
};

class List
{
	Node* pHead;
	Node* pTail;

public:
	List();
	~List();

	void addToHead(const int &amp);

	void delFromTail();

	void delByIndex(int index);

	void insByIndex(int index, int value);

	void Print() const;
};

