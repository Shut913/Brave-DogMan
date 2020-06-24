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
	Enemy(string name,int id, int maxHp, int power);
public:
	string getName();
	void getHit(int attackPower);
	int getCurHp();
	int getMaxHp();
	void heal();
	int getId();
	void attack(Unit& unit);
	int attackPower();
	virtual void giveLoot(Unit& unit)=0;
};

// Sub classes:
class Wolf final : public Enemy
{
public:
	Wolf();
	virtual void giveLoot(Unit& unit);
};

class Goblin final : public Enemy
{
public:
	Goblin();
	virtual void giveLoot(Unit& unit);
};

class Skeleton final : public Enemy
{
public:
	Skeleton();
	virtual void giveLoot(Unit& unit);
};

class Bandit final : public Enemy
{
public:
	Bandit();
	virtual void giveLoot(Unit& unit);
};

class Dragon final : public Enemy
{
public:
	Dragon();
	virtual void giveLoot(Unit& unit);
};


#endif