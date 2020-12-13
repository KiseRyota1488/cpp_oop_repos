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
        int lenght;
        int floor;
    public:
        vector <Room> rooms;

       
        Room(int width, int length, int floor)
        {
            this->width = width;
            this->lenght = lenght;
            this->floor = floor;
        }

        void CreateRoom()
        {
            int width, lenght, floor;
            cout << "Enter width: ";
            cin >> width;
            cout << "Enter lenght: ";
            cin >> lenght;
            cout << "Enter floor: ";
            cin >> floor;
            Room room = Room(width, lenght, floor);
            rooms.push_back(room);
        }

        void ShowRooms()
        {
            for (int i = 0; i < rooms.size(); i++)
                cout << "Width: " << rooms[i].width << "\nLenght: " << rooms[i].lenght << "\nFloor: " << rooms[i].floor << endl;
        }

        int GetWidth()
        {
            return width;
        }
        int GetLenght()
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
        void SetLenght(int lenght)
        {
            this->lenght = lenght;
        }
        void SetFloor(int floor)
        {
            this->floor = floor;
        }

        ~Room() {}
   

        
    };

public:
    House()
    {

    }
};

int main()
{
    House h;



    return 0;
}
