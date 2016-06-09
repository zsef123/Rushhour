#include "carBlock.h"
#include "stage.h"
void Car::setPosition(const int x, const  int y, const int size) { _x = x; _y = y; _carSize = size; }
void Car::getPosition(int *x, int *y, int *size) { *x = _x; *y = _y; *size = _carSize; }

void vCar::draw(const int status) {
	// 잘못된부분 erase 하는지 주의해야한다
	// draw는 Car 가 아닌 map Class에서 지정해야할듯
	for (int i = 0; i < _carSize; i++) {
		Stage::_map[_y + i][_x] += _carSize*status;
	}
	
}
void hCar::draw(const int status) {
	// 잘못된부분 erase 하는지 주의해야한다
	// draw는 Car 가 아닌 map Class에서 지정해야할듯
	for (int i = 0; i < _carSize; i++) {
		Stage::_map[_y][_x + i] += _carSize*status;
	}
	
}

int vCar::collision(const int nextStatus) {
	if (nextStatus == up) {
		if (Stage::_map[_y - 1][_x] != 0)
			return 1;
	}
	else if (nextStatus == down) {
		if (Stage::_map[_y + _carSize][_x] != 0)
			return 1;
	}
	return 0;
}
int hCar::collision(const int nextStatus) {
	if (nextStatus == left) {
		if (Stage::_map[_y][_x - 1] != 0)
			return 1;
	}
	else if (nextStatus == right) {
		if (Stage::_map[_y][_x + _carSize] != 0)
			return 1;
	}
	return 0;
}

int vCar::moveCar(const int key, int *sFlag) {
	if (collision(key) == 1) return 0;
	if (key == choice) {
		*sFlag = 0;
		return 0;
	}
	// 문제 있다 collison이랑 switch가 겹친다

	draw(-1);
	switch (key)
	{
	case up://up
		_y--;
		break;
	case down://down
		_y++;
	default:
		break;
	};
	draw(1);
	return 1;
}
int hCar::moveCar(const int key, int *sFlag) {
	if (collision(key) == 1) return 0;
	if (key == choice) {
		*sFlag = 0;
		return 0;
	}
	// 문제 있다 collison이랑 switch가 겹친다

	draw(-1);
	switch (key)
	{
	case left://left
		_x--;
		break;
	case right://right
		_x++;
	default:
		break;
	};
	
	draw(1);
	return 1;
}

int vCar::isSelect(const int x, const int y) {
	if ( x == _x) {
		if (y >= _y && y < _y + _carSize)
			return 1;
	}
	return 0;
}
int hCar::isSelect(const int x, const int y) {
	if ( y == _y) {
		if (x >= _x && x < _x + _carSize)
			return 1;

	}
	return 0;
}


