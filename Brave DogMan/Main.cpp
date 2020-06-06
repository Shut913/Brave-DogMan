#include <iostream>
#include <conio.h>
#include "Map.h"
#include "Enemy.h"
#include "Items.h"
#include "Unit.h"
#include "GUI.h"

using namespace std;

int main()
{
    
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
