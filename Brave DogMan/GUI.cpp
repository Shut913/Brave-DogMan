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
	int* cell;
	key = _getch();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 102);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { short(unit.getUnitCoords()._x_Local*2+2),short(unit.getUnitCoords()._y_Local +6)});
	cout << "  ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	switch (key) {
	case (72):		// ^ - перемещение юнита вверх
		if (unit.getUnitCoords()._y_Local != 0)
		{
			cell = &map._map[unit.getUnitCoords()._y_Global][unit.getUnitCoords()._x_Global][unit.getUnitCoords()._y_Local - 1][unit.getUnitCoords()._x_Local];
			if (*cell ==0)
				unit.moveUnitCoords(-1, 0, map);
			else
			{
				interract(cell, map, unit);
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
			cell = &map._map[unit.getUnitCoords()._y_Global][unit.getUnitCoords()._x_Global][unit.getUnitCoords()._y_Local + 1][unit.getUnitCoords()._x_Local];
			if (*cell == 0)
				unit.moveUnitCoords(1, 0, map);
			else
			{
				interract(cell, map, unit);
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
			cell = &map._map[unit.getUnitCoords()._y_Global][unit.getUnitCoords()._x_Global][unit.getUnitCoords()._y_Local][unit.getUnitCoords()._x_Local - 1];
			if (*cell == 0)
				unit.moveUnitCoords(0, -1, map);
			else
			{
				interract(cell, map, unit);
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
			cell = &map._map[unit.getUnitCoords()._y_Global][unit.getUnitCoords()._x_Global][unit.getUnitCoords()._y_Local][unit.getUnitCoords()._x_Local + 1];
			if (*cell == 0)
				unit.moveUnitCoords(0, 1, map);
			else
			{
				interract(cell, map, unit);
			}
		}
		else
		{
			unit.moveUnitCoords(0, 1, map);
			drawInterface(map, unit);
		}
		break;
	case (105):		// I - инвентарь
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 111);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { short(unit.getUnitCoords()._x_Local * 2 + 2),short(unit.getUnitCoords()._y_Local + 6) });
		cout << " @";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

		unit.useInventory(false);
		drawUnitInfo(unit);
		drawUnitItems(unit);
		break;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 111);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { short(unit.getUnitCoords()._x_Local * 2 + 2),short(unit.getUnitCoords()._y_Local + 6 )});
	cout << " @";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void GUI::interract(int* cell, Map& map, Unit& unit)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 111);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { short(unit.getUnitCoords()._x_Local * 2 + 2),short(unit.getUnitCoords()._y_Local + 6) });
	cout << " @";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	switch (*cell)
	{
	case 2: // monsters
	case 12:
	case 22:
	case 32:
	case 42:
	{
		if (drawFightWindow(unit, cell)) *cell = 0;
		if (unit.getCurHp() == 0) throw "GAME OVER!";
		drawLegend();
		drawGameWindow(map, unit);
	}
		break;
	case 3: // trader
	{
		for (int i = 0; i < 15; i++)
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 2,short(6 + i) });
			for (int j = 0; j < 20; j++)
			{
				cout << "  ";
			}
		}

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 20,7 });
		cout << "Trader";
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 3,9 });
		cout << "Do you want buy this item? (Yes/No/Sell)";
		
		static int randomItem = 0;
		randomItem++;
		if (randomItem == 5) randomItem = 1;
		Food* f = nullptr;
		Armor* a = nullptr;
		Amulet* am = nullptr;
		Weapon* w = nullptr;

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 14,11 });
		switch (randomItem)
		{
		case 1:
		{
			int randFood = rand() % 4;
			switch (randFood)
			{
			case 0:
				f = new Apple;
				break;
			case 1:
				f = new Beer;
				break;
			case 2:
				f = new Bread;
				break;
			case 3:
				f = new HpPotion;
				break;
			}
			cout << f->getName() << " - " << f->getCost() << "g.";
			break;
		}
		case 2:
		{
			int randArmor = rand() % 3;
			switch (randArmor)
			{
			case 0:
				a = new LeatherArmor;
				break;
			case 1:
				a = new SteelArmor;
				break;
			case 2:
				a = new DiamondArmor;
				break;
			}
			cout << a->getName() << " - " << a->getCost() << "g.";
			break;
		}
		case 3:
		{
			int randAmulet = rand() % 2;
			switch (randAmulet)
			{
			case 0:
				am = new AmuletOfDefence;
				break;
			case 1:
				am = new AmuletOfPower;
				break;
			}
			cout << am->getName() << " - " << am->getCost() << "g.";
			break;
		}
		case 4:
		{
			int randWeapon = rand() % 2;
			switch (randWeapon)
			{
			case 0:
				w = new Knife;
				break;
			case 1:
				w = new Sword;
				break;
			}
			cout << w->getName() << " - " << w->getCost() << "g.";
			break;
		}
		}

		switch ((int)_getch())
		{
		case 115: // s - sell
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 45,2 });
			cout << "Space - sell item";
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 45,4 });
			cout << "B - buy item";
			unit.useInventory(true);
			break;
		case 121: // y - yes
			switch (randomItem)
			{
			case 1:
				if (f->getCost() < unit.getMoney())
				{
					unit.take(f);
					unit.take(-f->getCost());
				}
				else delete f;
				break;
			case 2:
				if (a->getCost() < unit.getMoney())
				{
					unit.take(a);
					unit.take(-a->getCost());
				}
				else delete a;
				break;
			case 3:
				if (am->getCost() < unit.getMoney())
				{
					unit.take(am);
					unit.take(-am->getCost());
				}
				else delete am;
				break;
			case 4:
				if (w->getCost() < unit.getMoney())
				{
					unit.take(w);
					unit.take(-w->getCost());
				}
				else delete am;
				break;
			}
			break;
			default:
				delete f;
				delete a;
				delete am;
				delete w;
			break;
		}

		drawInterface(map, unit);
	}
		break;
	case 4:  // forest
		if (rand()%20==10)
		{	Apple* a = new Apple;
			unit.take(a);
			drawUnitItems(unit);
		}
		break;
	case 5: // info
	{
		for (int i = 0; i < 15; i++)
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 2,short(6 + i) });
			for (int j = 0; j < 20; j++)
			{
				cout << "  ";
			}
		}
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 20,7 });
		cout << "Stranger";

		int randomInfo = rand() % 10 + 1;

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 3,9 });
		switch (randomInfo)
		{
		case 1:
			cout << "On trees you can find some apples";
			break;
		case 2:
			cout << "If you lost all your hit points,";
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 3,10 });
			cout << "you will die";
			break;
		case 3:
			cout << "Finally there is a hero, who could";
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 3,10 });
			cout << "defeat the dragon";
			break;
		case 4:
			cout << "In the chests you can find amulets,";
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 3,10 });
			cout << "food, armor and weapons";
			break;
		case 5:
			cout << "Hi wanderer, how are you?";
			break;
		case 6:
			cout << "I advise you to carry food to";
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 3,10 });
			cout << "restore health in battle";
			break;
		case 7:
			cout << "Good armor will help you in battle";
			break;
		case 8:
			cout << "If the enemy is very strong, you";
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 3,10 });
			cout << "can just run away from him";
			break;
		case 9:
			cout << "You can restore health at the";
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 3,10 });
			cout << "fountain";
			break;
		case 10:
			cout << "What a wonderful day, isn't it?";
			break;
		}
		_getch();
		drawGameWindow(map, unit);
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
		if (randomLoot <= 30) unit.take(rand() % 20 + 5);
		else if (randomLoot > 30 && randomLoot <= 50)
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
		else if (randomLoot > 50 && randomLoot <= 55)
		{
			Knife* k = new Knife;
			unit.take(k);
			unit.take(rand() % 20 + 5);
		}
		else if (randomLoot > 55 && randomLoot <= 60)
		{
			Sword* s = new Sword;
			unit.take(s);
			unit.take(rand() % 20 + 5);
		}
		else if (randomLoot >60 && randomLoot <= 65)
		{
			Bread* b = new Bread;
			unit.take(b);
			unit.take(rand() % 20 + 5);
		}
		else if (randomLoot > 65 && randomLoot <= 70)
		{
			LeatherArmor* l = new LeatherArmor;
			unit.take(l);
			unit.take(rand() % 20 + 5);
		}
		else if (randomLoot > 70 && randomLoot <= 75)
		{
			SteelArmor* s = new SteelArmor;
			unit.take(s);
			unit.take(rand() % 20 + 5);
		}
		else if (randomLoot > 80 && randomLoot <= 85)
		{
			DiamondArmor* d = new DiamondArmor;
			unit.take(d);
			unit.take(rand() % 20 + 5);
		}
		else if (randomLoot > 85 && randomLoot <= 90)
		{
			AmuletOfDefence* a = new AmuletOfDefence;
			unit.take(a);
			unit.take(rand() % 20 + 5);
		}
		else if (randomLoot > 90 && randomLoot <= 95)
		{
			AmuletOfHealth* a = new AmuletOfHealth;
			unit.take(a);
			unit.take(rand() % 20 + 5);
		}
		else if (randomLoot > 95 && randomLoot <= 100)
		{
			AmuletOfPower* a = new AmuletOfPower;
			unit.take(a);
			unit.take(rand() % 20 + 5);
		}
		*cell = 0;
		drawGameWindow(map,unit);
	}
		break;
	}

	drawUnitInfo(unit);

	drawUnitItems(unit);
}

