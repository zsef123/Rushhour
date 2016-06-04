/***************************
rush hour
OOP P final project
***************************/
#pragma comment(lib,"winmm.lib")
#include <iostream>
#include <conio.h>
#include "mouse.h"
int cur_X=1, cur_Y=1;
// in main 
int selectFlag = 0;
int cur_Car;
COORD prev;

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

void printScreen(Stage *tmp) {
	gotoxy(0, 0);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15*16);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
			printf("%d ", tmp->_map[i][j]);
		puts("");
	}
	printf("cur_X: %d, cur_Y: %d\n", cur_X, cur_Y);
	printf("sFlag: %d, curCar: %d\n\n", selectFlag, cur_Car);

	colorScreen(tmp);
}
/*
void stageSetting() {
	cars[0].setInfo(2, 0);
	cars[0].setPosition(2, 3);

	cars[1].setPosition(1, 1); 
	cars[1].setInfo(2, 0);

	cars[2].setPosition(1, 2);
	cars[2].setInfo(3, 1);

	cars[3].setPosition(1, 5);
	cars[3].setInfo(2, 1)

	cars[4].setPosition(4, 2);
	cars[4].setInfo(3, 1);

	cars[5].setPosition(6, 1);
	cars[5].setInfo(3, 1);

	cars[6].setPosition(5, 5);
	cars[6].setInfo(2, 0);

	cars[7].setPosition(3, 6);
	cars[7].setInfo(3, 0);

	for (int i = 0; i < sizeof(cars) / sizeof(Car); i++)
		stg.drawCar(cars[i], 1);
}
*/

int main() {
	introMenu();
	Stage stg[2];
	
	for (int i = 0; i < 2; i++) {
		stg[i].setCar();
		inputMouse a(stg[i].getCar());
		while (1) {
			a.read();

			printScreen(&stg[i]);
			if (stg[i]._map[3][7] != 0) {
				printf("GAME OVER");
				break;
			}
		}
	}
	
}