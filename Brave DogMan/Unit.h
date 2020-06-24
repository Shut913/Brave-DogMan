#ifndef UNIT_H
#define UNIT_H

class Enemy; // Для видимости
class Map;
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <conio.h>
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
	int _allItemsQty;
public:
	Backpack();

	void take(Weapon* weapon);
	void take(Food* food);
	void take(Amulet* amulet);
	void take(Armor* armor);

	void sellWeapon(Unit& unit, int pos);
	void sellFood(Unit& unit, int pos);
	void sellAmulet(Unit& unit, int pos);
	void sellArmor(Unit& unit, int pos);

	void useWeapon(Unit& unit, int pos);
	void useFood(Unit& unit, int pos);
	void useAmulet(Unit& unit, int pos);
	void useArmor(Unit& unit, int pos);

	void showAll(Unit& unit, bool interact, bool trade);
};

class Unit
{
private:
	Coordinates _coords;
	Backpack _backpack;
	Weapon* _weapon;
	Amulet* _amulet;
	Armor* _armor;
	int _money;
	int _maxHp;
	int _curHp;
public:
	Unit();

	void attack(Enemy* enemy);
	int attackPower();
	void getHit(int attackPower);
	int getCurHp();
	int getMaxHp();
	int getMoney();
	int getDef();
	string getCurWeapon();
	string getCurAmulet();
	string getCurArmor();
	void wear(Weapon* item);
	void wear(Amulet* item);
	void wear(Armor* item);
	void take(Weapon* item);
	void take(Food* item);
	void take(Amulet* item);
	void take(Armor* item);
	void take(int money);
	void heal(int hp);
	void showBackpack();
	const Coordinates& getUnitCoords();
	void moveUnitCoords(int yLocal, int xLocal, Map& map);
	void useInventory(bool trade);

};

#endif
