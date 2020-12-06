#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Point
{
private:
	int x, y;
public:

	int GetX()
	{
		return x;
	}
	void SetX(int x)
	{
		this->x = x;
	}
	int GetY()
	{
		return y;
	}
	void SetY(int y)
	{
		this->y = y;
	}

	void CreatePoint()
	{
		x = 0;
		y = 0;
	}

};

int main()
{
	Point firstPoint;

	firstPoint.CreatePoint();

	int tmp;

	char key;
	do {
		cout << "1. Enter point\n2. Show point\n3. Change point\n4. Exit\n->_";
		cin >> key;

		system("cls");
		switch (key)
		{
		case '1':
		{
			cout << "Enter x: ";
			cin >> tmp;
			firstPoint.SetX(tmp);

			cout << "Enter y: ";
			cin >> tmp;
			firstPoint.SetY(tmp);

			system("cls");

			break;
		}
		case '2': 
		{
			cout << "Your point: X - " << firstPoint.GetX() << " | Y - " << firstPoint.GetY()<<"\n";

			break;
		}
		case '3':
		{
			bool a;
			cout << "Choose which coord you want to change (0 - X, 1 - Y): ";
			cin >> a;
			if (a)
			{
				cout << "Enter Y: ";
				cin >> tmp;
				firstPoint.SetY(tmp);
			}
			else if (!a)
			{
				cout << "Enter X: ";
				cin >> tmp;
				firstPoint.SetX(tmp);
			}
			else
				cout << "Wrong option\n";

			break;
		}
		default:
			break;
		}
		
	} while (key != '4');

	return 0;
}