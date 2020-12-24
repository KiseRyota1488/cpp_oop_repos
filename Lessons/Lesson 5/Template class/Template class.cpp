#include <iostream>

using namespace std;

class Cat {
private:
	string name;
	string breed;
	int age = 0;
public:
	Cat(string name, string breed, int age) {
		this->name = name;
		this->breed = breed;
		this->age = age;
	};
	Cat() {}
	void Print() {
		cout << "Name: " << this->name << "\nBreed: " << this->breed << "\nAge: " << this->age << endl;
	}
};

class Dog {
private:
	string name;
	string breed;
	int age = 0;
public:
	Dog(string name, string breed, int age) {
		this->name = name;
		this->breed = breed;
		this->age = age;
	};
	Dog() {}
	void Print() {
		cout << "Name: " << this->name << "\nBreed: " << this->breed << "\nAge: " << this->age << endl;
	}
};

template<typename T, typename T2>
class Animal {
private:
	T animal;
	T2 animal2;
public:
	Animal(T animal, T2 animal2) {
		this->animal = animal;
		this->animal2 = animal2;
	}

	void ShowAnimal() {
		this->animal.Print();
		this->animal2.Print();
	}
};

int main() {

	Cat cat("Murzik", "GoodBreed", 5);
	Dog dog("Bobik", "Labrador", 2);

	Animal<Cat, Dog> animal(cat, dog);

	animal.ShowAnimal();

	system("pause");
	return 0;
}