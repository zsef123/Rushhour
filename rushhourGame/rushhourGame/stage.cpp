#include "stage.h"

int Stage::_map[8][8];

void Stage::setCar() {
	// temp stage 1 
	_car[0] = new hCar(2, 3, 2);
	_car[1] = new hCar(1, 1, 2);
	_car[2] = new hCar(5, 5, 2);
	_car[3] = new hCar(3, 6, 3);
	_car[4] = new vCar(1, 2, 3);
	_car[5] = new vCar(1, 5, 2);
	_car[6] = new vCar(4, 2, 3);
	_car[7] = new vCar(6, 1, 2);

	Stage::drawCar(1);
}
int (*Stage::getMap())[8] {
	return _map;
}
Car** Stage::getCar() {
	return _car;
}
//왜 const Car하면 안될까
void Stage::drawCar( const int status) {
	for (int i = 0; i < sizeof(_car) / sizeof(Car*); i++) {
		_car[i]->draw(1);
	}
}