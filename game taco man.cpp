#include <iostream>
#include <cmath>
#include <Windows.h>
#include <conio.h>
#include <ctime>

using namespace std;
const int col = 134, row = 31;
const int modes = 7;
const int sizeY = 10, sizeX = 10;

void randomize() {
	srand((unsigned int)time(nullptr));
}
int random(int max, int min = 1) {
	return int(((double)rand() / RAND_MAX)*(1 + max - min) + min);
}

void upDoor(char room[row][col], int e) {
	int no = 0;
	char upDoor[][2][20] = {
	{
		{ "               "},
		{ "_______________" },
	},
	{
		{ "  |    W    |  " },
		{ "__|         |__" },
	},
	{
		{ "  |    W    |  " },
		{ "__|_&_______|__" },
	},
	{
		{ "  |    W    |  " },
		{ "__|         |__" },
	},
	{
		{ " B|    W    |B " },
		{ "__|         |__" },
	},

	};
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			room[1 + i][col / 2 - 10 + j] = upDoor[e][i][j];
		}
	}
}
void downDoor(char room[row][col], int e) {
	int no = 0;
	char upDoor[][3][20] = {
		{
			{ "________________" },
			{ "                " },
			{ "________________" },
		},
		{
			{ "__            __" },
			{ "  |     S    |  " },
			{ "__|__________|__"},
		},
		{
			{ "________________" },
			{ "  | &   S    |  " },
			{ "__|__________|__" },
		},
		{
			{ "__            __" },
			{ " B|     S    |B " },
			{ "__|__________|__" },
		},
	};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			room[row - 4 + i][col / 2 - 10 + j] = upDoor[e][i][j];
		}
	}
}
void leftDoor(char room[row][col], int e) {
	int no = 0;
	char upDoor[][8][10] = {
		{
			{ "    |" },
			{ "    |" },
			{ "    |" },
			{ "    |" },
			{ "    |" },
			{ "    |" },
			{ "    |" },
			{ "    |" },
		},
		{
			{ "    |" },
			{ "____|" },
			{ "     " },
			{ "     " },
			{ "A    " },
			{ "     " },
			{ "____ " },
			{ "    |" },
		},
		{
			{ "    |" },
			{ "____|" },
			{ "   &|" },
			{ "    |" },
			{ "A   |" },
			{ "    |" },
			{ "____|" },
			{ "    |" },

		},
	{
		{ "    |" },
		{ "___B|" },
		{ "     " },
		{ "     " },
		{ "A    " },
		{ "     " },
		{ "____ " },
		{ "   B|" },
	},
	};
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			room[row / 2 - 4 + i][1 + j] = upDoor[e][i][j];
		}
	}
}
void rightDoor(char room[row][col], int e) {
	int no = 0;
	char upDoor[][8][6] = {
		{
			{ "|    " },
			{ "|    " },
			{ "|    " },
			{ "|    " },
			{ "|    " },
			{ "|    " },
			{ "|    " },
			{ "|    " },

		},
		{
			{ "|    " },
			{ "|____" },
			{ "     " },
			{ "     " },
			{ "    D" },
			{ "     " },
			{ " ____" },
			{ "|    " },
		},
		{
			{ "|    " },
			{ "|____" },
			{ "|&   " },
			{ "|    " },
			{ "|   D" },
			{ "|    " },
			{ "|____" },
			{ "|    " },
		},
		{
			{ "|    " },
			{ "|B___" },
			{ "     " },
			{ "     " },
			{ "    D" },
			{ "     " },
			{ " ____" },
			{ "|B   " },
		},
	};
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			room[row / 2 - 5 + i][col - 18 + j] = upDoor[e][i][j];
		}
	}
}

void gameOver() {
	system("cls");
		cout << "GAME OVER!";
		system("pause");
}
void printRoom(char room[row][col]) {
	system("cls");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << room[i][j];



		}
		cout << endl;
	}
}

