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

int Weapon::getCost()
{
	return _cost;
}

Fists* Fists::_fists = new Fists;

Knife::Knife():
	Weapon(1, "Knife", 4, 100) {} // id = 1, damage=4, cost=10

Sword::Sword():
	Weapon(2, "Sword", 17, 250) {} // id = 2, damage=17, cost=20


// Food
Food::Food(int id, string name, int restoreHp, int cost) :
	_id{ id }, _name{ name }, _restoreHp{ restoreHp }, _cost{cost}{}

string Food::getName()
{return _name;}

int Food::getRestoreHp()
{
	return _restoreHp;
}

int Food::getCost()
{
	return _cost;
}

Bread::Bread(): 
	Food(0,"Bread", 15, 15){} // restor 15hp, cost 5g

Beer::Beer() :
	Food(1, "Beer", 25, 25) {} // restor 25hp, cost 8g

Apple::Apple() :
	Food(2, "Apple", 10, 5) {} // restor 10hp, cost 3g

HpPotion::HpPotion() :
	Food(0, "HP Potion", 100, 40) {} // restor 100hp, cost 30g

Meat::Meat() :
	Food(0, "Meat", 50, 30) {} // restor 50hp, cost 15g

// Amulets
Amulet::Amulet(int id, string name, int cost, int hpBonus, int armourBonus, int attackBonus, int moneyBonus):
	_id{ id }, _name{ name }, _cost{cost}, _hpBonus{ hpBonus }, _armourBonus{ armourBonus }, _attackBonus{ attackBonus }, _moneyBonus{ moneyBonus }{}

string Amulet::getName()
{return _name;}

int Amulet::getHpBonus()
{
	return _hpBonus;
}

int Amulet::getArmorBonus()
{
	return _armourBonus;
}

int Amulet::getAttackBonus()
{
	return _attackBonus;
}

int Amulet::getMoneyBonus()
{
	return _moneyBonus;
}

int Amulet::getCost()
{
	return _cost;
}

AmuletOfHealth::AmuletOfHealth() :
	Amulet(0, "Amulet of health",300, 20, 0, 0, 0) {}

AmuletOfDefence::AmuletOfDefence() :
	Amulet(1, "Amulet of defence",300, 0, 2, 0, 0) {}

AmuletOfPower::AmuletOfPower() : 
	Amulet(2, "Amulet of power",300, 0, 0, 3, 0) {}

AmuletOfRich::AmuletOfRich() :
	Amulet(3, "Amulet of rich",300, 0, 0, 0, 20) {}

AmuletOfGOD::AmuletOfGOD() :
	Amulet(4, "Amulet of GOD",3000, 20, 2, 3, 20) {}


// Armor
Armor::Armor(int id, string name, int defence, int cost):
	_id{ id }, _name{ name }, _defence{ defence }, _cost{ cost }  {}

string Armor::getName()
{	return _name;}

int Armor::getDef()
{
	return _defence;
}

int Armor::getCost()
{
	return _cost;
}

LeatherArmor::LeatherArmor():
	Armor(0,"Leather armor", 1, 200){}

SteelArmor::SteelArmor() :
	Armor(0, "Steel armor", 2, 600) {}

DiamondArmor::DiamondArmor() :
	Armor(0, "Diamond armor", 3, 1200) {}
