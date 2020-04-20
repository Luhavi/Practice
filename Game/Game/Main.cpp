#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include "screen.h"
#include "Gamedata.h"

snake s;
int x1,y1,x2,y2,x3,y3,x4,y4,x5,y5;
int dir;

void init() {
	s.HP = 1;
	s.x = 22;
	s.y = 8;
	x1 = s.x - 1, y1 = s.y;
	x2 = s.x - 2, y2 = s.y;
	x3 = s.x - 3, y3 = s.y;
	x4 = s.x - 4, y4 = s.y;
	x5 = s.x - 5, y5 = s.y;
	dir = 3;
}

void snakemove ( int num ) {
	clock_t curtime = clock();
	if (curtime > s.speed) {
		curtime = 0;
		if (num = 0) {
			s.y += 1;
		}
		else if (num = 1) {
			s.x -= 1;
		}
		else if (num = 2) {
			s.y -= 1;
		}
		else if (num = 3) {
			s.x += 1;
		}
	}
}

void snakerender (int x, int y) {
	x5 = x4;
	y5 = y4;
	x4 = x3;
	y4 = y3;
	x3 = x2;
	y3 = y2;
	x2 = x1;
	y2 = y1;
	x1 = x;
	y1 = y;

	ScreenPrint(x, y, "¡Ý");
	ScreenPrint(x1, y1, "¡Ý");
	ScreenPrint(x2, y2, "¡Ý");
	ScreenPrint(x3, y3, "¡Ý");
	ScreenPrint(x4, y4, "¡Ý");
	ScreenPrint(x5, y5, "¡Ý");
}

void Render() {
	ScreenFlipping();
	snakerender(s.x, s.y);

	ScreenClear();
}

void Update() {
	int key;

	if (kbhit() != 0)
	{
		key = getch();
		switch (key)
		{
		case 'w':if(dir != 2) dir = 0;
		case 'W':if (dir != 2) dir = 0;
		case 'a':if (dir != 3) dir = 1;
		case 'A':if (dir != 3) dir = 1;
		case 's':if (dir != 0) dir = 2;
		case 'S':if (dir != 0) dir = 2;
		case 'd':if (dir != 1) dir = 3;
		case 'D':if (dir != 1) dir = 3;
		default:
			break;
		}
	}
}

void Release() {

}

int main() {
	ScreenInit();
	init();
	while (1) {
		Update();
		Render();
	}
	Release();
	ScreenRelease();
}