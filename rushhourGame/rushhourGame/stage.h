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

	// 여기서 car를 만든후 map에 집어 넣는다. 
	//그후 map은 public으로 돌려서 ctrl에서 호출


	int (*getMap())[8];

	void setCar();
	Car** getCar();
	void drawCar(const int status);
private:
	Car *_car[8];
};