#ifndef ITEMS_H
#define ITEMS_H

#include <iostream>

using namespace std;

// Weapons
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
	int getCost();
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

// Food
class Food
{
protected:
	int _id;
	string _name;
	int _restoreHp;
	int _cost;

	Food(int id, string name, int restoreHp, int cost);
public:
	string getName();
	int getRestoreHp();
	int getCost();
};

class Bread final : public Food
{
public:
	Bread();
};

class Beer final : public Food
{
public:
	Beer();
};

class Apple final : public Food
{
public:
	Apple();
};

class HpPotion final : public Food
{
public:
	HpPotion();
};

class Meat final : public Food
{
public:
	Meat();
};

// Amulet
class Amulet
{
protected:
	int _id;
	string _name;
	int _hpBonus;
	int _armourBonus;
	int _attackBonus;
	int _moneyBonus;
	int _cost;

	Amulet(int id, string name, int cost, int hpBonus, int armourBonus, int attackBonus, int moneyBonus);
public:
	string getName();
	int getHpBonus();
	int getArmorBonus();
	int getAttackBonus();
	int getMoneyBonus();
	int getCost();
};

class AmuletOfHealth final : public Amulet
{
public:
	AmuletOfHealth();
};

class AmuletOfDefence final : public Amulet
{
public:
	AmuletOfDefence();
};

class AmuletOfPower final : public Amulet
{
public:
	AmuletOfPower();
};

class AmuletOfRich final : public Amulet
{
public:
	AmuletOfRich();
};

class AmuletOfGOD final: public Amulet
{
public:
	AmuletOfGOD();
};

// Armor
class Armor
{
protected:
	int _id;
	string _name;
	int _defence;
	int _cost;
	Armor(int id, string name, int defence, int cost);
public:
	string getName();
	int getDef();
	int getCost();
};

class LeatherArmor final: public Armor
{
public:
	LeatherArmor();
};

class SteelArmor final: public Armor
{
public:
	SteelArmor();
};

class DiamondArmor final: public Armor
{
public:
	DiamondArmor();
};
#endif