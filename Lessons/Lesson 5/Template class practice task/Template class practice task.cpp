#include <iostream>

using namespace std;

template <typename T/*, typename T2, typename T3*/>
class CShop
{
private:
	int frArrSize = 0;
	T* arr1;
public:
	CShop(T* arr1, int frArrSize/*, T* arr2, T* arr3*/)
	{
		this->arr1 = arr1;
		this->frArrSize = frArrSize;
	}
	CShop(){}

	void Show()
	{
		for (size_t i = 0; i < frArrSize; i++)
			this->arr1[i].Print();
	}
};

class Book
{
private:
	string name;
public:
	Book(string name)
	{
		this->name = name;
	}
	Book(){}

	void Print()
	{
		cout << "Name " << name << "\n";
	}
};

int main()
{
	int booksSize = 5, cdDisksSize = 5, magazinesSize = 5;
	Book* books = new Book[booksSize];

	/*char key = '0';
	do{
		cout << "CShop\n 1 Show all products\n 2 Show the most expensive product from each category\n"
			<< "3 Show the cheapest product from each category\n 4 Show avarage price from each category\n"
			<< "5 Show the HOT new one\n 6 Exit\n->_";
		cin >> key;

		
	
	} while (key != '6');*/
	
	Book b1("1");
	Book b2("2");
	Book b3("3");

	books[0] = b1;
	books[1] = b2;
	books[2] = b3;
	
	CShop<Book>shop(books, booksSize);

	shop.Show();

	return 0;
}
