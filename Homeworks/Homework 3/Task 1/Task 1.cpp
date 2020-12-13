#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

void Session();



class Unit
{
public:
	double hp;
	short damage;

	Unit() {}
	Unit(double hp, short damage)
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
	Swordman(double hp, short damage, short hasShield) : Unit(hp, damage)
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
	Wizard(double hp, short damage, short mana) : Unit(hp, damage)
	{
		this->hp = 80;
		this->mana = rand() % 100 + 1;
	}
};

class Bowman : public Unit
{
public:
	short evadeChance;

	Bowman() {}
	Bowman(double hp, short damage, short evadeChance) : Unit(hp, damage)
	{
		this->hp = 70;
		this->damage = rand() % 10 + 1;
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
			Wizard wizard(NULL, NULL, NULL);
			wizards[i] = wizard;
		}
	}

	int GetBowmenHP()
	{
		double hpS = 0;
		for (int i = 0; i < 10; i++)
		{
			hpS += bowmen[i].hp;
		}
		return hpS;
	}
	int GetSwordmenHP()
	{
		double hpS = 0;
		for (int i = 0; i < 10; i++)
		{
			hpS += swordmen[i].hp;
		}
		return hpS;
	}
	int GetWizardsHP()
	{
		double hpS = 0;
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
		if (GetWizardsMana() > 250)
			return allDamage * 1.75;
		else
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
	int GetBowmenEvade()
	{
		int eChance = 0;
		for (int i = 0; i < 10; i++)
			eChance += bowmen[i].evadeChance;
		return eChance;
	}

	void SetBowmenHP(double hp)
	{
		double hpS = hp / 10;
		for (int i = 0; i < 10; i++)
			bowmen[i].hp = hpS;
	}
	void SetSwordmenHP(double hp)
	{
		double hpS = hp / 10;
		for (int i = 0; i < 10; i++)
			swordmen[i].hp = hpS;
	}
	void SetWizardsHP(double hp)
	{
		double hpS = hp / 10;
		for (int i = 0; i < 10; i++)
			wizards[i].hp = hpS;
	}

};

void Attack(int, int, Team&);

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
		cout << setw(5) << "HP : " << setw(15) << red.GetWizardsHP()
			<< blue.GetWizardsHP() << endl;
		cout << setw(9) << "Damage : " << setw(11) << red.GetWizardsDamage()
			<< blue.GetWizardsDamage() << endl;
		cout << setw(7) << "Mana : " << setw(13) << red.GetWizardsMana()
			<< blue.GetWizardsMana() << endl;
		cout << "Swordmen:\n";
		cout << setw(5) << "HP : " << setw(15) << red.GetSwordmenHP()
			<< blue.GetSwordmenHP() << endl;
		cout << setw(9) << "Damage : " << setw(11) << red.GetSwordmenDamage()
			<< blue.GetSwordmenDamage() << endl;
		cout << setw(9) << "Defence : " << setw(10) << red.GetSwordmenShield()
			<< blue.GetSwordmenShield() << endl;
		cout << "Bowmen:\n";
		cout << setw(5) << "HP : " << setw(15) << red.GetBowmenHP()
			<< blue.GetBowmenHP() << endl;
		cout << setw(9) << "Damage : " << setw(11) << red.GetBowmenDamage()
			<< blue.GetBowmenDamage() << endl;
		cout << setw(7) << "Evade : " << setw(12) << red.GetBowmenEvade()
			<< blue.GetBowmenEvade() << endl;

		cout << "\n" << setw(18) << right << "FIGHT\n";

		if (itr % 2 == 0)
		{
			cout << "Red team fighting ...\n";

			int squad, enemiesSquad;
			cout << "Which squad is attacking? (1 - Swordmen, 2 - Wizards, 3 - Bowmen): ";
			cin >> squad;
			cout << "Who are we attacking? (1 - Swordmen, 2 - Wizards, 3 - Bowmen): ";
			cin >> enemiesSquad;

			switch (squad)
			{
			case 1:
			{
				int temp = red.GetSwordmenDamage();
				Attack(enemiesSquad, temp, blue);
				break;
			}
			case 2:
			{
				int temp = red.GetWizardsDamage();
				Attack(enemiesSquad, temp, blue);
				break;
			}
			case 3:
			{
				int temp = red.GetBowmenDamage();
				Attack(enemiesSquad, temp, blue);
				break;
			}

			default:
				break;
			}
		}
		else if(itr==100)
		{
			cout << "Blue team fighting ...\n";
			int squad = 0, enemiesSquad = 0;

			int min = blue.GetSwordmenDamage();
			if (blue.GetBowmenDamage() > min)
			{
				min = blue.GetBowmenDamage();
				squad = 3;
			}
			else if (blue.GetWizardsDamage() > min)
			{
				min = blue.GetWizardsDamage();
				squad = 2;
			}
			else
				squad = 1;

			switch (squad)
			{
			case 1:
			{
				int temp = red.GetSwordmenDamage();
				Attack(enemiesSquad, temp, blue);
				break;
			}
			case 2:
			{
				int temp = red.GetWizardsDamage();
				Attack(enemiesSquad, temp, blue);
				break;
			}
			case 3:
			{
				int temp = red.GetBowmenDamage();
				Attack(enemiesSquad, temp, blue);
				break;
			}

			default:
				break;
			}
		}

		itr++;
		if (itr == 2)
			key = '3';
		else
			key = '1';
		system("PAUSE");
		system("cls");
	} while (key != '3');
}

void Attack(int enemiesSquad, int damage, Team &team)
{
	switch (enemiesSquad)
	{
	case 1:
	{
		team.SetSwordmenHP(team.GetSwordmenHP() - damage);
		break;
	}
	case 2:
	{
		team.SetWizardsHP(team.GetWizardsHP() - damage);
		break;
	}
	case 3:
	{
		team.SetBowmenHP(team.GetBowmenHP() - damage);
		break;
	}
	default:
		break;
	}


}