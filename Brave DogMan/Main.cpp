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
    
    Unit unit;
    Sword* s=new Sword;
    Knife* k=new Knife;
    Apple* a = new Apple;
    LeatherArmor* p = new LeatherArmor;
    //Dummy d;
    //u.attack(d);

    unit.take(s);
    unit.take(k);
    unit.take(a);
    unit.take(p);

    a = nullptr;
    s = nullptr;
    k = nullptr;

    Map map(unit);
    GUI g;
    while (true)
    {
        g.drawInterface(map, unit);
        g.control(map, unit);
    }
    _getch();
    return 0;
}
