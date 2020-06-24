#include <iostream>
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
    Apple* a1 = new Apple;
    Apple* a2 = new Apple;
  
    unit.take(a1);
    unit.take(a2);

    a1 = nullptr;
    a2 = nullptr;

    Map map(unit);
    GUI g;
    g.beginText();
    g.drawInterface(map, unit);
    try
    {
        while (true)
        {
            Sleep(150);
            g.control(map, unit);
        }
    }
    catch (const char* text)
    {
        for (int i = 0; i < 15; i++)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 2,short(6 + i) });
            for (int j = 0; j < 20; j++)
            {
                cout << "  ";
            }
        }

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 15,13 });
        cout << text;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 15,14 });
    }
    _getch();
    system("cls");
    return 0;
}
