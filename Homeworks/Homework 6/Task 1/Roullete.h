
#pragma once
#include <iostream>

using namespace std;

class Roullete
{
	int* roullete;
	int maxLength;
	int roulleteLength;

public:
	Roullete(int max);
	~Roullete();

	void Add(int el);
	int Extract();

	bool isFull() const;
	bool isEmpty() const;
	int GetCount() const;
	int GetById(int id) const;

	void Clear();
	void Show() const;
};
