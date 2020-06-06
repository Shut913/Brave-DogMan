#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include "Items.h"
#include "Enemy.h"

using namespace std;

class Backpack
{
private:
	Weapon** _weapon;
	int _weaponsQty;
	Food** _food;
	int _foodQty;
	Amulet** _amulet;
	int _amuletQty;
	Armor** _armor;
	int _armorQty;
public:
	Backpack();

	void take(Weapon& weapon);
	void take(Food& food);
	void take(Amulet& amulet);
	void take(Armor& armor);

	void drop(Weapon& weapon);
	void drop(Food& food);
	void drop(Amulet& amulet);
	void drop(Armor& armor);

	void use(Weapon& weapon);
	void use(Food& food);
	void use(Amulet& amulet);
	void use(Armor& armor);
};

class Unit
{
private:
	Backpack _backpack;
	Weapon* _weapon;

public:
	Unit();

	void attack(Enemy& enemy);

};

#endif