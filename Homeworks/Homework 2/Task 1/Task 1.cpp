#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

//Необхідно створити клас Monitor, який повинен містити :
//
//поля:
//технічні характеристики, роздільна здатність, розмір тощо;
//ціна монітору.
//методи:
//Конструктор по замовчуванню та з параметрами;
//Деструктор;
//Стандартні методи доступу до полів класу, в яких явно використати вказівник this;
//Методи для встановлення значень в поля класу;
//Метод Print() для виведення полів класу на консоль.


class Monitor
{
private:
	string name;
	short price = 0;
	double diagonal = 0;
	short refreshRate = 0;
public:

	Monitor() {}
	Monitor(string name, short price, double diagonal, short refreshRate)
	{
		this->name = name;
		this->price = price;
		this->diagonal = diagonal;
		this->refreshRate = refreshRate;
	}

	void Print()
	{
		cout << name << " " << price << " " << diagonal << " " << refreshRate << "\n";
	}

	~Monitor(){}
};

int main()
{
	vector <Monitor> monitors;

	char key;
	do {
		cout << "Menu\n 1 Show all monitors\n 2 Add new monitor\n 3 Exit\n->_";
		cin >> key;

		switch (key)
		{
		case '1':
		{
			Monitor monitor;
			if (!monitors.empty())
			{
				for (size_t i = 0; i < monitors.size(); i++)
				{
					monitor = monitors[i];
					monitor.Print();
				}
			}
			else
				cout << "Add at least 1 monitor\n";
			break;
		}
		case '2':
		{
			string name;
			double diagonal;
			short price, refreshRate;

			cout << "Enter monitor model: ";
			cin >> name;
			cout << "Enter price: ";
			cin >> price;
			cout << "Enter diagonal: ";
			cin >> diagonal;
			cout << "Enter refresh rate: ";
			cin >> refreshRate;

			Monitor monitor = Monitor(name, price, diagonal, refreshRate);
			monitors.push_back(monitor);

			break;
		}
		default:
			break;
		}

		system("PAUSE");
		system("cls");
	} while (key != '3');

	return 0;
}
