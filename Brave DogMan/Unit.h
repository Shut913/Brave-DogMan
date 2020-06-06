#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include "Items.h"
#include "Enemy.h"

using namespace std;

class Unit
{
private:
	Weapon** _weapon;
	int _weaponsQty;
	int _curWeapon;
public:
	Unit() :_curWeapon{ 0 }, _weaponsQty{ 1 }
	{
		_weapon = new Weapon * [1];
		_weapon[0] = Fists::getFists();
	}

	void takeWeapon(Weapon& weapon)
	{
		bool alreadyHave = false;
		for (int i = 0; i < _weaponsQty; i++)
		{
			if (&weapon == _weapon[i]) alreadyHave = true;
		}

		if (alreadyHave == false)
		{
			Weapon** tmp = new Weapon * [_weaponsQty + 1];

			for (int i = 0; i < _weaponsQty; i++)
				tmp[i] = _weapon[i];

			tmp[_weaponsQty] = &weapon;
			delete[]_weapon;
			_weapon = tmp;
			_weaponsQty++;
		}
	}

	void changeWeapon()
	{
		_curWeapon++;
		if (_curWeapon == _weaponsQty) _curWeapon = 0;
	}

	void attack(Enemy& enemy)
	{
		enemy.getHit(_weapon[_curWeapon]->attack());
	}

	void showInventory()
	{
		cout << " - Units inventory - " << endl;
		if (_weaponsQty == 1) cout << " Empty" << endl;
		else
			for (int i = 1; i < _weaponsQty; i++)
			{
				cout << ' ' << i << ". " << _weapon[i]->getName() << endl;
			}
		cout << " =================" << endl;
	}

	Weapon* currWeapon()
	{
		return _weapon[_curWeapon];
	}
};

#endif