void GUI::drawUnitInfo(Unit& unit)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 3,1 });
	cout << "HP: "<<unit.getCurHp()<<'('<<unit.getMaxHp()<<')'<<"   ";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 3,2 });
	cout << "Weapon: "<<unit.getCurWeapon();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 3,3 });
	cout << "Armor: " << unit.getCurArmor();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 3,4 });
	cout << "Amulet: " << unit.getCurAmulet();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 27,1 });
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
	cout << y << ':' << x;

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
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "M";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << " - monster";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 3,24 });
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << "T";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << " - trader";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 3,25 });
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
	cout << "#";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << " - wall";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 3,26 });
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 166);
	cout << char(134);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout <<" - forest";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 23,22 });
	cout << "! - info";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 23,23 });
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	cout << char(177);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout <<" - the fountain";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 23,24 });
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 228);
	cout << char(23) ;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << " - chest";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 23,25 });
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 155);
	cout << "~";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << " - water";
}

bool GUI::drawFightWindow(Unit& unit, int* cell)
{
	Enemy* enemy=nullptr;
	switch (*cell)
	{
		case 2:
			enemy = new Wolf;
			break;
		case 12:
			enemy = new Goblin;
			break;
		case 22:
			enemy = new Skeleton;
			break;
		case 32:
			enemy = new Bandit;
			break;
		case 42:
			enemy = new Dragon;
			break;
	}

	while(true)
	{
		for (int i = 0; i < 15; i++)
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 2,short(6 + i) });
				for (int j = 0; j < 20; j++)
				{
					cout << "  ";
				}
			}

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 45,1 });
		cout << "E - escape     ";
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 45,2 });
		cout << "Space - attack";

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 10,7 });
		cout << "YOU";
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 27,7 });
		cout << "ENEMY";
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 27,8 });
		cout <<'(' << enemy->getName() << ')';
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 6,9 });
		cout <<"HP: "<< unit.getCurHp()<<'('<<unit.getMaxHp()<<')';
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 23,9 });
		cout << "HP: " << enemy->getCurHp() << '(' << enemy->getMaxHp() << ')';
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 5,10 });
		cout << "Atk: "<<unit.attackPower();
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 22,10 });
		cout << "Atk: "<<enemy->attackPower();
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 5,11 });
		cout << "Def: " << unit.getDef();


		switch (_getch()) 
		{
		case (105):		// I - инвентарь
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 45,2 });
			cout << "Space - use    ";
			unit.useInventory(false);
			drawUnitInfo(unit);
			drawUnitItems(unit);
			break;
		case (32):		// space - атаковать
			unit.attack(enemy);
			enemy->attack(unit);
			drawUnitInfo(unit);
			break;
		case (101):		// E - сбежать
			delete enemy;
			return false;
			break;
		case (27):		// ESC - выход в меню
			delete enemy;
			return false;
			break;
		}

		if (enemy->getCurHp() == 0)
		{
			enemy->giveLoot(unit);
			delete enemy;
			return true;
		}
		if (unit.getCurHp() == 0)
		{
			delete enemy;
			return false;
		}
	};
}

void GUI::beginText()
{
	cout << endl << "\t\t\t Story of Brave DogMan";
	cout << endl<<endl << " Once upon a time, many years ago, there was a city."<<endl
		<< " Its simple inhabitants led a measured life" << endl
		<< " Now ... Now the city was gone. Only ruins remained." << endl
		<< " The dead city has new, creepy inhabitants." << endl
		<< " There are almost no people left." << endl
		<< " --------------------------------------" << endl
		<< " Something huge, swiftand furious, possessing" << endl
		<< " monstrous force ... Something rushed at DogMan from behind, clawing" << endl
		<< " clothes. DogMan drove the sword into the monster and" << endl
		<< " cranked there a couple of times." << endl
		<< " It seems that after this he cooled down and ... retreated ?" << endl
		<< " After the creature left with a sword in its side," << endl
		<< " DogMan was unconscious for a while." << endl
		<< " Realized himself already wandering around the city." << endl;
	_getch();
}
