/***************************
rush hour
OOP P final project
***************************/

#include <iostream>
#include <conio.h>
#include <windows.h>
#include "stage.h"

int cur_X=1, cur_Y=1;
// in main 
int selectFlag = 0;
int cur_Car;
Car cars[8];
Stage stg(cars);
COORD prev;

int moveCur(int key,int *cur) {
	switch(key) {
		// operator로 바꿀수있지않을까 범위 초과부분을 
	case up:
		cur_Y--;
		if (cur_Y == 0 ) cur_Y=6;
		break;
	case down:
		cur_Y++;
		if ( cur_Y == 7) cur_Y=1;
		break;
	case left:
		cur_X--;
		if ( cur_X == 0) cur_X=6;
		break;
	case right:
		cur_X++;
		if ( cur_X == 7) cur_X=1;
		break;
	case choice:
		int i;
		// my car를 0 index로 하던가해야지
		for (i = 0; i < sizeof(cars) / sizeof(Car) ; i++) {
			if (cars[i].isSelect(cur_X,cur_Y) == 1) {
				*cur = i;
				return 1;
			}
		}
		break;
	default:
		break;
	}
	return 0;
}

void gotoxy(int x, int y) {
	COORD pos = { (SHORT)x,(SHORT)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void introMenu() {
	std::cout << "Rush hour" << std::endl;
	getchar();
	gotoxy(0, 0);
}

void colorScreen() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			switch (_map[i][j]) {
			case 0:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 0);
				printf(" .");
				break;
			case 2:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15*16+12);
				printf("■");
				break;
			case 3:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15*16+14);
				printf("■");
				break;
			case 9:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15*16+7);
				printf("■");
				break;
			default:
				printf("%d ", _map[i][j]);
				break;
			}
		}
		puts("");
	}
}

void printScreen() {
	gotoxy(0, 0);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15*16);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
			printf("%d ", _map[i][j]);
		puts("");
	}
	printf("cur_X: %d, cur_Y: %d\n", cur_X, cur_Y);
	printf("sFlag: %d, curCar: %d\n\n", selectFlag, cur_Car);

	colorScreen();
}

void stageSetting() {
	cars[0].setInfo(2, 0);
	cars[0].setPosition(2, 3);
	cars[1].setPosition(1, 1); 
	cars[1].setInfo(2, 0);
	cars[2].setPosition(1, 2);
	cars[2].setInfo(3, 1);
	cars[3].setPosition(1, 5);
	cars[3].setInfo(2, 1);
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

VOID MouseEventProc(MOUSE_EVENT_RECORD mer)
{
#ifndef MOUSE_HWHEELED
#define MOUSE_HWHEELED 0x0008
#endif
	printf("Mouse event: ");
	int i = 0, key = 0;
	switch (mer.dwEventFlags)
	{
	case 0:

		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			printf("left button press \n");
			//이떄 sFlag on
			
			for (i = 0; i < sizeof(cars) / sizeof(Car); i++) {
				if (cars[i].isSelect(mer.dwMousePosition.X/2, mer.dwMousePosition.Y-11) == 1) {
					selectFlag = 1;
					break;
				}
			}
			printf(" i : %d", i);
		}
		else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
		{
			printf("right button press \n");
		}
		else
		{
			printf("button press\n");
			//이땐 sFlag off
			selectFlag = 0;
		}
		break;
	case DOUBLE_CLICK:
		printf("double click\n");
		break;
	case MOUSE_HWHEELED:
		printf("horizontal mouse wheel\n");
		break;
	case MOUSE_MOVED:
		printf("mouse moved, x:%d, y:%d / prevX : %d, prevY : %d", 
			mer.dwMousePosition.X, mer.dwMousePosition.Y, prev.X, prev.Y);
		if (mer.dwMousePosition.X - prev.X == 2) key = left;
		else if (mer.dwMousePosition.X - prev.X == -2)key = right;
	
		if (mer.dwMousePosition.Y - prev.Y == 1) key = down;
		else if (mer.dwMousePosition.Y - prev.Y == -1) key = up;
			
		// sFlag에 따라 구분
		if (selectFlag == 1 && i !=8) {
			cars[i].moveCar(key, &selectFlag);
		}

		prev.X = mer.dwMousePosition.X;
		prev.Y = mer.dwMousePosition.Y;
		break;
	case MOUSE_WHEELED:
		printf("vertical mouse wheel\n");
		break;
	default:
		printf("unknown\n");
		break;
	}
}

int main() {
	introMenu();
	stageSetting();
	while (1) {
		HANDLE _hStdin = GetStdHandle(STD_INPUT_HANDLE);
		DWORD _fdwSaveOldMode, _cNumRead;
		GetConsoleMode(_hStdin, &_fdwSaveOldMode);
		DWORD _fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
		SetConsoleMode(_hStdin, _fdwMode);
		INPUT_RECORD _irInBuf[128];

		ReadConsoleInput(
			_hStdin,      // input buffer handle 
			_irInBuf,     // buffer to read into 
			128,         // size of read buffer 
			&_cNumRead);
		for (DWORD i = 0; i < _cNumRead; i++)
		{
			switch (_irInBuf[i].EventType)
			{
			case MOUSE_EVENT: // mouse input 
				MouseEventProc(_irInBuf[i].Event.MouseEvent);
				break;
			default:
				break;
			}
			puts("");
		}


		// keyboard
		/*
		if (_kbhit() != 0) {
			int key = _getch();
			if (key == 224) key =  _getch();
			if (selectFlag == 0 ) {
				selectFlag=moveCur(key, &cur_Car);
			}
			else if (selectFlag == 1) {
				cars[cur_Car].moveCar(key, &selectFlag);
			}
		}
		*/
		printScreen();
		if (_map[3][7] != 0) {
			printf("GAME OVER");
			break;
		}
	}
}