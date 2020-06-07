#include "Unit.h"

// Backpack

Backpack::Backpack():
	_weaponsQty{ 0 }, _foodQty{ 0 }, _amuletQty{ 0 }, _armorQty{ 0 }
{
	_weapon = nullptr;
	_food = nullptr;
	_amulet = nullptr;
	_armor = nullptr;
}

void Backpack::take(Weapon& weapon)
{
	Weapon** tmp = new Weapon * [_weaponsQty + 1];

	for (int i = 0; i < _weaponsQty; i++)
		tmp[i] = _weapon[i];

	tmp[_weaponsQty] = &weapon;
	delete[]_weapon;
	_weapon = tmp;
	_weaponsQty++;
}

void Backpack::take(Food& food)
{
	Food** tmp = new Food * [_foodQty + 1];

	for (int i = 0; i < _foodQty; i++)
		tmp[i] = _food[i];

	tmp[_foodQty] = &food;
	delete[]_food;
	_food = tmp;
	_foodQty++;
}

void Backpack::take(Amulet& amulet)
{
	Amulet** tmp = new Amulet * [_amuletQty + 1];

	for (int i = 0; i < _amuletQty; i++)
		tmp[i] = _amulet[i];

	tmp[_amuletQty] = &amulet;
	delete[]_amulet;
	_amulet = tmp;
	_amuletQty++;
}

void Backpack::take(Armor& armor)
{
	Armor** tmp = new Armor * [_armorQty + 1];

	for (int i = 0; i < _armorQty; i++)
		tmp[i] = _armor[i];

	tmp[_armorQty] = &armor;
	delete[]_armor;
	_armor = tmp;
	_armorQty++;
}

// Unit
Unit::Unit() :_backpack(), _maxHp{100}, _curHp{100}
{
	_weapon = Fists::getFists();
}

void Unit::attack(Enemy& enemy)
{
	enemy.getHit(_weapon->attack());
}

