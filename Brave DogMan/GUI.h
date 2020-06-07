#ifndef GUI_H
#define GUI_H

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Map.h"
//#include "Enemy.h"
//#include "Items.h"
//#include "Unit.h"

using namespace std;

class GUI
{
private:
public:
	GUI();
	void drawInterface(const Map &map, Unit &unit );
	void control(Map& map, Unit& unit);
};


#endif
