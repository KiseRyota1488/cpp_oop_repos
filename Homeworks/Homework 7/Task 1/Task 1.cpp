#include <iostream>
#include <vector>

using namespace std;

class Train
{
private:

	int number = 0;
	string depTime;
	string destination;

public:

	Train(int number, string depTime, string destination)
	{
		this->number = number;
		this->depTime = depTime;
		this->destination = destination;
	};

	class Carriage
	{
	private:
		int seats;
		string type;

	public:

		Carriage(int seats, string type)
		{
			this->seats = seats;
			this->type = type;
		}

		int GetSeats()
		{
			return seats;
		}
		string GetType()
		{
			return type;
		}

		void PrintCarriage()
		{
			cout << "Seats: " << seats << " Type: " << type << endl;
		}

	};

	vector <Carriage> carriages;

	int GetNumber()
	{
		return number;
	}

	int GetTrainSeats()
	{
		int allSeats = 0;

		for (int i = 0; i < carriages.size(); i++)
			allSeats += carriages[i].GetSeats();

		return allSeats;
	}

	void CreateCarriage(int seats, string type)
	{
		Carriage carriage(seats, type);
		carriages.push_back(carriage);
	}

	void PrintTrain()
	{
		cout << "Train number: " << number << " Depart time: " << depTime << " Destination: "
			<< destination << " Carriages: " << carriages.size() << " Overall seats in train: " << GetTrainSeats() << endl;

		for (int i = 0; i < carriages.size(); i++)
		{
			cout << "\tCarriage " << i + 1 << " | ";
			carriages[i].PrintCarriage();
		}
		cout << endl;

	}

};

int main()
{
	vector <Train> trains;

	char key;

	do {
		cout << " 1 - Show all trains\n 2 - Show train by number\n 3 - Add train\n 4 - Add carriage\n 5 - Exit\n->_";		cin >> key;

		switch (key)
		{
		case '1':
		{
			if (!trains.empty())
			{
				for (int i = 0; i < trains.size(); i++)
					trains[i].PrintTrain();

				break;
			}
			else
			{
				cout << "At first create train!\n";
				goto addTrain;
			}

		}
		case '2':
		{
			if (!trains.empty())
			{
				int number;
				cout << "Enter train number: ";
				cin >> number;

				for (int i = 0; i < trains.size(); i++)
				{
					if (trains[i].GetNumber() == number)
					{
						trains[i].PrintTrain();

						break;
					}
				}

				break;
			}
			else
			{
				cout << "At first create train!\n";
				goto addTrain;
			}

		}
		case '3':
		{
			addTrain:
			int number;
			string depTime, destination;
			cout << "Enter number: ";
			cin >> number;
			cout << "Enter departure time: ";
			cin >> depTime;
			cout << "Enter destination: ";
			cin >> destination;

			Train train(number, depTime, destination);
			trains.push_back(train);

			goto addCarriage;

			break;
		}
		case '4':
		{
			if (!trains.empty())
			{
			addCarriage:
				int number, seats;
				string type;
				cout << "Enter train number: ";
				cin >> number;
				cout << "Enter seats: ";
				cin >> seats;
				cout << "Enter type: ";
				cin >> type;

				for (int i = 0; i < trains.size(); i++)
				{
					if (trains[i].GetNumber() == number)
					{
						trains[i].CreateCarriage(seats, type);
					}
				}
			}
			else
			{
				cout << "At first add train!\n";
				goto addTrain;
			}

			break;
		}

		default:
			break;
		}

		system("PAUSE");
		system("cls");

	} while (key != '5');

}