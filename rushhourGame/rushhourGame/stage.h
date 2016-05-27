#pragma once
#include "carBlock.h"

extern int _map[8][8];
class Stage {
public:

	Stage(Car *car) {
		car = _car;
		for (int i = 0; i < 8; i++) {
			_map[0][i] = 9;
			_map[7][i] = 9;
			_map[i][0] = 9;
			_map[i][7] = 9;
		}
		_map[3][7] = 0;
	}
	// 여기서 car를 만든후 map에 집어 넣는다. 
	//그후 map은 public으로 돌려서 ctrl에서 호출
	void setCar(Car *car);
	Car* getCar() { return _car; }
	void drawCar(Car car,const int status);
private:
	Car *_car;
};