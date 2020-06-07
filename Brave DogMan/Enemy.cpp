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
	Enemy("Wolf", 30) {} // Name=Wolf, MaxHp=30

Goblin::Goblin() :
	Enemy("Goblin", 50) {} // Name=Goblin, MaxHp=50