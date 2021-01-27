<<<<<<< HEAD
﻿#include <iostream>
#include "Stack.h"
#include <ctime>

using namespace std;

int main()
{
	Stack stack;

	cout << stack.getCount();

	stack.push(5);

	cout << stack.getCount();

=======
#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

void Try(int connect)
{
	if (connect == 1)
		throw exception("404");
	else if (connect == 2)
		throw exception("500");
	else
		cout << "tried\n";
}

int main()
{
	srand(unsigned(time(NULL)));

	int connect = rand() % 5 + 1;

	try
	{
		Try(connect);
	}
	catch (const exception &ex)
	{
		cout << ex.what() << endl;
	}

	

	return 0;
>>>>>>> ff420cb009ae6e5cfa9d05dcf091f399675d829a
}
