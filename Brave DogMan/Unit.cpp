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

void Backpack::take(Weapon* weapon)
{
	Weapon** tmp = new Weapon * [_weaponsQty + 1];

	for (int i = 0; i < _weaponsQty; i++)
		tmp[i] = _weapon[i];

	tmp[_weaponsQty] = weapon;
	delete[]_weapon;
	_weapon = tmp;
	_weaponsQty++;
}

void Backpack::take(Food* food)
{
	Food** tmp = new Food * [_foodQty + 1];

	for (int i = 0; i < _foodQty; i++)
		tmp[i] = _food[i];

	tmp[_foodQty] = food;
	delete[]_food;
	_food = tmp;
	_foodQty++;
}

void Backpack::take(Amulet* amulet)
{
	Amulet** tmp = new Amulet * [_amuletQty + 1];

	for (int i = 0; i < _amuletQty; i++)
		tmp[i] = _amulet[i];

	tmp[_amuletQty] = amulet;
	delete[]_amulet;
	_amulet = tmp;
	_amuletQty++;
}

void Backpack::take(Armor* armor)
{
	Armor** tmp = new Armor * [_armorQty + 1];

	for (int i = 0; i < _armorQty; i++)
		tmp[i] = _armor[i];

	tmp[_armorQty] = armor;
	delete[]_armor;
	_armor = tmp;
	_armorQty++;
}

void Backpack::showAll()
{
	int k = 0;
	for (int i = 0; i < _weaponsQty; i++)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 45,short(7+k) });
		cout<<left <<setw(18)<< _weapon[i]->getName();
		k++;
	}
	for (int i = 0; i < _foodQty; i++)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 45,short(7 + k) });
		cout << left << setw(18) << _food[i]->getName();
		k++;
	}
	for (int i = 0; i < _amuletQty; i++)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 45,short(7 + k) });
		cout << left << setw(18) << _amulet[i]->getName();
		k++;
	}
	for (int i = 0; i < _armorQty; i++)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 45,short(7 + k) });
		cout << left << setw(18) << _armor[i]->getName();
		k++;
	}




}

// Unit
Unit::Unit() :_backpack(), _maxHp{ 100 }, _curHp{ 100 }, _money{100}
{
	_coords._x_Global=0;
	_coords._y_Global = 0;
	_coords._x_Local = 8;
	_coords._y_Local = 7;
	_weapon = Fists::getFists();
}

void Unit::attack(Enemy& enemy)
{
	enemy.getHit(_weapon->attack());
}


int Unit::getCurHp()
{return _curHp;}

int Unit::getMaxHp()
{return _maxHp;}

int Unit::getMoney()
{return _money;}

string Unit::getCurWeapon()
{return _weapon->getName();}

void Unit::take(Weapon* item)
{
	_backpack.take(item);
}

void Unit::take(Food* item)
{
	_backpack.take(item);
}

void Unit::take(Amulet* item)
{
	_backpack.take(item);
}

void Unit::take(Armor* item)
{
	_backpack.take(item);
}

void Unit::take(int money)
{
	_money += money;
}

void Unit::heal(int hp)
{
	_curHp += hp;
	if (_curHp > _maxHp) _curHp = _maxHp;
}

void Unit::showBackpack()
{
	_backpack.showAll();
}

const Coordinates& Unit::getUnitCoords()
{return _coords;}

void Unit::moveUnitCoords(int yLocal, int xLocal, Map& map)
{
	
	map._map[_coords._y_Global][_coords._x_Global][_coords._y_Local][_coords._x_Local] = 0;
	_coords._y_Local += yLocal;
	_coords._x_Local += xLocal;

	if (_coords._y_Local < 0)
	{
		_coords._y_Local = 14;
		_coords._y_Global--;
	}
	if (_coords._y_Local > 14)
	{
		_coords._y_Local = 0;
		_coords._y_Global++;
	}
	if (_coords._x_Local < 0)
	{
		_coords._x_Local = 19;
		_coords._x_Global--;
	}
	if (_coords._x_Local > 19)
	{
		_coords._x_Local = 0;
		_coords._x_Global++;
	}
	map._map[_coords._y_Global][_coords._x_Global][_coords._y_Local][_coords._x_Local] = 6;
}

