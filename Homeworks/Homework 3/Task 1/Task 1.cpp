#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

class Unit
{
public:
	short hp;
	short damage;
	short hitChance;

	Unit() {}
	Unit(short hp, short damage, short hitChance)
	{
		srand(time(0));
		this->hp = 100;
		this->damage = rand()%5+1;
		this->hitChance = 100;
	}

};

class Swordman : public Unit
{
public:
	bool hasShield = 0;

	Swordman(short hp, short damage, short hitChance, short hasShield) : Unit(hp, damage, hitChance)
	{
		this->hasShield = hasShield;
	}

	bool GetShield()
	{
		return hasShield;
	}
};

class Wizard : public Unit
{
public:
	short mana = 100;

	Wizard() {}
	Wizard(short hp, short damage, short hitChance, short mana) : Unit(hp, damage, hitChance)
	{
		this->mana = mana;
	}
};

class Bowman : public Unit
{
public:
	short evadeChance = 15;

	Bowman() {}
	Bowman(short hp, short damage, short hitChance, short evadeChance) : Unit(hp, damage, hitChance)
	{
		this->evadeChance = evadeChance;
	}

};

class Team
{
public:
	vector <Bowman> bowmen;
	vector <Swordman> swordmen;
	vector <Wizard> wizards;

};


int main()
{
	
	


	return 0;
}