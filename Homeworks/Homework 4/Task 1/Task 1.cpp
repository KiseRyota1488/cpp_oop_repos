#include <iostream>
#include <vector>

using namespace std;

//Визначити класи
//Room з полями
//ширина кімнати
//довжина кімнати
//поверх
//та методами
//конструктори
//методами доступу до полів(getters, setters)
//обчислення площі кімнати
//виводу інформації про кімнату
//заповнення кімнати з клавіатури
//
//House з полями
//кімната - кухня
//кількість кімнат
//динамічний масив кімнат(Room * rooms)
//кількість поверхів
//та методами
//конструктори
//деструктор
//виведення інформації про кімнати будинку
//обчислення сумарної площі кімнати int totalRoomsSquare() const
//обчислення площі кімнат на певному поверсі int levelRoomsSquare(int level) const)
//зміна розмірів певної кімнати(за номером у масиві кімнат)
//зміна розмірів кухні
//вивід інформації про кімнати на заданому поверсі
//Перевірити роботу класу.

class House
{

private:
	int floor = 0;

	class Room
	{
	private:
		int width = 0;
		int length = 0;
	public:

		Room() {}
		Room(int width, int length)
		{
			this->width = width;
			this->length = length;
		}

		Room CreateRoom()
		{
			int width, length, floor;
			cout << "Enter width: ";
			cin >> width;
			cout << "Enter length: ";
			cin >> length;

			Room room = Room(width, length);
			return room;
		}


		int GetWidth()
		{
			return width;
		}
		int GetLength()
		{
			return length;
		}

		void SetWidth(int width)
		{
			this->width = width;
		}
		void Setlength(int length)
		{
			this->length = length;
		}

		int GetSquare()
		{
			return width * length;
		}

		~Room() {}

	};



public:
	vector <Room> rooms;

	House() {}
	House(int floor)
	{
		this->floor = floor;
	}

	int GetFloor()
	{
		return floor;
	}
	void SetFloor(int floor)
	{
		this->floor = floor;
	}

	void AddRoom()
	{
		Room room;
		rooms.push_back(room.CreateRoom());
	}
	void ShowRooms()
	{
		for (int i = 0; i < rooms.size(); i++)
		{
			cout << "Room " << i + 1 << " " << rooms[i].GetWidth() << "x" << rooms[i].GetLength() << endl;
		}
	}

	~House()
	{

	}
};

void AddRoom(vector<House>&, char);

void SortHouses(vector<House>&);

int main()
{
	vector <House> houses;

	char key;
	do {
		cout << "Menu:\n 1 Add room\n 2 Show all houses with special floor\n 3 Show all rooms in in 1 house\n 4 Exit\n";
		cin >> key;


		switch (key)
		{
		case '1':
		{
			char choice;
			cout << "Add room to existing house or create new one? (1 - add to existing | 2 - create new):\n->_";
			cin >> choice;

			AddRoom(houses, choice);

			break;
		}
		case '2':
		{
			bool cond = 0;
			if (!houses.empty())
			{
				while (!cond)
				{
					int floor;
					cout << "Enter floor: ";
					cin >> floor;

					if (floor > 0)
					{
						cout << "ID|Width|Height\n";
						for (int i = 0; i < houses.size(); i++)
						{
							if (houses[i].GetFloor() == floor)
							{
								cout << "House " << i + 1 << "\n";
								houses[i].ShowRooms();
							}
						}
						cond = 1;
					}
					else
						cout << "Wrong floor!";
				}
			}
			else
				cout << "No houses\n";

			break;
		}
		case '3':
		{
			bool cond = 0;
			if (!houses.empty())
			{
				while (!cond)
				{

					int id;
					cout << "Enter house id: ";
					cin >> id;

					if (id <= houses.size() && id > 0)
					{
						for (int i = 0; i < houses.size(); i++)
							if (i + 1 == id)
							{
								cout << "House " << i + 1 << "\n";
								houses[i].ShowRooms();
							}
						cond = 1;
					}
					else
						cout << "Wrong house id!\n";

				}
			}
			else
				cout << "No houses\n";

			break;
		}
		default:
			break;
		}

		system("PAUSE");
		system("cls");

		if (!houses.empty())
			SortHouses(houses);

	} while (key != '5');

	return 0;
}

void AddRoom(vector<House>& houses, char choice)
{
	bool cond = 0;
	if (choice == '1' && !houses.empty())
	{
		while (!cond)
		{

			int id;
			cout << "Enter house id: ";
			cin >> id;

			if (id <= houses.size() && id > 0)
			{
				for (int i = 0; i < houses.size(); i++)
					if (i + 1 == id)
						houses[i].AddRoom();
				cond = 1;
			}
			else
				cout << "Wrong house id!\n";
		}
	}
	else if (choice == '2')
	{
		int floor;
		cout << "Enter floor: ";
		cin >> floor;

		House house(floor);
		house.AddRoom();

		houses.push_back(house);

	}
	else
		cout << "Wrong choice!";
}

void SortHouses(vector <House>& houses)
{
	for (int i = 0; i < houses.size() - 1; i++)
		for (int j = i + 1; j < houses.size(); j++)
			if (houses[i].GetFloor() > houses[j].GetFloor())
				swap(houses[i], houses[j]);
}

