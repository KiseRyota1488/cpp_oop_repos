#pragma once

class Queue
{
	int* queue;
	int maxLength;
	int queueLength;

public:

	Queue(int max);
	~Queue();

	void Add(int el);
	int Extract();

	bool isFull() const;
	bool isEmpty() const;
	int getCount() const;
	void Clear();
	void Show() const;


};