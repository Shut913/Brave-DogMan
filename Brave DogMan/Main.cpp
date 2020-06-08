﻿#include <iostream>
#include <conio.h>
#include <time.h>
#include "Map.h"
#include "Enemy.h"
#include "Items.h"
#include "Unit.h"
#include "GUI.h"

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand(time(NULL));

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
    g.drawInterface(map, unit);
    while (true)
    {
        Sleep(150);
        g.control(map, unit);
    }
    _getch();
    return 0;
}
