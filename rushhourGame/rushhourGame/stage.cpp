#include "stage.h"

int _map[8][8] = { 0 };
void Stage::setCar(Car *car) { car = _car; }
//�� const Car�ϸ� �ȵɱ�
void Stage::drawCar(Car car, const int status) {
	// Car ���� �����س��ٰ�
	// moveCar���ҽÿ� ������ Car( ���� index ) �� ����� �̹��� ���� ������ ���� setCar���Ѵ�
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