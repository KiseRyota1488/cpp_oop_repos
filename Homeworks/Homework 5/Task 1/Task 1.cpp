#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

template <typename T/*, typename T2, typename T3*/>
class CShop
{
private:
	vector <T> arr1;
	vector <T> arr2;
	vector <T> arr3;
public:
	CShop(vector <T>& arr1/*, T* arr2, T* arr3*/)
	{
		this->arr1 = arr1;
	}
	CShop() {}

	void CheckForNew(vector <T>& arr)
	{
		for (int i = 0; i < arr.size(); i++)
		{
			if (i < arr.size() - 2)
				arr[i].SetIsNew(0);
			else
				arr[i].SetIsNew(1);
		}

	}

	void Show(char key)
	{
		if (key == '1')
		{
			cout << "Book name | Author | Price | New\n";
			for (int i = 0; i < arr1.size(); i++)
				this->arr1[i].Print();
		}
		else if (key == '2')
			for (int i = 0; i < arr2.size(); i++)
				this->arr2[i].Print();
		else if (key == '3')
			for (int i = 0; i < arr3.size(); i++)
				this->arr3[i].Print();
		else
			cout << "Wrong command!\n";
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

	void Print()
	{
		cout << left << setw(10) << name << " " << setw(8) << author << " " << setw(7) << price << " " << isNew << endl;
	}
};

int main()
{
	vector <Book> books;
	/*char key = '0';
	do{
		cout << "CShop\n 1 Show all products\n 2 Show the most expensive product from each category\n"
			<< "3 Show the cheapest product from each category\n 4 Show avarage price from each category\n"
			<< "5 Show the HOT new one\n 6 Exit\n->_";
		cin >> key;



	} while (key != '6');*/

	Book b1("gary", "joanne", 500);
	Book b2("potter", "rowling", 400);
	Book b3("prikvel", "idk", 1000);

	books.push_back(b1);
	books.push_back(b2);
	books.push_back(b3);

	CShop<Book>shop(books);

	shop.CheckForNew(books);
	shop.Show('1');
	cout << books[2].GetIsNew();

	

	return 0;
}
