// Practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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


	class Room
	{
	private:
		int width;
		int length;
		int floor;
	public:

		Room() {}
		Room(int width, int length, int floor)
		{
			this->width = width;
			this->length = length;
			this->floor = floor;
		}

		Room CreateRoom()
		{
			int width, length, floor;
			cout << "Enter width: ";
			cin >> width;
			cout << "Enter length: ";
			cin >> length;
			cout << "Enter floor: ";
			cin >> floor;
			Room room = Room(width, length, floor);
			return room;
		}


		int GetWidth()
		{
			return width;
		}
		int Getlength()
		{
			return width;
		}
		int GetFloor()
		{
			return floor;
		}

		void SetWidth(int width)
		{
			this->width = width;
		}
		void Setlength(int length)
		{
			this->length = length;
		}
		void SetFloor(int floor)
		{
			this->floor = floor;
		}

		int GetSquare()
		{
			return width * length;
		}

		~Room() {}

	};



public:
	vector <Room> rooms;
	int floors[9] = { 0 };
	House()
	{

	}

	void AddRoom()
	{
		Room room;
		rooms.push_back(room.CreateRoom());
	}

	void ShowRooms()
	{
		for (int i = 0; i < rooms.size(); i++)
			cout << rooms[i].GetWidth() << " " << rooms[i].Getlength() << " " << rooms[i].GetFloor() << endl;
	}

	void OverallSquare()
	{
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < rooms.size(); j++)
				if (i == rooms[j].GetFloor())
					floors[i] += rooms[j].GetSquare();
	}

	void ShowOverallSquare()
	{
		for (int i = 0; i < 9; i++)
		{
			cout << floors[i] << endl;
		}
	}

	~House()
	{

	}
};

int main()
{
	House house;

	house.AddRoom();
	house.AddRoom();
	house.ShowRooms();
	house.OverallSquare();
	house.ShowOverallSquare();

	return 0;
}
