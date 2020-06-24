#include "Unit.h"

// Backpack

Backpack::Backpack():
	_weaponsQty{ 0 }, _foodQty{ 0 }, _amuletQty{ 0 }, _armorQty{ 0 }, _allItemsQty{0}
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
	_allItemsQty++;
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
	_allItemsQty++;
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
	_allItemsQty++;
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
	_allItemsQty++;
}

void Backpack::sellWeapon(Unit& unit, int pos)
{
	unit.take(_weapon[pos]->getCost());
	Weapon** tmp = new Weapon * [_weaponsQty - 1];

	for (int i = 0; i < pos; i++)
		tmp[i] = _weapon[i];

	for (int i = pos; i < _weaponsQty - 1; i++)
		tmp[i] = _weapon[i + 1];

	delete[]_weapon;
	_weapon = tmp;
	_weaponsQty--;
	_allItemsQty--;
}

void Backpack::sellFood(Unit& unit, int pos)
{
	unit.take(_food[pos]->getCost());
	Food** tmp = new Food * [_foodQty - 1];

	for (int i = 0; i < pos; i++)
		tmp[i] = _food[i];

	for (int i = pos; i < _foodQty - 1; i++)
		tmp[i] = _food[i + 1];
	delete _food[pos];
	delete[]_food;
	_food = tmp;
	_foodQty--;
	_allItemsQty--;
}

void Backpack::sellAmulet(Unit& unit, int pos)
{
	unit.take(_amulet[pos]->getCost());
	Amulet** tmp = new Amulet * [_amuletQty - 1];

	for (int i = 0; i < pos; i++)
		tmp[i] = _amulet[i];

	for (int i = pos; i < _amuletQty - 1; i++)
		tmp[i] = _amulet[i + 1];

	delete[]_amulet;
	_amulet = tmp;
	_amuletQty--;
	_allItemsQty--;
}

void Backpack::sellArmor(Unit& unit, int pos)
{
	unit.take(_armor[pos]->getCost());
	Armor** tmp = new Armor * [_armorQty - 1];

	for (int i = 0; i < pos; i++)
		tmp[i] = _armor[i];

	for (int i = pos; i < _armorQty - 1; i++)
		tmp[i] = _armor[i + 1];

	delete[]_armor;
	_armor = tmp;
	_armorQty--;
	_allItemsQty--;
}

void Backpack::useWeapon(Unit& unit, int pos)
{
	unit.wear(_weapon[pos]);
	Weapon** tmp = new Weapon * [_weaponsQty -1];

	for (int i = 0; i < pos; i++)
		tmp[i] = _weapon[i];

	for (int i = pos; i < _weaponsQty-1; i++)
		tmp[i] = _weapon[i+1];

	delete[]_weapon;
	_weapon = tmp;
	_weaponsQty--;
	_allItemsQty--;
}

void Backpack::useFood(Unit& unit, int pos)
{
	unit.heal(_food[pos]->getRestoreHp());
	Food** tmp = new Food * [_foodQty - 1];

	for (int i = 0; i < pos; i++)
		tmp[i] = _food[i];

	for (int i = pos; i < _foodQty - 1; i++)
		tmp[i] = _food[i + 1];
	delete _food[pos];
	delete[]_food;
	_food = tmp;
	_foodQty--;
	_allItemsQty--;
}

void Backpack::useAmulet(Unit& unit, int pos)
{
	unit.wear(_amulet[pos]);
	Amulet** tmp = new Amulet * [_amuletQty - 1];

	for (int i = 0; i < pos; i++)
		tmp[i] = _amulet[i];

	for (int i = pos; i < _amuletQty - 1; i++)
		tmp[i] = _amulet[i + 1];

	delete[]_amulet;
	_amulet = tmp;
	_amuletQty--;
	_allItemsQty--;
}

void Backpack::useArmor(Unit& unit, int pos)
{
	unit.wear(_armor[pos]);
	Armor** tmp = new Armor * [_armorQty - 1];

	for (int i = 0; i < pos; i++)
		tmp[i] = _armor[i];

	for (int i = pos; i < _armorQty - 1; i++)
		tmp[i] = _armor[i + 1];

	delete[]_armor;
	_armor = tmp;
	_armorQty--;
	_allItemsQty--;
}

