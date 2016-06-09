#pragma once
#include <windows.h>
#include "stage.h"
#include "Wave.h"
class inputMouse {
public:
	inputMouse(Car** a ) {
		_hStdin = GetStdHandle(STD_INPUT_HANDLE);
		GetConsoleMode(_hStdin, &_fdwSaveOldMode);
		_fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
		_fdwMode &= ~ENABLE_QUICK_EDIT_MODE;
		SetConsoleMode(_hStdin, _fdwMode | ENABLE_EXTENDED_FLAGS);
		cars = a;

		effect.setFile("alert.wav");
	}
	void setCar(Car** a) {
		cars = a;
	}
	int read() {
		int chk=0;
		ReadConsoleInput(_hStdin, _irInBuf, 128, &_cNumRead);
		for (int i = 0; i < (int)_cNumRead; i++)
		{
			switch (_irInBuf[i].EventType)
			{
			case KEY_EVENT: // keyboard input 
				break;

			case MOUSE_EVENT: // mouse input 
				MouseEventProc(_irInBuf[i].Event.MouseEvent,&chk);
				// moved event process while button presse
				break;

			case WINDOW_BUFFER_SIZE_EVENT: // scrn buf. resizing 
				break;

			case FOCUS_EVENT:  // disregard focus events 

			case MENU_EVENT:   // disregard menu events 
				break;

			default:
				break;
			}
		}
		return chk;
	}
private:

	HANDLE _hStdin;
	DWORD _cNumRead, _fdwMode, _i, _fdwSaveOldMode;
	INPUT_RECORD _irInBuf[128];

	int selectFlag, cur_Car;
	Car** cars;
	COORD prev;

	Wave effect;
	VOID MouseEventProc(MOUSE_EVENT_RECORD mer, int *chk)
	{
#ifndef MOUSE_HWHEELED
#define MOUSE_HWHEELED 0x0008
#endif
		int key = 0;
		switch (mer.dwEventFlags)
		{
		case 0:
			effect.play(1);
			if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				for (cur_Car = 0; cur_Car < 8; cur_Car++) {
					if (cars[cur_Car]->isSelect(mer.dwMousePosition.X / 2, mer.dwMousePosition.Y - 1) == 1) {
						selectFlag = 1;
						break;
					}
				}
			}
			else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
			{
				printf("right button press \n");
			}
			else
			{
				selectFlag = 0;
			}
			break;
		case DOUBLE_CLICK:
			break;
		case MOUSE_HWHEELED:
			break;
		case MOUSE_MOVED:
			/*
			printf("mouse moved, x:%d, y:%d / prevX : %d, prevY : %d\n",
				mer.dwMousePosition.X, mer.dwMousePosition.Y, prev.X, prev.Y);*/
			if (mer.dwMousePosition.X - prev.X == 1) key = right;
			else if (mer.dwMousePosition.X - prev.X == -1)key = left;

			if (mer.dwMousePosition.Y - prev.Y == 1) key = down;
			else if (mer.dwMousePosition.Y - prev.Y == -1) key = up;
			printf("sFlag: %d, cur: %d", selectFlag, cur_Car);
			// sFlag에 따라 구분
			if (selectFlag == 1 && cur_Car < 8) {
				cars[cur_Car]->moveCar(key, &selectFlag);
			}

			prev.X = mer.dwMousePosition.X;
			prev.Y = mer.dwMousePosition.Y;
			*chk = 1;
			break;
		case MOUSE_WHEELED:
			break;
		default:
			break;
		}
	}
};