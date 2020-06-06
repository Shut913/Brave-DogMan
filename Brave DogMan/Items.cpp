#include "Items.h"

// Weapons
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


// Food
Food::Food(int id, string name, int restoreHp, int cost) :
	_id{ id }, _name{ name }, _restoreHp{ restoreHp }, _cost{cost}{}

string Food::getName()
{return _name;}

Bread::Bread(): 
	Food(0,"Bread", 15, 5){} // restor 15hp, cost 5g

Beer::Beer() :
	Food(1, "Beer", 25, 8) {} // restor 25hp, cost 8g

Apple::Apple() :
	Food(2, "Apple", 10, 3) {} // restor 10hp, cost 3g

HpPotion::HpPotion() :
	Food(0, "HP Potion", 100, 30) {} // restor 100hp, cost 30g

Meat::Meat() :
	Food(0, "Meat", 50, 15) {} // restor 50hp, cost 15g

// Amulets
Amulet::Amulet(int id, string name, double hpBonus, double armourBonus, double attackBonus, double moneyBonus):
	_id{ id }, _name{ name }, _hpBonus{ hpBonus }, _armourBonus{ armourBonus }, _attackBonus{ attackBonus }, _moneyBonus{ moneyBonus }{}

string Amulet::getName()
{return _name;}

AmuletOfHealth::AmuletOfHealth() :
	Amulet(0, "Amulet of health", 1.2, 1, 1, 1) {}

AmuletOfDefence::AmuletOfDefence() :
	Amulet(1, "Amulet of defence", 1, 1.2, 1, 1) {}

AmuletOfPower::AmuletOfPower() : 
	Amulet(2, "Amulet of power", 1, 1, 1.2, 1) {}

AmuletOfRich::AmuletOfRich() :
	Amulet(3, "Amulet of rich", 1, 1, 1, 1.2) {}

AmuletOfGOD::AmuletOfGOD() :
	Amulet(4, "Amulet of GOD", 1.2, 1.2, 1.2, 1.2) {}


// Armor
Armor::Armor(int id, string name, double defence):
	_id{id}, _name{name}, _defence{defence} {}

string Armor::getName()
{	return _name;}

LeatherArmor::LeatherArmor():
	Armor(0,"Leather armor", 0.8){}

SteelArmor::SteelArmor() :
	Armor(0, "Steel armor", 0.6) {}

DiamondArmor::DiamondArmor() :
	Armor(0, "Diamond armor", 0.4) {}
