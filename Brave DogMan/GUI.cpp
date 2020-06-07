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

void GUI::drawInterface(const Map &map, Unit& unit)
{
	system("cls");
	// draw borders
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			if (i == 0 || i == 5||i==21 || i == 25 || j == 0 || j == 21 || j == 31) cout << " *";
			else cout << "  ";
		}
		cout << endl;
	}
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 3,1 });
	cout << "Arrows - move";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 3,2 });
	cout << "Space - use";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 3,3 });
	cout << "I - inventory";

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 45,1 });
	cout << "HP: 100(100)";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 45,2 });
	cout << "ARM: 50";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 45,3 });
	cout << "Use: Sword";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 45,4 });
	cout << "Gold: 1000";

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {49,6});
	cout << "Items:";

	int x = unit.getUnitCoords()._x_Global;
	int y = unit.getUnitCoords()._y_Global;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 49,22 });
	cout << "Map coord:";

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 51,23 });
	cout << x <<':'<< y;

	for (int i = 0; i < 15; i++)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 2,short(6+i) });
		for (int j = 0; j < 20; j++)
		{
			if (map._map[y][x][i][j] == 0) cout << "  ";
			else if (map._map[y][x][i][j] == 1) cout << " #";
			else if (map._map[y][x][i][j] == 2|| 
				map._map[y][x][i][j] == 12|| 
					map._map[y][x][i][j] == 22|| 
						map._map[y][x][i][j] == 32|| 
							map._map[y][x][i][j] == 42|| 
								map._map[y][x][i][j] == 52) cout << " M";
			else if (map._map[y][x][i][j] == 3) cout << " T";
			else if (map._map[y][x][i][j] == 4) cout << " " << char(134);
			else if (map._map[y][x][i][j] == 5) cout << " !";
			else if (map._map[y][x][i][j] == 7) cout << " " << char(177);
			else if (map._map[y][x][i][j] == 6) cout << " @";
			else if (map._map[y][x][i][j] == 8) cout << " ~";
			else if (map._map[y][x][i][j] == 9) cout << " " << char(23);
		}
	}

	unit.showBackpack();
}

void GUI::control(Map& map, Unit& unit)
{
	int key;
	key = _getch();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { short(unit.getUnitCoords()._x_Local*2+2),short(unit.getUnitCoords()._y_Local +6)});
	cout << "  ";
	switch (key) {
	case (72):		// ^ - перемещение юнита вверх
		if (unit.getUnitCoords()._y_Local != 0)
		{
			if (map._map[unit.getUnitCoords()._y_Global][unit.getUnitCoords()._x_Global][unit.getUnitCoords()._y_Local-1][unit.getUnitCoords()._x_Local]==0)
				unit.moveUnitCoords(-1, 0, map);
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
			if (map._map[unit.getUnitCoords()._y_Global][unit.getUnitCoords()._x_Global][unit.getUnitCoords()._y_Local + 1][unit.getUnitCoords()._x_Local] == 0)
				unit.moveUnitCoords(1, 0, map);
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
			if (map._map[unit.getUnitCoords()._y_Global][unit.getUnitCoords()._x_Global][unit.getUnitCoords()._y_Local][unit.getUnitCoords()._x_Local-1] == 0)
				unit.moveUnitCoords(0, -1, map);
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
			if (map._map[unit.getUnitCoords()._y_Global][unit.getUnitCoords()._x_Global][unit.getUnitCoords()._y_Local][unit.getUnitCoords()._x_Local + 1] == 0)
				unit.moveUnitCoords(0, 1, map);
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

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { short(unit.getUnitCoords()._x_Local * 2 + 2),short(unit.getUnitCoords()._y_Local + 6 )});
	cout << " @";
}
