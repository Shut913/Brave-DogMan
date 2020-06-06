#include "Items.h"

Weapon::Weapon(int id, string name, int damage, int cost) :
	_id{ id }, _name{ name }, _damage{ damage }, _cost{ cost } {}

int Weapon::attack() 
{ return _damage; }

void Weapon::showSpecs()
{

	cout << " Name: " << _name << endl
		<< " Damage: " << _damage << endl
		<< " Cost: " << _cost << endl;
	cout << " =================" << endl;
}

string Weapon::getName()
{return _name;}

int Weapon::getId()
{return _id;}

Fists* Fists::_fists = new Fists;

Knife::Knife():
	Weapon(1, "Knife", 4, 10) {} // id = 1, damage=4, cost=10

Sword::Sword():
	Weapon(2, "Sword", 17, 20) {} // id = 2, damage=17, cost=20
