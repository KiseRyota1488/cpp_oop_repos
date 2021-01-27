#include "List.h"

List::List()
{
	pHead = pTail = NULL;
}

List::~List()
{
	//Clear();
}

void List::Print() const
{
	Node* temp = pHead;

	while (temp != NULL)
	{
		cout << temp->value << "\t";
		temp = temp->pNext;
	}
	cout << endl;
}

void List::addToHead(const int& value)
{
	Node* forAdd = new Node;

	forAdd->value = value;
	forAdd->pNext = pHead;

	if (pHead != NULL)
		pHead = forAdd;
	else
		pHead = pTail = forAdd;

}

void List::delFromTail()
{
	Node* temp = pHead;
	Node* del_temp = pTail;

	if (pHead != NULL)
	{
		while (temp->pNext != pTail)
			temp = temp->pNext;

		temp->pNext = NULL;
		pTail = temp;
	}
	else
		cout << "error";

	delete del_temp;
}

void List::delByIndex(int index)
{
	Node* temp = pHead; // 1 4 5 6  | 1 5 5 6 | 1 5 6
	int i = 0, value, b;

	while (temp != pTail)
	{
		if (i == index)
			break;
		temp = temp->pNext;
		i++;
	}// другий елемент, попередній

	while (temp != pTail)
	{
		temp = temp->pNext;
	}

	pTail = temp;
	pTail->pNext = NULL;


}