int addToView(char room[row][col], int ch, int placeX, int placeY) {
	int x = 6+placeX*10;
	int y = 3+placeY*5;
	
	char items[][5][11] = {
		{ { "          " },
		{ "          " },
		{ "          " },
		{ "          " },
		{ "          " }, 
		},
		{
			{ " Q        " },
			{ "          " },
			{ " /\\__|__| " },
			{ " \\/       " },
			{ "          "},
		},
	{
		{ "Q **   ** " },
		{ " *  * *  *" },
		{ "  *  *  * " },
		{ "   *   *  " },
		{ "    ***   " },
	},
	{
		{ "Q         " },
		{ "   ____   " },
		{ " /______\\ " },
		{ "|        |" },
		{ "|________|" },
	},
	{
		{ "E         " },
		{ "          " },
		{ " SPEED UP " },
		{ "$$$$$$$$$$" },
		{ "    $$    " },
	},
	{
		{ "E         " },
		{ "  SUPER   " },
		{ " SPEED UP " },
		{ "$$$$$$$$$$" },
		{ "    $$    " },
	},
	{
		{ "E         " },
		{ "          " },
		{ "DEMAGE UP " },
		{ "$$$$$$$$$$" },
		{ "    $$    " },
	},
	{
		{ "E         " },
		{ "   SUPER  " },
		{ "DEMAGE UP " },
		{ "$$$$$$$$$$" },
		{ "    $$    " },
	},
	{
		{ "E         " },
		{ "          " },
		{ "  HP UP   " },
		{ "$$$$$$$$$$" },
		{ "    $$    " },
	},
	{
		{ "E         " },
		{ "          " },
		{ "  !STAR!  " },
		{ "$$$$$$$$$$" },
		{ "    $$    " },
	},
	};
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			room[y + i][x + j] = items[ch][i][j];
		}
	}
	return ch;
}

void roomMiniMap(int x, int y, int mapMode[modes][sizeY][sizeX], char room[row][col]) {
	switch (mapMode[0][y][x]) {
	case 1: if (mapMode[1][y][x]) room[1 + y][123 + x] = 'O'; else room[1 + y][123 + x] = 'o'; break;
	case 2: room[1 + y][123 + x] = 'S'; break;
	case 3: room[1 + y][123 + x] = '*'; break;

	}
}

void write(char room[row][col], char message[20], int x, int y, int clean = 1, int time = 2000) {
	if (clean == 0) {
		for (int i = 0; i < 20; i++)
		{
			room[y][x + i] = ' ';
		}
	}
	else {
		for (int i = 0; i < 20; i++)
		{
			room[y][x + i] = message[i];
		}
	}
	printRoom(room);
	if (clean == 2) {
		Sleep(time);
		for (int i = 0; i < 20; i++)
		{
			room[y][x + i] = ' ';
		}
		printRoom(room);
	}
}

