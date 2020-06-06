#ifndef ITEMS_H
#define ITEMS_H

#include <iostream>

using namespace std;

//class Items
//{
//
//};

class Weapon
{
protected:
	int _id;
	string _name;
	int _damage;
	int _cost;
public:
	Weapon(int id, string name, int damage, int cost); 
	int attack();
	void showSpecs();
	string getName();
	int getId();
};

class Fists final: public Weapon
{
private:
	Fists() :Weapon(0, "Fists", 1, 0) {} // id = 0, damage=1, cost=0
	static Fists* _fists;
public:
	static Fists* getFists() { return _fists; }
};

class Knife final : public Weapon
{
public:
	Knife();
};

class Sword final : public Weapon
{
public:
	Sword();
};

#endif