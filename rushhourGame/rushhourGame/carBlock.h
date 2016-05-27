#pragma once

// Car 배열을 만들게 될까
// vCar hCar를 만든후에 Car에서 통합하고 
// virtual keyword로 죄다 조진다음
// Car 배열에서 전부 같이 불러오는게 가능해진다
// Car cars[2]= { vCarSome, hCarSome } 
// for (0 .. 2 ) { car[i].moveCar(key) }라는 식으로 
enum keys {up=72, down=80, left=75, right=77, choice='z'};
class Car {
public:
	Car() {}
	Car(int size, int vertical) { _carSize = size; _vStatus = vertical; }

	void setPosition(const int x,const  int y);
	void getPosition(int *x, int *y);
	void setInfo(const int size,const int vS);
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
