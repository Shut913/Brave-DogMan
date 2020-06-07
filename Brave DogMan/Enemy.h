#ifndef ENEMY_H
#define ENEMY_H

class Unit; // для видимости

#include <iostream>
#include "Unit.h"
using namespace std;

// Main class:
class Enemy
{
protected:
	int _id;
	string _name;
	int _maxHp;
	int _curHp;
	int _power;
	Enemy(string name, int maxHp, int power);
	static int _lastId;
public:
	string getName();
	void getHit(int attackPower);
	int getCurHp();
	int getMaxHp();
	void heal();
	int getId();
	void attack(Unit& unit);
};

// Sub classes:
class Wolf final : public Enemy
{
public:
	Wolf();
};

class Goblin final : public Enemy
{
public:
	Goblin();
};

class Sceleton final : public Enemy
{
public:
	Sceleton();
};

class Bandit final : public Enemy
{
public:
	Bandit();
};

class Dragon final : public Enemy
{
public:
	Dragon();
};


#endif