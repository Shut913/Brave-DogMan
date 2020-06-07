#include "GUI.h"

GUI::GUI()
{
	system("mode con cols=59 lines=27"); // widow size 27x59
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	GetConsoleCursorInfo(hOut, &info);
	info.bVisible = false;
	SetConsoleCursorInfo(hOut, &info);
}

void GUI::drawInterface(const Map &map)
{
	// draw borders
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 29; j++)
		{
			if (i == 0 || i == 5||i==21 || i == 25 || j == 0 || j == 21 || j == 28) cout << " *";
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

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {46,6});
	cout << "Items:";

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 46,22 });
	cout << "Map coord:";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 48,23 });
	cout << "5:-3";
	int x = 1;
	int y = 1;
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


}
