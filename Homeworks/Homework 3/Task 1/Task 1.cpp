#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

void Session();

class Unit
{
public:
	short hp;
	short damage;

	Unit() {}
	Unit(short hp, short damage)
	{
		this->hp = 100;
		this->damage = rand() % 5 + 1;
	}

};

class Swordman : public Unit
{
public:
	int hasShield;

	Swordman() {};
	Swordman(short hp, short damage, short hasShield) : Unit(hp, damage)
	{
		this->hasShield = rand() % 2;
	}

	bool GetShield()
	{
		return hasShield;
	}
};

class Wizard : public Unit
{
public:
	short mana;

	Wizard() {}
	Wizard(short hp, short damage, short mana) : Unit(hp, damage)
	{
		this->mana = rand() % 100 + 1;
	}
};

class Bowman : public Unit
{
public:
	short evadeChance;

	Bowman() {}
	Bowman(short hp, short damage, short evadeChance) : Unit(hp, damage)
	{
		this->evadeChance = rand() % 30 + 1;
	}

};

class Team
{
public:
	Bowman bowmen[10];
	Swordman swordmen[10];
	Wizard wizards[10];

	void GenerateTeam()
	{
		for (int i = 0; i < 10; i++)
		{
			Bowman bow(NULL, NULL, NULL);
			bowmen[i] = bow;
			Swordman sword(NULL, NULL, NULL);
			swordmen[i] = sword;
			Wizard wizard( NULL, NULL, NULL);
			wizards[i] = wizard;
		}
	}

	int GetBowmenHP()
	{
		int hpS = 0;
		for (int i = 0; i < 10; i++)
		{
			hpS += bowmen[i].hp;
		}
		return hpS;
	}
	int GetSwordmenHP()
	{
		int hpS = 0;
		for (int i = 0; i < 10; i++)
		{
			hpS += swordmen[i].hp;
		}
		return hpS;
	}
	int GetWizardsHP()
	{
		int hpS = 0;
		for (int i = 0; i < 10; i++)
		{
			hpS += wizards[i].hp;
		}
		return hpS;
	}

	int GetBowmenDamage()
	{
		int allDamage = 0;
		for (int i = 0; i < 10; i++)
		{
			allDamage += bowmen[i].damage;
		}
		return allDamage;
	}
	int GetSwordmenDamage()
	{
		int allDamage = 0;
		for (int i = 0; i < 10; i++)
		{
			allDamage += swordmen[i].damage;
		}
		return allDamage;
	}
	int GetWizardsDamage()
	{
		int allDamage = 0;
		for (int i = 0; i < 10; i++)
		{
			allDamage += wizards[i].damage;
		}
		return allDamage;
	}

	int GetWizardsMana()
	{
		int mana = 0;
		for (int i = 0; i < 10; i++)
		{
			mana += wizards[i].mana;
		}
		return mana;
	}
	int GetSwordmenShield()
	{
		int shields = 0;
		for (int i = 0; i < 10; i++)
			shields += swordmen[i].hasShield;
		return shields * 10;
	}

	void SetBowmenHP(short hp)
	{
		int hpS = (GetBowmenHP() - 10) / 10;
		for (int i = 0; i < 10; i++)
			bowmen[i].hp = hpS;
	}
	void SetSwordmenHP(short hp)
	{
		int hpS = (GetSwordmenHP() - 10) / 10;
		for (int i = 0; i < 10; i++)
			swordmen[i].hp = hpS;
	}
	void SetWizardsHP(short hp)
	{
		int hpS = (GetWizardsHP() - hp) / 10;
		for (int i = 0; i < 10; i++)
			wizards[i].hp = hpS;
	}

};


int main()
{
	srand(time(0));

	Session();

	return 0;
}

void Session()
{
	Team red, blue;

	red.GenerateTeam();
	blue.GenerateTeam();

	char key, space = ' ';
	int itr = 0;
	do {
		cout << setw(20) << left << "RED" << "BLUE\n";
		cout << "Wizards:\n";
		cout << setw(5) << "HP : " <<setw(15)<< red.GetWizardsHP() 
			  << blue.GetWizardsHP() <<endl;
		cout << setw(9) << "Damage : " <<setw(11)<< red.GetWizardsDamage()
			  << blue.GetWizardsDamage() << endl;
		cout << setw(7) << "Mana : " <<setw(13)<< red.GetWizardsMana()
			  << blue.GetWizardsMana() << endl;
		cout << "Swordmen:\n";
		cout << setw(5) << "HP : " << setw(15) << red.GetSwordmenHP()
			<< blue.GetSwordmenHP() << endl;
		cout << setw(9) << "Damage : " << setw(11) << red.GetSwordmenDamage()
			<< blue.GetSwordmenDamage() << endl;
		cout << setw(9) << "Defence : " << setw(10) << red.GetSwordmenShield()  
			<< blue.GetSwordmenShield() << endl;

		cout << "\n" << setw(18) <<right<< "FIGHT\n";
		
		if(itr%2 == 0)
		{
			cout << "Red team fighting ...\n";
			
			int squad, enemiesSquad;
			cout << "Which squad is attacking? (1 - Swordmen, 2 - Wizards, 3 - Bowmen): ";
			cin >> squad;

			// в функції!
			/*cout << "Who are we attacking? (1 - Swordmen, 2 - Wizards, 3 - Bowmen): ";
			cin >> enemiesSquad;*/
		}

		itr++;
		key = '3';
		system("cls");
	} while (key != '3');
}