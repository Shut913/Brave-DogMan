#include "Enemy.h"

// Main class:

Enemy::Enemy(string name, int id, int maxHp, int power) :
	_id{ id }, _name{ name }, _maxHp{ maxHp }, _curHp{ maxHp }, _power{ power } {}

string Enemy::getName()
{return _name;}

void Enemy::getHit(int attackPower)
{
	_curHp -= attackPower;
	if (_curHp < 0) _curHp = 0;
}

int Enemy::getCurHp()
{return _curHp;}

int Enemy::getMaxHp()
{return _maxHp;}

void Enemy::heal()
{_curHp = _maxHp;}

int Enemy::getId()
{return _id;}

void Enemy::attack(Unit & unit)
{
	unit.getHit(_power);
}

int Enemy::attackPower()
{
	return _power;
}

// Sub classes:

Wolf::Wolf():
	Enemy("Wolf",2, 30, 3) {} // Name=Wolf, MaxHp=30, attaack=3

void Wolf::giveLoot(Unit& unit)
{
	int randomLoot = rand() % 100 + 1;
	if (randomLoot <= 50) unit.take(rand() % 20 + 5);
	else if (randomLoot > 50 )
	{
		Meat* m = new Meat;
		unit.take(m);
		unit.take(rand() % 20 + 5);
	}
}

Goblin::Goblin() :
	Enemy("Goblin",12, 50, 5) {} // Name=Goblin, MaxHp=50, attaack=5

void Goblin::giveLoot(Unit& unit)
{
	int randomLoot = rand() % 100 + 1;
	if (randomLoot <= 50) unit.take(rand() % 20 + 5);
	else if (randomLoot > 50 && randomLoot <= 60)
	{
		Bread* b = new Bread;
		unit.take(b);
		unit.take(rand() % 20 + 5);
	}
	else if (randomLoot > 60 && randomLoot <= 70)
	{
		Beer* b = new Beer;
		unit.take(b);
		unit.take(rand() % 20 + 5);
	}
	else if (randomLoot > 70 && randomLoot <= 80)
	{
		Apple* a = new Apple;
		unit.take(a);
		unit.take(rand() % 20 + 5);
	}
	else if (randomLoot > 80 && randomLoot <= 90)
	{
		LeatherArmor* l = new LeatherArmor;
		unit.take(l);
		unit.take(rand() % 20 + 5);
	}
	else if (randomLoot > 90 && randomLoot <= 100)
	{
		Knife* k = new Knife;
		unit.take(k);
		unit.take(rand() % 20 + 5);
	}
}

Skeleton::Skeleton() :
	Enemy("Sceleton",22, 75, 7) {} // Name=Sceleton, MaxHp=75, attaack=7

void Skeleton::giveLoot(Unit& unit)
{
	int randomLoot = rand() % 100 + 1;
	if (randomLoot <= 50) unit.take(rand() % 20 + 5);
	else if (randomLoot > 50 && randomLoot <= 60)
	{
		Bread* b = new Bread;
		unit.take(b);
		unit.take(rand() % 20 + 5);
	}
	else if (randomLoot > 60 && randomLoot <= 70)
	{
		Beer* b = new Beer;
		unit.take(b);
		unit.take(rand() % 20 + 5);
	}
	else if (randomLoot > 70 && randomLoot <= 80)
	{
		Apple* a = new Apple;
		unit.take(a);
		unit.take(rand() % 20 + 5);
	}
	else if (randomLoot > 80 && randomLoot <= 90)
	{
		SteelArmor* s = new SteelArmor;
		unit.take(s);
		unit.take(rand() % 20 + 5);
	}
	else if (randomLoot > 90 && randomLoot <= 100)
	{
		Knife* k = new Knife;
		unit.take(k);
		unit.take(rand() % 20 + 5);
	}
}

Bandit::Bandit() :
	Enemy("Bandit",32, 85, 8) {} // Name=Bandit, MaxHp=85, attaack=8

void Bandit::giveLoot(Unit& unit)
{
	int randomLoot = rand() % 100 + 1;
	if (randomLoot <= 50) unit.take(rand() % 20 + 5);
	else if (randomLoot > 50 && randomLoot <= 80)
	{
		HpPotion* h = new HpPotion;
		unit.take(h);
		unit.take(rand() % 20 + 5);
	}
	else if (randomLoot > 80 && randomLoot <= 90)
	{
		DiamondArmor* d = new DiamondArmor;
		unit.take(d);
		unit.take(rand() % 20 + 5);
	}
	else if (randomLoot > 90 && randomLoot <= 100)
	{
		Sword* k = new Sword;
		unit.take(k);
		unit.take(rand() % 20 + 5);
	}
}

Dragon::Dragon() :
	Enemy("Dragon",42, 500, 10) {} // Name=Dragon, MaxHp=500, attaack=10

void Dragon::giveLoot(Unit& unit)
{
	AmuletOfGOD* a = new AmuletOfGOD;
	unit.take(a);
	unit.take(2000);
}
