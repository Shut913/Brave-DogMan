#include "Enemy.h"

// Main class:

int Enemy::_lastId = 0;

Enemy::Enemy(string name, int maxHp, int curHp) :
	_id{ ++_lastId }, _name{ name }, _maxHp{ maxHp }, _curHp{ curHp } {}

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

// Sub classes:

Dummy::Dummy():
	Enemy("Dummy", 1000, 1000) {} // Name=Dummy, MaxHp=1000
