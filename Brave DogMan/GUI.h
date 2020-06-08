#ifndef GUI_H
#define GUI_H

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Map.h"
#include "Enemy.h"
#include "Items.h"
#include "Unit.h"

using namespace std;

class GUI
{
private:
public:
	GUI();
	void drawInterface(Map &map, Unit &unit );
	void control(Map& map, Unit& unit);
	void interract(int cellCode, Map& map, Unit& unit);
	void drawUnitInfo(Unit& unit);
	void drawUnitItems(Unit& unit);
	void drawGameWindow(Map& map, Unit& unit);
	void drawLegend();
};


#endif
