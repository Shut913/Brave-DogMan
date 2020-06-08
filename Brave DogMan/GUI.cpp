#include "GUI.h"

GUI::GUI()
{
	system("mode con cols=70 lines=30"); // widow size 27x65
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	GetConsoleCursorInfo(hOut, &info);
	info.bVisible = false;
	SetConsoleCursorInfo(hOut, &info);
}

void GUI::drawInterface(Map &map, Unit& unit)
{
	system("cls");

	drawLegend();

	drawUnitInfo(unit);

	drawGameWindow(map, unit);

	drawUnitItems(unit);

}

void GUI::control(Map& map, Unit& unit)
{
	int key;
	int cellCode;
	key = _getch();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 102);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { short(unit.getUnitCoords()._x_Local*2+2),short(unit.getUnitCoords()._y_Local +6)});
	cout << "  ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	switch (key) {
	case (72):		// ^ - перемещение юнита вверх
		if (unit.getUnitCoords()._y_Local != 0)
		{
			cellCode = map._map[unit.getUnitCoords()._y_Global][unit.getUnitCoords()._x_Global][unit.getUnitCoords()._y_Local - 1][unit.getUnitCoords()._x_Local];
			if (cellCode ==0)
				unit.moveUnitCoords(-1, 0, map);
			else
			{
				interract(cellCode, map, unit);
			}
		}
		else
		{
			unit.moveUnitCoords(-1, 0, map);
			drawInterface(map, unit);
		}
		break;
	case (80):		// v - перемещение юнита вниз
		if (unit.getUnitCoords()._y_Local != 14)
		{
			cellCode = map._map[unit.getUnitCoords()._y_Global][unit.getUnitCoords()._x_Global][unit.getUnitCoords()._y_Local + 1][unit.getUnitCoords()._x_Local];
			if (cellCode == 0)
				unit.moveUnitCoords(1, 0, map);
			else
			{
				interract(cellCode, map, unit);
			}
		}
		else
		{
			unit.moveUnitCoords(1, 0, map);
			drawInterface(map, unit);
		}
		break;
	case (75):		// <- - перемещение юнита влево
		if (unit.getUnitCoords()._x_Local != 0)
		{
			cellCode = map._map[unit.getUnitCoords()._y_Global][unit.getUnitCoords()._x_Global][unit.getUnitCoords()._y_Local][unit.getUnitCoords()._x_Local - 1];
			if (cellCode == 0)
				unit.moveUnitCoords(0, -1, map);
			else
			{
				interract(cellCode, map, unit);
			}
		}
		else
		{
			unit.moveUnitCoords(0, -1, map);
			drawInterface(map, unit);
		}
		break;
	case (77):		// -> - перемещение юнита вправо
		if (unit.getUnitCoords()._x_Local != 19)
		{
			cellCode = map._map[unit.getUnitCoords()._y_Global][unit.getUnitCoords()._x_Global][unit.getUnitCoords()._y_Local][unit.getUnitCoords()._x_Local + 1];
			if (cellCode == 0)
				unit.moveUnitCoords(0, 1, map);
			else
			{
				interract(cellCode, map, unit);
			}
		}
		else
		{
			unit.moveUnitCoords(0, 1, map);
			drawInterface(map, unit);
		}
		break;
	case (32):		// space - подтвердить действие

		break;
	case (27):		// ESC - выход в меню

		break;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 111);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { short(unit.getUnitCoords()._x_Local * 2 + 2),short(unit.getUnitCoords()._y_Local + 6 )});
	cout << " @";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void GUI::interract(int cellCode, Map& map, Unit& unit)
{

	switch (cellCode)
	{
	case 2: // monsters
	case 12:
	case 22:
	case 32:
	case 42:
	case 52:

		break;
	case 3: // trader
	{

	}
		break;
	case 4:  // forest
		if (rand()%20==10)
		{	Apple* a = new Apple;
			unit.take(a);
			drawInterface(map, unit); 
		}
		break;
	case 5: // quest
	{

	}
		break;
	case 7: // the fountain
	{
		unit.heal(200);
	}
		break;
	case 8: // water
	{

	}
		break;
	case 9: // chest
	{
		int randomLoot = rand() % 100 + 1;
		if (randomLoot <= 50) unit.take(rand() % 20 + 5);
		else if (randomLoot > 50 && randomLoot <= 60)
		{
			Apple* a1 = new Apple;
			Apple* a2 = new Apple;
			Apple* a3 = new Apple;
			Apple* a4 = new Apple;
			unit.take(a1);
			unit.take(a2);
			unit.take(a3);
			unit.take(a4);
			unit.take(rand() % 20 + 5);
		}
		else if (randomLoot > 60 && randomLoot <= 70)
		{
			Knife* k = new Knife;
			unit.take(k);
			unit.take(rand() % 20 + 5);
		}
		else if (randomLoot > 70 && randomLoot <= 80)
		{
			Sword* s = new Sword;
			unit.take(s);
			unit.take(rand() % 20 + 5);
		}
		else if (randomLoot > 80 && randomLoot <= 90)
		{
			Bread* b = new Bread;
			unit.take(b);
			unit.take(rand() % 20 + 5);
		}
		else if (randomLoot > 90 && randomLoot <= 100)
		{
			LeatherArmor* l = new LeatherArmor;
			unit.take(l);
			unit.take(rand() % 20 + 5);
		}
	}
		break;
	}

	drawUnitInfo(unit);

	drawUnitItems(unit);
}