void createFight(char room[row][col], int mapMode[modes][sizeY][sizeX],int no) {
	int x = 16, y = 11, x1 = x + 82;
	char duck;
	int mes;
	char duckMessage[][20] = {
		{ "unik: z" },
		{ "unik: x" },
		{ "unik: c" },
		{"unik: v"},
	};
	char message[][20] = {
		{ "unik: z" },
		{ "unik udany" },
		{ "oberwales" },
		{ "atakujesz" },
		{"WYGRANA!"},
		{"WALKA!"},
		{"- <3"}
	};
	int fighterStat[][2] = {
		{ 5,1 },
		{ 3,3 },
		{ 7,3 },
		{ 4,4 },
	};// odpornoœæ, szybkoœæ
	char fighterView[][5][11] = {
	{
		{"  ******  "},
		{"**  ***  *"},
		{"  ******  "},
		{" X      X "},
		{"X        X"}
	},
	{
		{ "   ^   ^  " },
		{ "     *    " },
		{ "  ^^^^^^  " },
		{ "^^^^^^^^^^" },
		{ "  ^^^^^^  " },
	},
	{
		{ "  ^    ^  "},
		{ "  |____|  " },
		{ "   >  <   " },
		{ "   ____   " },
		{ "    ||    " }
	},
	{
		{ "**********" },
		{ "**  ***  *" },
		{ "**********" },
		{ "**      **" },
		{ "**********" }
	},

	};

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			room[13 + i][96 + j] = fighterView[no][i][j];
		}
	}
	printRoom(room);

	write(room, message[5], x + 35, y - 5, 2, 2000);
	int hard = mapMode[2][1][1] - fighterStat[no][1];
	int t=1000;
	for (int i = 0; i <= abs(hard); i++)
	{
		if (hard < 0) t *= 0.9;
		else t *= 1.1;
	}
	for (int i = fighterStat[no][0] / mapMode[2][1][0]; i > 0; i--)
	{
		switch(mes = random(3, 0)) {
	case 0: duck = 'z'; break;
	case 1: duck = 'x'; break;
	case 2: duck = 'c'; break;
	case 3: duck = 'v'; break;
		}
		cout << endl << i << endl << fighterStat[no][0] / mapMode[2][1][0];
		if (mapMode[2][1][1] >= fighterStat[no][1]) {
			write(room, message[3], x, y, 2, 500);
			write(room, message[6], x1, y, 2, 800);
			if (i == 1) {
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 11; j++)
					{
						room[13 + i][96 + j] = ' ';
					}

				}
				printRoom(room);
				write(room, message[4], x + 35, y - 5, 2, 2000);
				break;
			}


			
			write(room, duckMessage[mes], x, y, 2, t);

			if (_kbhit() && _getch() == duck) {
				cout << "ok";
				write(room, message[1], x, y, 2, 2000);
			}
			else {
				--mapMode[2][0][1];
				write(room, message[2], x, y, 2, 1000);
				room[1][15] = (char)(48 + mapMode[2][0][1]);
				room[1][17] = (char)(48 + mapMode[2][0][2]);
				write(room, message[6], x, y, 2, 1000);
			}
			if (mapMode[2][0][1] == 0) gameOver();


		}
		else {
			write(room, duckMessage[mes], x, y, 2, t);

			if (_kbhit() && _getch() == duck) {
				cout << "ok";
				write(room, message[1], x, y, 2, 2000);
			}
			else {
				--mapMode[2][0][1];
				write(room, message[2], x, y, 2, 1000);
				room[1][15] = (char)(48 + mapMode[2][0][1]);
				room[1][17] = (char)(48 + mapMode[2][0][2]);
				write(room, message[6], x, y, 2, 1000);
			}
			if (mapMode[2][0][1] == 0) gameOver();

	
				write(room, message[3], x, y, 2, 1000);
				write(room, message[6], x1, y, 2, 1000);
				if (i == 1) {
					for (int i = 0; i < 5; i++)
					{
						for (int j = 0; j < 11; j++)
						{
							room[13 + i][96 + j] = ' ';
						}

					}
					printRoom(room);
					write(room, message[4], x + 35, y - 5, 2, 2000);
					break;
				}
			
		}
	}
}

void createRoom(int mapMode[modes][sizeY][sizeX], char room[row][col], int x, int y) {
	int xx;
	upDoor(room, mapMode[0][y - 1][x]);
	roomMiniMap(x, y - 1, mapMode, room);


	downDoor(room, mapMode[0][y + 1][x]);
	roomMiniMap(x, y + 1, mapMode, room);


	leftDoor(room, mapMode[0][y][x - 1]);
	roomMiniMap(x - 1, y, mapMode, room);


	rightDoor(room, mapMode[0][y][x + 1]);
	roomMiniMap(x + 1, y, mapMode, room);
	addToView(room, 0, 5, 2);

	room[1 + y][123 + x] = 'X';

	room[1][9] = (char)(48 + mapMode[2][0][0]);
	room[1][15] = (char)(48 + mapMode[2][0][1]);
	room[1][17] = (char)(48 + mapMode[2][0][2]);
	if (mapMode[1][y][x] == 0 && random(3) == 1 && mapMode[0][y][x] == 1) {
		createFight(room, mapMode, random(1,0));
		xx = (addToView(room, random(2, 1), 5, 2)+2);
		mapMode[xx][y][x]++;
	}
	if (mapMode[1][y][x] == 0 && mapMode[0][y][x] == 3) {
		createFight(room, mapMode, random(3, 2));
		xx = (addToView(room, random(4,9), 5, 2));
		mapMode[6][y][x] = xx;
	}
	if (mapMode[1][y][x] == 0 && random(3) == 1 && mapMode[0][y][x] == 1) {
		createFight(room, mapMode, random(1, 0));
		xx = (addToView(room, random(2, 1), 5, 2) + 2);
		mapMode[xx][y][x]++;
	}
	for (int i = 3; i <6; i++)

	{
		if (mapMode[i][y][x] > 0) { int xx = addToView(room, i - 2, 5, 2); break; }
	}
	if (mapMode[0][y][x] == 2 && mapMode[1][y][x] == 0) {
		
		mapMode[6][y][x] = addToView(room, random(9, 4), 5, 2);
	} else if(mapMode[0][y][x] == 2 && mapMode[0][y][x] == 1) addToView(room, mapMode[6][y][x], 5, 2);
	mapMode[1][y][x] = 1;
	
	printRoom(room);


}

