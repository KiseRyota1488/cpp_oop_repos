#include <iostream>
#include <vector>
#include <sstream>
#include "windows.h"

using namespace std;

//Створити для класу Авто власні класи виключень WrongSpeedException, WrongMaxSpeedException та InvalidNumberException, які інкапсулюють у собі невірне дане та повідомлення про помилку.
//
//
//
//Клас Auto повинен викидати виключення типу WrongMaxSpeedException при встановленні максимальної швидкості більше 360
//
//Клас Auto повинен викидати виключення типу WrongSpeedException при встановленні чи досягненні швидкості, яка перевищує максимальну
//
//Клас повинен викидати виключення типу InvalidNumberException при встановленні невірного номера авто
//
//Створити програму для перевірки роботи виключних ситуацій класу Auto.

class Auto
{
private:
	int speed;
	string carNumber;
	int speedIncrement;
public:
	Auto(int speed, string carNumber, int speedIncrement = 5)
	{
		this->speed = speed;
		this->carNumber = carNumber;
		this->speedIncrement = speedIncrement;
	}

	void Print()
	{
		cout << speed << carNumber << speedIncrement;
	}

	int GetSpeed()
	{
		return speed;
	}

	string GetCarNumber()
	{
		return carNumber;
	}

	int GetSpeedInc()
	{
		return speedIncrement;
	}
};

bool CorrectCarNumber(const string);

int main()
{
	int speed;
	string carNumber;
	bool choose;


	cout << " --- Create car ---\n";
	cout << "Enter speed: ";
	cin >> speed;
	do {
		cout << "Enter car number: ";
		cin >> carNumber;

		if (!CorrectCarNumber(carNumber))
		{
			cout << "Car number is incorrect! Try again!\n";
			system("PAUSE");
			system("cls");
		}
		else
			cout << "Car number is correct!\n";
	} while (!CorrectCarNumber(carNumber));

	Auto car(speed, carNumber);
	

	system("cls");

	while(1)
	{
		cout << "Car info: \nCurrent speed: " << car.GetSpeed() << "\nSpeed increment: " << car.GetSpeedInc() << "\nCar number: "<<car.GetCarNumber() << "\n";
		Sleep(5000);
	}

}

bool CorrectCarNumber(const string carNumber)
{
	if (carNumber.size() == 8)
		for (int i = 0; i < carNumber.size(); i++)
		{
			if (i < 2 && i >= 6)
			{
				int temp = carNumber[i];
				if (!((temp >= 65 && temp <= 90) || (temp >= 97 && temp <= 122)))
				{
					return 0;
				}
			}
			else
			{

				int temp = carNumber[i];
				if (!(temp >= 48 && temp <= 57))
				{
					return 1;
				}
			}
		}
	else
		return 0;

	return 1;
}
