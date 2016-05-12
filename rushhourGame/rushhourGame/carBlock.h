#pragma once

// Car 배열을 만들게 될까
enum keys {up=72, down=80, left=75, right=77, choice='z'};
class Car {
public:
	Car() {}
	Car(int size, int vertical) { _carSize = size; _vStatus = vertical; }

	void setPosition(int x, int y);
	void getPosition(int *x, int *y);
	void setInfo(int size, int vS);
	void getInfo(int *size, int *vS);

	void draw(int status);
	int collision(int nextStatus);
	int moveCar(int key, int *sFlag);
	int isSelect(int x, int y);
private:
	int _x, _y;
	int _carSize;
	int _vStatus;
};