void Backpack::showAll(Unit& unit, bool interact=false,bool trade=false)
{
	int selectedLine = 0;
	int shiftLines = 0;
	bool useItem = false;

	do
	{

		int k = -shiftLines;
		for (int i = 0; i < _weaponsQty; i++)
		{
			if (k >= 0)
			{
				if (k == 13) break;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 45,short(7+k) });
				if (interact && k== selectedLine) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 143);
				cout<<left <<setw(18)<< _weapon[i]->getName();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				if (interact && k == selectedLine && useItem)
				{
					if (trade) sellWeapon(unit, i);
					else useWeapon(unit, i);
					useItem = false;
					interact = false;
				}
			}
			k++;
		}
		for (int i = 0; i < _foodQty; i++)
		{
			if (k >= 0)
			{
				if (k == 13) break;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 45,short(7 + k) });
				if (interact && k == selectedLine) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 143);
				cout << left << setw(18) << _food[i]->getName();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				if (interact && k == selectedLine && useItem)
				{
					if (trade) sellFood(unit, i);
					else useFood(unit, i);
					useItem = false;
					interact = false;
				}
			}
			k++;
		}
		for (int i = 0; i < _amuletQty; i++)
		{
			if (k >= 0)
			{
				if (k == 13) break;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 45,short(7 + k) });
				if (interact && k == selectedLine) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 143);
				cout << left << setw(18) << _amulet[i]->getName();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				if (interact && k == selectedLine && useItem)
				{
					if (trade) sellAmulet(unit, i);
					else useAmulet(unit, i);
					useItem = false;
					interact = false;
				}
			}
			k++;
		}
		for (int i = 0; i < _armorQty; i++)
		{
			if (k >= 0)
			{
				if (k == 13) break;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 45,short(7 + k) });
				if (interact && k == selectedLine) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 143);
				cout << left << setw(18) << _armor[i]->getName();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				if (interact && k == selectedLine && useItem)
				{
					if (trade) sellArmor(unit, i);
					else useArmor(unit, i);
					useItem = false;
					interact = false;
				}
			}
			k++;
		}
		if (_allItemsQty>13)
		{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 45,20 });
		cout << left << setw(18) << "       v";
		}
		else
		{
			int n = k;
			while (n <= 13)
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 45,short(7 + n) });
				cout << left << setw(18) << "  ";
				n++;
			}
		}

		if (_allItemsQty == 0) return;

		if (interact)
		{
			int key;
			key = _getch();
			switch (key)
			{
			case (72):		// ^ - перемещение вверх
				if (--selectedLine < 0)
				{
					selectedLine = 0;
					if (--shiftLines < 0) shiftLines = 0;
				}
				break;
			case (80):		// v - перемещение вниз
				if (selectedLine == 12 && (_allItemsQty - selectedLine - shiftLines) > 1)
				{
					shiftLines++;
				}
				if (++selectedLine == k)
				{
					selectedLine = k - 1;
				}
				break;

			case (105):		// I - инвентарь
				interact = false;
				break;
			case (32):		// space - подтвердить действие
				useItem = true;
				break;
			case (27):		// ESC - выход в меню

				break;
			}
		}
		

	} while (interact);
}

// Unit
Unit::Unit() :_backpack(), _maxHp{ 100 }, _curHp{ 34 }, _money{100}
{
	_coords._x_Global=2;
	_coords._y_Global = 3;
	_coords._x_Local = 8;
	_coords._y_Local = 7;
	_weapon = Fists::getFists();
	_amulet = nullptr;
	_armor = nullptr;
}

void Unit::attack(Enemy* enemy)
{
	enemy->getHit(_weapon->attack());
}

int Unit::attackPower()
{
	return _weapon->attack();
}

void Unit::getHit(int attackPower)
{
	int tmp = attackPower - getDef();
	if (tmp < 0) tmp = 0;
	_curHp -= tmp;
	if (_curHp < 0) _curHp = 0;
}


int Unit::getCurHp()
{return _curHp;}

int Unit::getMaxHp()
{
	if (_amulet == nullptr)
		return _maxHp;
	else
		return _maxHp + _amulet->getHpBonus();
}

int Unit::getMoney()
{return _money;}

int Unit::getDef()
{
	int tmp = 0;
	if (_amulet != nullptr)
		tmp+= _amulet->getArmorBonus();

	if (_armor!=nullptr) 
		tmp+= _armor->getDef();

	return tmp;
}

string Unit::getCurWeapon()
{return _weapon->getName();}

string Unit::getCurAmulet()
{
	if (_amulet == nullptr) return "Empty";
	return _amulet->getName();
}

string Unit::getCurArmor()
{
	if (_armor == nullptr) return "Empty";
	return _armor->getName();
}

void Unit::wear(Weapon * item)
{
	if (_weapon->getId()!=0) take(_weapon);
	_weapon = item;
}

void Unit::wear(Amulet* item)
{
	if (_amulet!= nullptr) take(_amulet);
	_amulet = item;
}

void Unit::wear(Armor* item)
{
	if (_armor != nullptr) take(_armor);
	_armor = item;
}

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
	if (getCurHp() > getMaxHp()) _curHp = getMaxHp();
}

void Unit::showBackpack()
{
	_backpack.showAll(*this);
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

void Unit::useInventory(bool trade=false)
{

	if (trade)
		_backpack.showAll(*this, true, true);
	else 
		_backpack.showAll(*this, true);
}

