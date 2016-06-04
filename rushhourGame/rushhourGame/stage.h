#pragma once
#include "carBlock.h"

class Stage {
public:
	static int _map[8][8];
	Stage() {
		for (int i = 0; i < 8; i++) {
			_map[0][i] = 9;
			_map[7][i] = 9;
			_map[i][0] = 9;
			_map[i][7] = 9;
		}
		_map[3][7] = 0;
	}
	~Stage() {
		for (int i = 0; i < sizeof(_car) / sizeof(Car*); i++) {
			delete _car[i];
		}
	}

	// ���⼭ car�� ������ map�� ���� �ִ´�. 
	//���� map�� public���� ������ ctrl���� ȣ��


	int (*getMap())[8];

	void setCar();
	Car** getCar();
	void drawCar(const int status);
private:
	Car *_car[8];
};