void createMap(int mapMode[modes][sizeY][sizeX], int *x, int *y) {
	int no = 0;
	*x = 4;
	*y = 4;
	int maps[][sizeY][sizeX] = {
		{
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,1,0,0,0,0,0,0 },
			{ 0,0,0,1,1,1,2,0,0,0 },
			{ 0,0,3,0,1,0,0,0,0,0 },
			{ 0,1,1,1,1,1,1,1,0,0 },
			{ 0,1,0,0,1,0,1,0,0,0 },
			{ 0,2,0,0,1,1,1,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
		},//mapa
		{
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,1,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
		},//odwiedziny
		{
			{ 0,6,6,0,0,0,0,0,0,0 },//klucze, zycie, mozliwe zycia
			{ 1,1,0,0,0,0,0,0,0,0 },//atak, szybkosc
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
		},//staty
		{
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
		},//klucze na mapie
		{
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
		},//serca na mapie
		{
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
		},//skrzynki na mapie
		{
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0 },
		},//itemy na mapie
	};

	for (int k = 0; k < modes; k++) {
		for (int i = 0; i < sizeY; i++)
		{
			for (int j = 0; j < sizeX; j++)
			{
				mapMode[k][i][j] = maps[k][i][j];
			}
		}
	}
}

void move(int *x, int *y, int moveX, int moveY, int mapMode[modes][sizeY][sizeX], char room[row][col]) {
	switch (mapMode[0][(*y) + moveY][(*x) + moveX]) {
	case 1:
		mapMode[0][(*y) + moveY][(*x) + moveX] = 1;
		createRoom(mapMode, room, (*x) += moveX, (*y) += moveY);
		break;
	case 2:
		if (mapMode[1][(*y) + moveY][(*x) + moveX] == 0) {
			if (mapMode[2][0][0] > 0) {
				room[1][9] = (char)(48 + --mapMode[2][0][0]);
				/*mapMode[0][(*y) + moveY][(*x) + moveX] = 3;*/
				createRoom(mapMode, room, (*x) += moveX, (*y) += moveY);
			}
		}else { 
		createRoom(mapMode, room, (*x) += moveX, (*y) += moveY);
		}
		break;
	case 3:
		mapMode[0][(*y) + moveY][(*x) + moveX] = 3;
		createRoom(mapMode, room, (*x) += moveX, (*y) += moveY);
	default: break;
	}
}

