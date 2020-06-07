#include <iostream>
#include <conio.h>
#include "Map.h"
//#include "Enemy.h"
//#include "Items.h"
//#include "Unit.h"
#include "GUI.h"

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    //Unit u;
    //Sword s;
    //Dummy d;
    //u.takeWeapon(s);
    //u.changeWeapon();
    //u.attack(d);
    Map map;
    GUI g;
    g.drawInterface(map);
    _getch();
    return 0;
}
