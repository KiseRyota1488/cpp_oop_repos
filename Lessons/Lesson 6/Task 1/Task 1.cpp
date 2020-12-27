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
}
