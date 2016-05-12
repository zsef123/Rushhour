#include "carBlock.h"
#include "stage.h"

void Car::setPosition(int x, int y) { _x = x; _y = y; }
void Car::getPosition(int *x, int *y) { *x = _x; *y = _y; }
void Car::setInfo(int size, int vS) { _carSize = size; _vStatus = vS; }
void Car::getInfo(int *size, int *vS) { *size = _carSize; *vS = _vStatus; }

void Car::draw(const int status) {
	// 잘못된부분 erase 하는지 주의해야한다
	// draw는 Car 가 아닌 map Class에서 지정해야할듯
	if (_vStatus == 0) {
		for (int i = 0; i < _carSize; i++) {
			_map[_y][_x + i] += _carSize*status;
		}
	}
	else {
		for (int i = 0; i < _carSize; i++) {
			_map[_y + i][_x] += _carSize*status;
		}
	}
}
int Car::collision(const int nextStatus) {
	if (_vStatus == 0) {
		if (nextStatus == left) {
			if (_map[_y][_x - 1] != 0)
				return 1;
		}
		else if (nextStatus == right) {
			if (_map[_y][_x + _carSize] != 0)
				return 1;
		}
	}
	else {
		if (nextStatus == up) {
			if (_map[_y - 1][_x] != 0)
				return 1;
		}
		else if (nextStatus == down) {
			if (_map[_y + _carSize][_x] != 0)
				return 1;
		}
	}
	return 0;
}
int Car::moveCar(const int key, int *sFlag) {
	if (collision(key) == 1) return 0;
	if (key == choice) {
		*sFlag = 0;
		return 0;
	}
	// 문제 있다 collison이랑 switch가 겹친다

	draw(-1);
	if (_vStatus == 0) {
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
	}
	else if (_vStatus == 1) {
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
	}
	draw(1);
	return 1;
}
int Car::isSelect(const int x, const int y) {
	if (_vStatus == 0 && y == _y) {
		if (x >= _x && x < _x + _carSize)
			return 1;

	}
	else if (_vStatus != 0 && x == _x) {
		if (y >= _y && y < _y + _carSize)
			return 1;
	}
	return 0;
}