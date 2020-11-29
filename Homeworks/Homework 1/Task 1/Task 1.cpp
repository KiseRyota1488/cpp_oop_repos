#include <iostream>
#include <ctime>
#include <vector>

//Написати клас "Банківський рахунок" (Account), який містить :
//
//Перевірити пін - код(3 неправильних введення - блок рахунку)
//
//Властивості
//Номер рахунку   Заповняється випадковим числом від 00000000 до 99999999
//Розмір коштів на рахунку(Balance)
//Назва валюти рахунку(гривні, евро, BTC тощо)
//
//
//Забезпечити можливість :
//
//Знімати гроші з рахунку
//Докладати гроші на рахунок
//Показати баланс
//
//Перевірити коректність роботи класу.

using namespace std;

class Account
{
private:
	int cardId = 0;
	int balance = 0;
	vector <char> pinCode = { '0','0','0','0' };
	string currency = "hrn";
public:

	Account() {}

	Account(int cardId, int balance, string currency)
	{
		this->cardId = cardId;
		this->balance = balance;
		this->currency = currency;
	}

	void CreateCardId()
	{
		srand(unsigned(time(0)));

		cardId = rand() % 999999999 + 100000001;
	}

	int GetCardId()
	{
		return cardId;
	}

	int GetBalance()
	{
		return balance;
	}

	void SetPinCode()
	{
		cout << "Enter new pin code: ";

		for (int i = 0; i < pinCode.size(); i++)
			cin >> pinCode[i];
	}

	void SetBalance(int money)
	{
		balance += money;
	}

	string GetCurrency()
	{
		return currency;
	}

	bool PinCodeCheck(char pinCodeArray[4])
	{
		int check = 0;

		for (int i = 0; i < pinCode.size(); i++)
		{
			if (pinCodeArray[i] == pinCode[i])
				check += 1;
		}

		if (check == 4)
			return 1;
		else
			return 0;
	}
};


int main()
{
	Account user;

	user.CreateCardId();
	user.SetPinCode();

	char key;
	do {
		cout << "\tMenu\n 1 Put money on account\n 2 Withdraw money from account\n 3 Show balance\n->_";
		cin >> key;

		int attemps = 3;
		char tempPin[4];

		switch (key)
		{
		case '1':
		{
			bool operation = 0;

			attemps = 3;

			do {
				cout << "Enter your pin code: ";
				cin >> tempPin;

				if (user.PinCodeCheck(tempPin))
				{
					int money;
					cout << "How much money you want to put on your account: ";
					cin >> money;

					if (money <= 0)
						cout << "Wrong number, try again!\n";
					else if (money >= 1000)
						cout << "Maximal sum to put is 1000 " << user.GetCurrency() << "\n";
					else
					{
						user.SetBalance(money);
						cout << "Operation success!\n";
						operation = 1;
					}

				}
				else
				{
					attemps--;
					cout << "Your pincode isnt right. Try again! You have " << attemps << "\n";
					if (attemps == 0)
						operation = 1;
				}
				system("PAUSE");
				system("cls");
			} while (!operation);

			break;
		}
		case '2':
		{
			bool operation = 0;

			attemps = 3;

			cout << "Enter your pin code: ";
			cin >> tempPin;

			do {
				if (user.PinCodeCheck(tempPin))
				{
					int money;
					cout << "How much money you want to withdraw: ";
					cin >> money;

					if (user.GetBalance() < money)
						cout << "Not enough money!\n";
					else if (money < 50)
						cout << "Minimal sum to withdraw is 50\n";
					else
					{
						user.SetBalance((-1) * money);
						operation = 1;
					}
					system("cls");
				}
				else
				{
					attemps--;
					cout << "Your pincode isnt right. Try again! You have " << attemps << "\n";
					if (attemps == 0)
						operation = 1;
				}
			} while (!operation);

			break;
		}
		case '3':
		{
			bool operation = 0;
			

			attemps = 3;

			do {
				cout << "Enter your pin code: ";
				cin >> tempPin;

				if (user.PinCodeCheck(tempPin))
				{
					cout << "Your balance: " << user.GetBalance() << " " << user.GetCurrency() << "\n";
					operation = 1;
				}
				else
				{
					attemps--;
					cout << "Your pincode isnt right. Try again! You have " << attemps << "\n";
					if (attemps == 0)
						operation = 1;
				}
				
				system("PAUSE");
				system("cls");

			} while (!operation);
				
				
			break;
		}
		default:
			break;
		}

		if (attemps == 0)
		{
			cout << "You have 0 attemps. Restart session!";
			key = '4';
		}

	} while (key != '4');

	return 0;
}
