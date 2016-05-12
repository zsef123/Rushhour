#include "stage.h"

int _map[8][8] = { 0 };
void Stage::setCar(Car *car) { car = _car; }
//왜 const Car하면 안될까
void Stage::drawCar(Car car, const int status) {
	// Car 별로 저장해놨다가
	// moveCar를할시에 기존의 Car( 같은 index ) 를 지우고 이번에 들어온 정보로 새로 setCar를한다
	int x, y;
	int size, vStatus;
	car.getPosition(&x, &y);
	car.getInfo(&size, &vStatus);
	if (vStatus == 0) {
		for (int i = 0; i < size; i++) {
			_map[y][x + i] += size * status;
		}
	}
	else {
		for (int i = 0; i < size; i++) {
			_map[y + i][x] += size * status;
		}
	}

}