#include <iostream>
#include "Stack.h"
#include <ctime>

using namespace std;

int main()
{
	Stack stack;

	cout << stack.getCount();

	stack.push(5);

	cout << stack.getCount();

}