void pilot(char act, int *x, int *y, int mapMode[modes][sizeY][sizeX], char room[row][col]) {
	switch (act) {
	case 'w': move(x, y, 0, -1, mapMode, room); break;
	case 's': move(x, y, 0, 1, mapMode, room); break;
	case 'a': move(x, y, -1, 0, mapMode, room);  break;
	case 'd': move(x, y, 1, 0, mapMode, room); break;
	case 'q': 
		if (mapMode[0][*y][*x] == 1) {
			for (int i = 3; i < 5; i++)
			{

				if (mapMode[i][*y][*x] > 0) {
					if (mapMode[2][0][0] == 9)--mapMode[2][0][0];
					if (mapMode[2][0][1] == mapMode[2][0][2])--mapMode[2][0][1];
					if (i == 3)room[1][9] = (char)(48 + ++mapMode[2][0][i - 3]);
					if (i == 4)room[1][15] = (char)(48 + ++mapMode[2][0][i - 3]);
					--mapMode[i][*y][*x];
					addToView(room, 0, 5, 2);
					createRoom(mapMode, room, *x, *y);
					break;
				}
			}
		}
		break;
	case 'e': 
		switch (mapMode[6][*y][*x]) {
		case 4: mapMode[2][1][1]++; mapMode[6][*y][*x] = 0; addToView(room, 0, 5, 2); printRoom(room); break;
	case 5:  mapMode[2][1][1]+=2; mapMode[6][*y][*x] = 0; addToView(room, 0, 5, 2); printRoom(room); break;
	case 6:  mapMode[2][1][0]++; mapMode[6][*y][*x] = 0; addToView(room, 0, 5, 2); printRoom(room); break;
	case 7: mapMode[2][1][0]+=2; mapMode[6][*y][*x] = 0; addToView(room, 0, 5, 2); printRoom(room); break;
	case 8: mapMode[2][0][1]++; mapMode[2][0][2]++;  mapMode[6][*y][*x] = 0; addToView(room, 0, 5, 2); printRoom(room); room[1][15] = (char)(48 + mapMode[2][0][1]);
		room[1][17] = (char)(48 + mapMode[2][0][2]); break;
	case 9: mapMode[2][0][1]++; mapMode[2][0][2]++;  mapMode[2][1][1]++;  mapMode[6][*y][*x] = 0; mapMode[2][1][0]++; addToView(room, 0, 5, 2); printRoom(room); room[1][15] = (char)(48 + mapMode[2][0][1]);
		room[1][17] = (char)(48 + mapMode[2][0][2]); break;
	default: break;
	}
		break; 
	
	default: break;
	}
}
int main()
{
	randomize();
	int mapMode[modes][sizeY][sizeX];
	int heroStat[] = { 1,1,1,1 };
	char action;
	int posX, posY;
	bool next = false;
	char room[row][col] = {
		{ " ________________________________________________________________________________________________________________________ __________ " },
		{ "|      &x   <3x /                                                                                                        |          |" },
		{ "|     ______________________________________________________________________________________________________________     |          |" },
		{ "|    |                                                                                                              |    |          |" },
		{ "|    |                                                                                                              |    |          |" },
		{ "|    |                                                                                                              |    |          |" },
		{ "|    |                                                                                                              |    |          |" },
		{ "|    |                                                                                                              |    |          |" },
		{ "|    |                                                                                                              |    |          |" },
		{ "|    |                                                                                                              |    |          |" },
		{ "|    |                                                                                                              |    |          |" },
		{ "|    |                                                                                                              |    |__________|" },
		{ "|    |                                                                                                              |    |" },
		{ "|    |         xxxxxxxxxx                                                                                           |    |" },
		{ "|    |             xx                                                                                               |    |" },
		{ "|    |           x    x                                                                                             |    |" },
		{ "|    |            xxxx                                                                                              |    |" },
		{ "|    |            x  x                                                                                              |    |" },
		{ "|    |                                                                                                              |    |" },
		{ "|    |                                                                                                              |    |" },
		{ "|    |                                                                                                              |    |" },
		{ "|    |                                                                                                              |    |" },
		{ "|    |                                                                                                              |    |" },
		{ "|    |                                                                                                              |    |" },
		{ "|    |                                                                                                              |    |" },
		{ "|    |                                                                                                              |    |" },
		{ "|    |                                                                                                              |    |" },
		{ "|    |______________________________________________________________________________________________________________|    |"},
		{ "|                                                                                                                        |" },
		{ "|________________________________________________________________________________________________________________________|" },

	};
	for (int i = 0; i < 1; i++) {
		createMap(mapMode, &posX, &posY);
		createRoom(mapMode, room, posX, posY);
		do {
			action = _getch();
			pilot(action, &posX, &posY, mapMode, room);
			cout << posX << posY <<  mapMode[6][posY][posX];
		} while (next == false);
	}
	cin.get();
	return 0;
}
