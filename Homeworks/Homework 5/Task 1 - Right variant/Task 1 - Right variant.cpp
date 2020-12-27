#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

template <typename T>
class CShop
{
private:
	vector <T> arr;
public:
	CShop(vector <T>& arr)
	{
		this->arr = arr;
	}
	CShop() {}

	void CheckForNew()
	{
		for (int i = 0; i < arr.size(); i++)
		{
			if (i < arr.size() - 2)
				arr[i].SetIsNew(0);
			else
				arr[i].SetIsNew(1);
		}
	}
	
	void FindExpensive()
	{
		int id = 0, max = -99999;

		for (int i = 0; i < arr.size(); i++)
			if (arr[i].GetPrice() > max)
			{
				id = i;
				max = arr[i].GetPrice();
			}
		arr[id].Print();
	}

	void Show()
	{
		for (int i = 0; i < arr.size(); i++)
		{
			arr[i].Print();
		}
	}
	
	void FindCheap()
	{
		int id = 0, min = 99999;

		for (int i = 0; i < arr.size(); i++)
			if (arr[i].GetPrice() < min)
			{
				id = i;
				min = arr[i].GetPrice();
			}
		arr[id].Print();
	}
	
	int GetAvaragePrices()
	{
		int avgPr = 0;
		for (int i = 0; i < arr.size(); i++)
			avgPr += arr[i].GetPrice();

		return avgPr / arr.size();
	}

	void SortByPrice()
	{
		for (int i = 0; i < arr.size() - 1; i++)
			for (int j = i + 1; j < arr.size(); j++)
				if (arr[i].GetPrice() > arr[j].GetPrice())
					swap(arr[i], arr[j]);
	}
};

class Audio
{
private:
	string name;
	string author;
	short diskAmount;
	int price;
	bool isNew;
public:
	Audio(string name, string author, short diskAmount, int price)
	{
		this->name = name;
		this->author = author;
		this->diskAmount = diskAmount;
		this->price = price;
	}
	Audio() {}

	void SetIsNew(bool isNew)
	{
		this->isNew = isNew;
	}
	bool GetIsNew()
	{
		return isNew;
	}
	int GetPrice()
	{
		return price;
	}

	void Print()
	{
		cout << left << setw(10) << name << " " << setw(8) << author << " " << setw(14)
			<< diskAmount << " " << setw(7) << price << " " << isNew << endl;
	}
};
class Magazine
{
private:
	string name;
	int price;
	bool isNew;
public:
	Magazine(string name, int price)
	{
		this->name = name;
		this->price = price;
	}
	Magazine() {}

	void SetIsNew(bool isNew)
	{
		this->isNew = isNew;
	}
	bool GetIsNew()
	{
		return isNew;
	}
	int GetPrice()
	{
		return price;
	}
	void Print()
	{
		cout << left << setw(10) << name << " " << setw(8) << price << " " << isNew << endl;
	}
};
class Book
{
private:
	string name;
	string author;
	int price;
	bool isNew;
public:
	Book(string name, string author, int price)
	{
		this->name = name;
		this->author = author;
		this->price = price;
	}
	Book() {}

	void SetIsNew(bool isNew)
	{
		this->isNew = isNew;
	}
	bool GetIsNew()
	{
		return isNew;
	}
	int GetPrice()
	{
		return price;
	}
	void Print()
	{
		cout << left << setw(10) << name << " " << setw(8) << author << " " << setw(7) << price << " " << isNew << endl;
	}
};

int main()
{
	vector <Book> books;
	vector <Audio> disks;
	vector <Magazine> magazines;


	Book b("row", "gar", 500);
	Book b1("row", "gar", 1500);
	Book b2("row", "gar", 1500);
	Book b3("row", "gar", 2050);
	books.push_back(b);
	books.push_back(b1);
	books.push_back(b2);
	books.push_back(b3);

	Audio a("cd", "ac", 15, 100);
	Audio a2("cd", "ac", 25, 200);
	disks.push_back(a);
	disks.push_back(a2);

	Magazine m("cosmo", 50);
	Magazine m1("cosmo", 150);
	Magazine m2("cosmo", 250);
	magazines.push_back(m);
	magazines.push_back(m1);
	magazines.push_back(m2);

	CShop<Book>shop(books);
	CShop<Audio>shop2(disks);
	CShop<Magazine>shop3(magazines);

	char key = '0';
	do {
		shop.CheckForNew();
		shop2.CheckForNew();
		shop3.CheckForNew();

		cout << "CShop\n 1 Show products\n 2 Show the most expensive product from each category\n"
			<< " 3 Show the cheapest product from each category\n 4 Show avarage price from each category\n"
			<< " 5 Sort with price all categories\n 6 Exit\n->_";
		cin >> key;

		switch (key)
		{
		case '1':
		{
			system("cls");

			char choice;

			cout << "What category? (1 - Books, 2 - Disks, 3 - Magazines, 4 - All): ";
			cin >> choice;

			switch (choice)
			{
			case '1':
			{
				shop.Show();
				break;
			}
			case '2':
			{
				shop2.Show();
				break;
			}
			case '3':
			{
				shop3.Show();
				break;
			}
			case '4':
			{
				cout << "Books\n";
				shop.Show();
				cout << "Disks\n";
				shop2.Show();
				cout << "Magazines\n";
				shop3.Show();
				break;
			}
			default:
				break;
			}

			break;
		}
		case '2':
		{
			shop.FindExpensive();
			shop2.FindExpensive();
			shop3.FindExpensive();

			break;
		}
		case '3':
		{
			shop.FindCheap();
			shop2.FindCheap();
			shop3.FindCheap();

			break;
		}
		case '4':
		{
			cout << "Books = ";
			cout << shop.GetAvaragePrices() << endl;
			cout << "Disks = ";
			cout << shop2.GetAvaragePrices() << endl;
			cout << "Magazines = ";
			cout << shop3.GetAvaragePrices() << endl;

			break;
		}
		case '5':
		{
			shop.SortByPrice();
			shop.Show();
			shop2.SortByPrice();
			shop2.Show();
			shop3.SortByPrice();
			shop3.Show();

			break;
		}
		default:
			break;
		}

		system("PAUSE");
		system("cls");
	} while (key != '6');

	return 0;
}
