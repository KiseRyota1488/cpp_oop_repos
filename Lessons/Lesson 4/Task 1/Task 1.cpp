#include <iostream>

using namespace std;

class Wheicle
{
public:

	virtual void Drive() = 0;
	void DriveL()
	{
		cout << "123";
	}
};

class Car : public Wheicle
{
public:
	void Drive() override
	{
		cout << "1";
	}
};

class Driver
{
public:
	void Driver1(Car &car)
	{
		car.Drive();
		car.DriveL();
		cout << "123";
	}
};

int main()
{
	Car car;
	Driver dr;

	dr.Driver1(car);

	return 0;
}
