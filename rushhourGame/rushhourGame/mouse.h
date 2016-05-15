#pragma once
#include <windows.h>

class inputMouse {
public:
	inputMouse() {
		_hStdin = GetStdHandle(STD_INPUT_HANDLE);
		GetConsoleMode(_hStdin, &_fdwSaveOldMode);
		_fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
		SetConsoleMode(_hStdin, _fdwMode);
	}

	int read() {
		ReadConsoleInput(_hStdin, _irInBuf, 128, &_cNumRead);
		for (int i = 0; i < _cNumRead; i++)
		{
			switch (_irInBuf[i].EventType)
			{
			case KEY_EVENT: // keyboard input 
				break;

			case MOUSE_EVENT: // mouse input 
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
};

VOID MouseEventProc(MOUSE_EVENT_RECORD mer)
{
#ifndef MOUSE_HWHEELED
#define MOUSE_HWHEELED 0x0008
#endif
	printf("Mouse event: ");

	switch (mer.dwEventFlags)
	{
	case 0:

		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			printf("left button press \n");
			//이떄 sFlag on
		}
		else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
		{
			printf("right button press \n");
		}
		else
		{
			printf("button press\n");
			//이땐 sFlag off
		}
		break;
	case DOUBLE_CLICK:
		printf("double click\n");
		break;
	case MOUSE_HWHEELED:
		printf("horizontal mouse wheel\n");
		break;
	case MOUSE_MOVED:
		printf("mouse moved, x:%d, y:%d", mer.dwMousePosition.X, mer.dwMousePosition.Y);
		// sFlag에 따라 구분
		break;
	case MOUSE_WHEELED:
		printf("vertical mouse wheel\n");
		break;
	default:
		printf("unknown\n");
		break;
	}
}