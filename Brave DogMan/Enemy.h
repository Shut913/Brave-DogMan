#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
using namespace std;

// Main class:

class Enemy
{
protected:
	int _id;
	string _name;
	int _maxHp;
	int _curHp;
	Enemy(string name, int maxHp, int curHp);
	static int _lastId;
public:
	string getName();
	void getHit(int attackPower);
	int getCurHp();
	int getMaxHp();
	void heal();
	int getId();
};

// Sub classes:

class Dummy final : public Enemy
{
public:
	Dummy();
};

#endif