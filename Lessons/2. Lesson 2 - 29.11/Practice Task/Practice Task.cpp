#include <iostream>
#include <ctime>

using namespace std;

//  Написати клас "Карточка на знижку" (DiscountCard), який містить наступну інформацію :
//
//  Номер карточки random 10000000 - 99999999
//  Розмір знижки(знижка передбачається накопичуваною; на початковому етапі вона рівна 1 % .За кожні 1000 грн.покупки, сума знижки збільшується на 1 % .)
//  Приховане допоміжне поле для збереження вартості накупленого товару
//  Дата видачі карточки,
//  Забезпечити можливість :
//
//  Купляти товар з використанням карточки на знижку;
//  Виводити інформацію про поточну величину знижки;
//  Виводити інформацію про те, на яку суму ще необхідно докупити товару, щоб величина знижки збільшилась.

class DiscountCard
{
private:
	long int cardId = 0;
	int discountSize = 1;
	int spentMoney = 0;
	string issueDate = "01.02.1970";
public:
	DiscountCard() {}

	DiscountCard(int cardId, int discountSize, int spentMoney, string issueDate)
	{
		this->cardId = cardId;
		this->discountSize = discountSize;
		this->spentMoney = spentMoney;
		this->issueDate = issueDate;
	}

	int GetCardId()
	{
		return cardId;
	}

	int GetDiscountSize()
	{
		return discountSize;
	}

	int GetSpentMoney()
	{
		return spentMoney;
	}

	string GetIssueDate()
	{
		return issueDate;
	}

	void SetIssueDate(string issueDate)
	{
		this->issueDate = issueDate;
	}

	void RandomCardId()
	{
		srand(unsigned(time(NULL)));

		cardId = rand() % 89999999 + 10000000;
	}

	void AddMoneySpent(int spentMoney)
	{
		this->spentMoney += spentMoney;
	}

	void AddDiscountSize(int discountSize)
	{
		if (this->discountSize + discountSize <= 10)
			this->discountSize += discountSize;
		else
			this->discountSize = 10;
	}

	int DiscountRemains()
	{
		if (spentMoney < 1000)
		{
			return 1000 - spentMoney;
		}
		else if (spentMoney % 1000 == 0)
			return 1000;
		else
		{
			int temp = spentMoney / 1000;
			temp = (temp + 1) * 1000;
			return temp - spentMoney;
		}
	}

	int DoDiscount(int money)
	{
		money -= (money * discountSize) / 100;

		return money;
	}

};

int main()
{
	char key;

	DiscountCard user;
	user.RandomCardId();

	do {
		cout << "\tMenu:\n 1 Show info about card\n 2 How much i need to buy for increase discount size on 1%\n 3 Shop\n 4 Exit\n->_";
		cin >> key;

		switch (key)
		{
		case '1':
		{
			system("cls");
			char key;
			cout << " 1 Show money spent\n 2 Show card id\n 3 Show issue date \n 4 Show discount size\n 5 Change issue date\n 6 Exit\n->_";
			cin >> key;

			switch (key)
			{
			case '1':
			{
				cout << "All money spent: " << user.GetSpentMoney() << endl;
				system("PAUSE");
				break;
			}
			case '2':
			{
				cout << "Card id: " << user.GetCardId() << endl;
				system("PAUSE");
				break;
			}
			case '3':
			{
				cout << "Issue date: " << user.GetIssueDate() << endl;
				system("PAUSE");
				break;
			}
			case '4':
			{
				cout << "Discount size: " << user.GetDiscountSize() << endl;
				system("PAUSE");
				break;
			}
			case '5':
			{
				string temp;
				cout << "Enter new issue date: ";
				cin >> temp;
				user.SetIssueDate(temp);
				break;
			}
			default:
				break;
			}
			system("cls");
			break;
		}
		case '2':
		{
			cout << "You should spent " << user.DiscountRemains() << " money to gain 1% discount\n";
			system("PAUSE");
			break;
		}
		case '3':
		{
			system("cls");
			int money, discountSize;

			cout << "How much money you want to spend: ";
			cin >> money;

			money = user.DoDiscount(money);
			discountSize = money / 1000;
			user.AddDiscountSize(discountSize);
			user.AddMoneySpent(money);
			
			cout << "You will spend " << money - ((money * user.GetDiscountSize()) / 100) << "; Discount: "
				<< user.GetDiscountSize() << "\n";
			
			system("PAUSE");
			break;
		}
		default:
			break;
		}
		system("cls");

	} while (key != '4');



	return 0;
}
