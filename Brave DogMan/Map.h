#ifndef MAP_H
#define MAP_H

class Unit; // Äëÿ âèäèìîñòè

#include <iostream>
#include "Unit.h"
using namespace std;

class Map
{
private:

public:
	Map(Unit& unit);
	int _map[5][5][15][20];
};

#endif