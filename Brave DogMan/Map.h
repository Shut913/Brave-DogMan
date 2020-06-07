#ifndef MAP_H
#define MAP_H

class Unit; // Для видимости

#include <iostream>
#include "Unit.h"
using namespace std;

class Map
{
private:

public:
	Map(Unit &unit);
	int _map[2][2][15][20];
};

#endif