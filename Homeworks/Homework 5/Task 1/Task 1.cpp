#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

template <typename T1, typename T2, typename T3>
class CShop
{
private:
	vector <T1> arr1;
	vector <T2> arr2;
	vector <T3> arr3;
public:
	CShop(vector <T1>& arr1, vector <T2> &arr2, vector <T3> &arr3)
	{
		this->arr1 = arr1;
		this->arr2 = arr2;
		this->arr3 = arr3;
	}
	CShop() {}

	void CheckForNew(vector <T1>& arr1, vector <T2>& arr2, vector <T3>& arr3)
	{
		for (int i = 0; i < arr1.size(); i++)
		{
			if (i < arr1.size() - 1)
				arr1[i].SetIsNew(0);
			else
				arr1[i].SetIsNew(1);
		}
		for (int i = 0; i < arr2.size(); i++)
		{
			if (i < arr2.size() - 1)
				arr2[i].SetIsNew(0);
			else
				arr2[i].SetIsNew(1);
		}
		for (int i = 0; i < arr3.size(); i++)
		{
			if (i < arr3.size() - 1)
				arr3[i].SetIsNew(0);
			else
				arr3[i].SetIsNew(1);
		}

	}

	void SortByPriceExp(vector<T1>& arr1, vector<T2>& arr2, vector<T3>& arr3)
	{
		int id = 0, max = -99999;

		for (int i = 0; i < arr1.size(); i++)
			if (arr1[i].GetPrice() > max)
			{
				id = i;
				max = arr1[i].GetPrice();
			}
		max = -99999;
		arr1[id].Print();
		for (int i = 0; i < arr2.size(); i++)
			if (arr2[i].GetPrice() > max)
			{
				id = i;
				max = arr2[i].GetPrice();
			}
		max = -99999;
		arr2[id].Print();
		for (int i = 0; i < arr3.size(); i++)
			if (arr3[i].GetPrice() > max)
			{
				id = i;
				max = arr3[i].GetPrice();
			}
		arr3[id].Print();


	}

	void Show(char key)
	{
		if (key == '1')
		{
			cout << "Book name | Author | Price | New\n";
			for (int i = 0; i < this->arr1.size(); i++)
				this->arr1[i].Print();
		}
		else if (key == '2')
		{
			cout << "Disk name | Author | Disk amount |Price | New\n";
			for (int i = 0; i < this->arr2.size(); i++)
				this->arr2[i].Print();
		}
		else if (key == '3')
		{
			cout << "Magazine | Price | New\n";
			for (int i = 0; i < this->arr3.size(); i++)
				this->arr3[i].Print();
		}
		else if ( key == '4')
		{
			cout << "Book name | Author | Price | New\n";
			for (int i = 0; i < this->arr1.size(); i++)
				this->arr1[i].Print();
			cout << "Disk name | Author | Disk amount |Price | New\n";
			for (int i = 0; i < this->arr2.size(); i++)
				this->arr2[i].Print();
			cout << "Magazine | Price | New\n";
			for (int i = 0; i < this->arr3.size(); i++)
				this->arr3[i].Print();
		}
		else
			cout << "Wrong command!\n";
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
		cout << left << setw(10) << name << " " << setw(8) << author << " " << setw(7) 
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
		cout << left << setw(10) << name << " "  << setw(8) << price << " " << isNew << endl;
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
	books.push_back(b);

	Audio a("cd", "ac", 15, 100);
	Audio a2("cd", "ac", 25, 200);
	disks.push_back(a);
	disks.push_back(a2);

	Magazine m("cosmo", 50);
	magazines.push_back(m);

	CShop<Book, Audio, Magazine>shop(books, disks, magazines);

	char key = '0';
	do{
		shop.CheckForNew(books, disks, magazines);

		cout << "CShop\n 1 Show products\n 2 Show the most expensive product from each category\n"
			<< " 3 Show the cheapest product from each category\n 4 Show avarage price from each category\n"
			<< " 5 Show the new one\n 6 Sort with price all categories\n 7 Exit\n->_";
		cin >> key;

		switch (key)
		{
		case '1':
		{
			system("cls");

			char choice;
			
			cout << "What category? (1 - Books, 2 - Disks, 3 - Magazines, 4 - All): ";
			cin >> choice;

			shop.Show(choice);

			break;
		}
		case '2':
		{
			shop.SortByPriceExp(books, disks, magazines);


			break;
		}
		default:
			break;
		}

		system("PAUSE");
		system("cls");
	} while (key != '7');

	return 0;
}
