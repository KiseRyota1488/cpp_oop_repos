#include <iostream>

using namespace std;

class Animal
{
public:
	string name;
	int age;
	string gender;

	Animal(string name, int age, string gender)
	{
		this->name = name;
		this->age = age;
		this->gender = gender;
	}

	
};

int main()
{
	Animal cat("bar", '3', "qwe");
	cat.ShowInfo();

	return 0;
}