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
	
	Unit(){}
	Unit(short hp, short damage, short hitChance)
	{
		this->hp = 100;
		this->damage = 5;
		this->hitChance = 90;
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


int main()
{
	char space = ' ';

	Unit* units = new Unit [5];
	Swordman sword;

	units[0] = sword;

	units[0].hasShield = 0;
	// cout <<setw(15)<< "|" <<left<<setfill(space)<<"TABLE"<<"|\n";


	return 0;
}