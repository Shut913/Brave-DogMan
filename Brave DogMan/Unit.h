#ifndef UNIT_H
#define UNIT_H

class Enemy; // Для видимости
class Map;
#include <iostream>
#include <Windows.h>
#include "Items.h"
#include "Enemy.h"
#include "Map.h"
using namespace std;

struct Coordinates
{
	int _x_Global;
	int _y_Global;
	int _x_Local;
	int _y_Local;
};

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

	void take(Weapon* weapon);
	void take(Food* food);
	void take(Amulet* amulet);
	void take(Armor* armor);

	//void drop(Weapon& weapon);
	//void drop(Food& food);
	//void drop(Amulet& amulet);
	//void drop(Armor& armor);

	//void use(Weapon& weapon);
	//void use(Food& food);
	//void use(Amulet& amulet);
	//void use(Armor& armor);

	void showAll();
};

class Unit
{
private:
	Coordinates _coords;
	Backpack _backpack;
	Weapon* _weapon;
	int _maxHp;
	int _curHp;
public:
	Unit();

	void attack(Enemy& enemy);
	void getHit(int attackPower)
	{
		_curHp -= attackPower;
		if (_curHp < 0) _curHp = 0;
	}

	void take(Weapon* item);
	void take(Food* item);
	void take(Amulet* item);
	void take(Armor* item);
	void showBackpack();
	const Coordinates& getUnitCoords();
	void moveUnitCoords(int yLocal, int xLocal, Map& map);
};

#endif


