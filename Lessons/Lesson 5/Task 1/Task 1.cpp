#include <iostream>

using namespace std;

namespace Person
{
	void Print()
	{
		cout << "Print person" << endl;
	}
}

namespace Animal
{
	void Print()
	{
		cout << "Print animal" << endl;
	}
}

using namespace Animal;
using namespace Person;

int main() 
{
	Animal::Print();
	Person::Print();
}