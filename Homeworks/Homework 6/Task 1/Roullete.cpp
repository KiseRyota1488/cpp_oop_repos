#include "Roullete.h"

Roullete::Roullete(int max)
{
	maxLength = max;
	roullete = new int[maxLength];
	roulleteLength = 0;
}

Roullete::~Roullete()
{
	delete[] roullete;
}

void Roullete::Add(int el)
{
	if (!isFull())
	{
		roullete[roulleteLength++] = el;
	}
}

int Roullete::Extract()
{
	if (!isEmpty())
	{
		int temp = roullete[0];
		for (int i = 1; i < roulleteLength; i++)
		{
			roullete[i - 1] = roullete[i];
		}
		roullete[roulleteLength - 1] = temp;

		return temp;
	}

	return INT_MIN;
}

bool Roullete::isFull() const
{
	return roulleteLength == maxLength;
}

bool Roullete::isEmpty() const
{
	return roulleteLength == 0;
}

int Roullete::GetCount() const
{
	return roulleteLength;
}

int Roullete::GetById(int id) const
{
	return roullete[id];
}

void Roullete::Clear()
{
	roulleteLength = 0;
}

void Roullete::Show() const
{
	for (int i = 0; i < roulleteLength; i++)
	{
		cout << roullete[i] << " ";
	}

}

