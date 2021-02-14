#include <iostream>
#include <vector>

//Визначити клас Passport(паспорт), який буде містити паспортну інформацію про громадянина України(ПІБ, серія та номер).
//
//За допомогою механізму успадкування реалізувати клас ForeignPassport(закордонний паспорт) як похідний від Passport.Закордонний паспорт містить окрім паспортних даних, також дані про всі видані візи.Видані візи можна зберігати у вигляді масиву(динамічного масиву) чи вектору(vector<Visa> visas).Передбачити можливість додавання нових віз до паспорту.
//
//Visa(клас або структура) містить назву країни та дату дії візи.
//
//Протестувати роботу класів.

using namespace std;

class Passport
{
private:
	string name;
	string phoneNumber;
	string passId;
public:

	Passport() {}
	Passport(string name, string phoneNumber, string passId)
	{
		this->name = name;
		this->phoneNumber = phoneNumber;
		this->passId = passId;
	}

	bool GetIsName()
	{
		if (!name.empty())
			return 1;
		else
			return 0;
	}

	void ShowPassport()
	{
		if (GetIsName())
			cout << "Name: " << name << " | Phone: " << phoneNumber << " | Pass ID: " << passId << "\n";
		else
			cout << "Passport is empty!";
	}

	void SetName(string name)
	{
		this->name = name;
	}
	void SetPhoneNumber(string phoneNumber)
	{
		this->phoneNumber = phoneNumber;
	}
	void SetPassId(string passId)
	{
		this->passId = passId;
	}

};

class ForeignPassport : public Passport
{
public:
	ForeignPassport()
	{}

	class Visa
	{
	private:
		string country;
		string expiryDate;
	public:

		Visa(string country, string expiryDate)
		{
			this->country = country;
			this->expiryDate = expiryDate;
		}

		void ShowVisa()
		{
			cout << "\tCountry: " << country << " | Expiry date: " << expiryDate << "\n";
		}

		string GetCountry()
		{
			return country;
		}

	};

	vector <Visa> visas;

	bool GetIsVisas()
	{
		if (!visas.empty())
			return 1;
		else
			return 0;
	}

	void ShowAllVisas()
	{
		for (int i = 0; i < visas.size(); i++)
		{
			visas[i].ShowVisa();
		}
	}

	void AddVisa()
	{
		string country, expiryDate;
		cout << "Enter country: ";
		cin >> country;
		cout << "Enter expiry date: ";
		cin >> expiryDate;

		Visa newVisa(country, expiryDate);
		visas.push_back(newVisa);
	}

	void RemoveVisa()
	{
		if (!visas.empty())
		{
			int id;
			cout << "Enter country id: ";
			cin >> id;

			auto it = visas.begin() + (id-1);
			visas.erase(it);
		}
	}
};

int main()
{
	ForeignPassport passport;
	char key;

	do
	{
		cout << " Profile\n1 Show all passport info\n2 Show all visas\n3 Add passport\n4 Add visa\n5 Remove visa\n6 Exit\n->_";
		cin >> key;

		switch (key)
		{
		case '1':
		{
			if (passport.GetIsName())
			{
				passport.ShowPassport();
				cout << "\tYour visas: \n";
				passport.ShowAllVisas();
			}
			else
				cout << "Add passport!\n";

			break;
		}
		case '2':
		{
			if (passport.GetIsVisas() && passport.GetIsName())
			{
				passport.ShowAllVisas();
			}
			else
				cout << "Add passport/visa info at first!\n";
			break;
		}
		case '3':
		{
			string name, phoneNumber, passId;
			if (!passport.GetIsName())
			{
				cout << "Enter name: ";
				cin >> name;
				cout << "Enter phone number: ";
				cin >> phoneNumber;
				cout << "Enter pass id: ";
				cin >> passId;

				passport.SetName(name);
				passport.SetPhoneNumber(phoneNumber);
				passport.SetPassId(passId);
			}
			else
				cout << "Passport is filled\n";
			break;
		}
		case '4':
		{
			if (passport.GetIsName())
				passport.AddVisa();
			else
				cout << "Fill passport!\n";
			break;
		}
		case '5':
		{
			passport.RemoveVisa();
			break;
		}
		default:
			break;
		}

		system("PAUSE");
		system("cls");


	} while (key != '6');
}
