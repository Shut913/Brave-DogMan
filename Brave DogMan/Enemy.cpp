#include "Enemy.h"

// Main class:

int Enemy::_lastId = 0;

Enemy::Enemy(string name, int maxHp, int power) :
	_id{ ++_lastId }, _name{ name }, _maxHp{ maxHp }, _curHp{ maxHp }, _power{ power } {}

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

// Sub classes:

Wolf::Wolf():
	Enemy("Wolf", 30, 3) {} // Name=Wolf, MaxHp=30, attaack=3

Goblin::Goblin() :
	Enemy("Goblin", 50, 5) {} // Name=Goblin, MaxHp=50, attaack=5

Sceleton::Sceleton() :
	Enemy("Sceleton", 75, 7) {} // Name=Sceleton, MaxHp=75, attaack=7

Bandit::Bandit() :
	Enemy("Bandit", 85, 8) {} // Name=Bandit, MaxHp=85, attaack=8

Dragon::Dragon() :
	Enemy("Dragon", 500, 10) {} // Name=Dragon, MaxHp=500, attaack=10
