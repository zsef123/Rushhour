/***************************
rush hour
OOP P final project
***************************/
#pragma comment(lib,"winmm.lib")
#include <iostream>
#include <conio.h>
#include "mouse.h"
#include <thread>
#include "Clock.h"

void gotoxy(int x, int y) {
	COORD pos = { (SHORT)x,(SHORT)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void introMenu() {
	std::cout << "Rush hour" << std::endl;
	getchar();
	gotoxy(0, 0);
}

void colorScreen(Stage *tmp) {
	gotoxy(0, 1);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			switch (tmp->_map[i][j]) {
			case 0:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 0);
				printf(" .");
				break;
			case 2:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15*16+12);
				printf("бс");
				break;
			case 3:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15*16+14);
				printf("бс");
				break;
			case 9:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15*16+7);
				printf("бс");
				break;
			default:
				printf("%d ", tmp->_map[i][j]);
				break;
			}
		}
		puts("");
	}
}

void bgMusic() {

}
int main() {
	introMenu();
	Stage stg[2];

	// loop in size of stage
	for (int i = 0; i < 2; i++) {
		stg[i].setCar();
		inputMouse a(stg[i].getCar());
		while (1) {
			if ( a.read()==1 )
				colorScreen(&stg[i]);

			if (stg[i]._map[3][7] != 0) {
				printf("GAME OVER");
				break;
			}
		}
	}

}