void GUI::drawUnitInfo(Unit& unit)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 3,1 });
	cout << "HP: "<<unit.getCurHp()<<'('<<unit.getMaxHp()<<')';
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 3,2 });
	cout << "ARM: 50";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 3,3 });
	cout << "Weapon: "<<unit.getCurWeapon();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 3,4 });
	cout << "Gold: "<<unit.getMoney();
}

void GUI::drawUnitItems(Unit& unit)
{
	unit.showBackpack();
}

void GUI::drawGameWindow(Map& map, Unit& unit)
{
	int x = unit.getUnitCoords()._x_Global;
	int y = unit.getUnitCoords()._y_Global;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 49,22 });
	cout << "Map coord:";

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 51,23 });
	cout << x << ':' << y;

  for (int i = 0; i < 15; i++)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 2,short(6+i) });
		for (int j = 0; j < 20; j++)
		{
			if (map._map[y][x][i][j] == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 102);
				cout << "  ";
			}
			else if (map._map[y][x][i][j] == 1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
				cout << " #";
			}
			else if (map._map[y][x][i][j] == 2 ||
				map._map[y][x][i][j] == 12 ||
				map._map[y][x][i][j] == 22 ||
				map._map[y][x][i][j] == 32 ||
				map._map[y][x][i][j] == 42 ||
				map._map[y][x][i][j] == 52)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 107);
				cout << " M";
			}
			else if (map._map[y][x][i][j] == 3)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 106);
				cout << " T";
			}
			else if (map._map[y][x][i][j] == 4)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 166);
				cout << " " << char(134);
			}
			else if (map._map[y][x][i][j] == 5)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 110);
				cout << " !";
			}
			else if (map._map[y][x][i][j] == 7)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 105);
				cout << " " << char(177);
			}
			else if (map._map[y][x][i][j] == 6)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 111);
				cout << " @";
			}
			else if (map._map[y][x][i][j] == 8)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 155);
				cout << " ~";
			}
			else if (map._map[y][x][i][j] == 9)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 228);
				cout << " " << char(23);
			}
		}
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void GUI::drawLegend()
{
	// draw borders
	for (int i = 0; i < 28; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			if (i == 0 || i == 5 || i == 21 || i == 27 || j == 0 || j == 21 || j == 31) cout << " *";
			else cout << "  ";
		}
		cout << endl;
	}

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 45,1 });
	cout << "Arrows - move";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 45,2 });
	cout << "Space - use";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 45,3 });
	cout << "I - inventory";

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 49,6 });
	cout << "Items:";

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 3,22 });
	cout << "@ - brave dogman";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 3,23 });
	cout << "M - monster";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 3,24 });
	cout << "T - trader";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 3,25 });
	cout << "# - wall";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 3,26 });
	cout << char(134) << " - forest";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 23,22 });
	cout << "! - quest ";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 23,23 });
	cout << char(177) << " - the fountain";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 23,24 });
	cout << char(23) << " - chest";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 23,25 });
	cout << "~ - water";
}
