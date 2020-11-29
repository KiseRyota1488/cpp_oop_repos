#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
	unsigned short age;
	string name;
	string lastName;
public:
	
	unsigned short GetAge()
	{
		return age;
	}
	void SetAge(unsigned short age)
	{
		if (age > 100 || (age <= this->age && this->age != 0))
			cout << "Wrong age\n";
		else
			this->age = age;
	}
	string GetName()
	{
		return name;
	}
	void SetName(string name)
	{
		this->name = name;
	}
	string GetLastName()
	{
		return lastName;
	}
	void SetLastName(string lastName)
	{
		this->lastName = lastName;
	}
};

int main()
{
	Person firstPerson;

	firstPerson.SetName("Clown");
	firstPerson.SetLastName("Gates");
	firstPerson.SetAge(30);

	cout << firstPerson.GetName() << " " << firstPerson.GetLastName() << " " << firstPerson.GetAge();

	return 0;
}