#pragma once
#include <windows.h>
#include "stage.h"
class inputMouse {
public:
	inputMouse(Car* a ) {
		_hStdin = GetStdHandle(STD_INPUT_HANDLE);
		GetConsoleMode(_hStdin, &_fdwSaveOldMode);
		_fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
		_fdwMode &= ~ENABLE_QUICK_EDIT_MODE;
		SetConsoleMode(_hStdin, _fdwMode | ENABLE_EXTENDED_FLAGS);
		cars = a;
	}

	void read() {
		ReadConsoleInput(_hStdin, _irInBuf, 128, &_cNumRead);
		for (int i = 0; i < _cNumRead; i++)
		{
			switch (_irInBuf[i].EventType)
			{
			case KEY_EVENT: // keyboard input 
				break;

			case MOUSE_EVENT: // mouse input 
				MouseEventProc(_irInBuf[i].Event.MouseEvent);
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
	}
private:
	HANDLE _hStdin;
	DWORD _cNumRead, _fdwMode, _i, _fdwSaveOldMode;
	INPUT_RECORD _irInBuf[128];

	int selectFlag, cur_Car;
	Car* cars;
	COORD prev;

	VOID MouseEventProc(MOUSE_EVENT_RECORD mer)
	{
#ifndef MOUSE_HWHEELED
#define MOUSE_HWHEELED 0x0008
#endif
		printf("Mouse event: ");
		int key = 0;
		switch (mer.dwEventFlags)
		{
		case 0:

			if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				printf("left button press \n");
				//이떄 sFlag on

				for (cur_Car = 0; cur_Car < 8; cur_Car++) {
					if (cars[cur_Car].isSelect(mer.dwMousePosition.X / 2, mer.dwMousePosition.Y - 11) == 1) {
						selectFlag = 1;
						break;
					}
				}
				printf(" cur : %d", cur_Car);
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
			printf("mouse moved, x:%d, y:%d / prevX : %d, prevY : %d\n",
				mer.dwMousePosition.X, mer.dwMousePosition.Y, prev.X, prev.Y);
			if (mer.dwMousePosition.X - prev.X == 1) key = right;
			else if (mer.dwMousePosition.X - prev.X == -1)key = left;

			if (mer.dwMousePosition.Y - prev.Y == 1) key = down;
			else if (mer.dwMousePosition.Y - prev.Y == -1) key = up;
			printf("sFlag: %d, cur: %d", selectFlag, cur_Car);
			// sFlag에 따라 구분
			if (selectFlag == 1 && cur_Car < 8) {
				cars[cur_Car].moveCar(key, &selectFlag);
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
};