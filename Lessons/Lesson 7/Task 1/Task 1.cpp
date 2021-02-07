#include <iostream>
#include <list>

using namespace std;

class Library
{
private:
	string name;
	string author;
	bool issued;
	int year;

public:
	Library(string name, string author, int year)
	{
		this->name = name;
		this->author = author;
		this->year = year;
		this->issued = 0;
	}

	string GetName()
	{
		return name;
	}

	string GetAuthor()
	{
		return author;
	}

	bool GetIssued()
	{
		return issued;
	}

	int GetYear()
	{
		return year;
	}

	void PrintBook()
	{
		cout << name << " | Author: " << author << " / " << year << " y. | Issued ";
		if (issued)
			cout << "+";
		else
			cout << "-";

		cout << endl;
	}

	void SetIssue(bool issued)
	{
		this->issued = issued;
	}

};

void SortByAuthor(list <Library>&);

void Issue(Library&);


int main()
{
	list <Library> books;

	char key;

	do {
		cout << "Menu\n 1. Add book \n 2. Show all library\n->_";
		cin >> key;

		switch (key)
		{
		case '4':
		{
			Library book("ab", "bb", 2000);
			Library book1("aa", "aa", 2000);
			Library book2("bb", "aa", 2000);

			books.push_back(book);
			books.push_back(book1);
			books.push_back(book2);

			break;
		}
		case '1':
		{
			string name, author;
			int year;

			cout << "Enter name: ";
			cin >> name;
			cout << "Enter author: ";
			cin >> author;
			cout << "Enter year: ";
			cin >> year;

			Library book(name, author, year);
			books.push_back(book);

			break;
		}
		case '2':
		{
			if (!books.empty())
			{
				for (auto i = books.begin(); i != books.end(); i++)
				{
					i->PrintBook();
				}
			}

			break;
		}
		case '3':
		{
			char choice;
			cout << "Search by name or author: (1 - name/2 - author): ";
			cin >> choice;

			if (choice == '1')
			{
				string name;
				cout << "Enter name: ";
				cin >> name;
				for (auto i = books.begin(); i != books.end(); i++)
				{
					if (i->GetName() == name)
					{
						i->PrintBook();
						if (!i->GetIssued())
							Issue(*i);
					}
				}
			}
			else if (choice == '2')
			{
				string author;
				cout << "Enter author: ";
				cin >> author;
				for (auto i = books.begin(); i != books.end(); i++)
				{
					if (i->GetAuthor() == author)
					{
						i->PrintBook();
						if (!i->GetIssued())
							Issue(*i);
					}
				}
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

void SortByAuthor(list <Library>& books)
{
	for (auto i = books.begin(); i != books.end(); i++)
	{

	}
}

void Issue(Library& book)
{
	bool choice;
	cout << "Want to take book? 1 yes/0 no: ";
	cin >> choice;
	book.SetIssue(choice);
}

