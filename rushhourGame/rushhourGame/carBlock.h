#pragma once

// Car �迭�� ����� �ɱ�
// vCar hCar�� �����Ŀ� Car���� �����ϰ� 
// virtual keyword�� �˴� ��������
// Car �迭���� ���� ���� �ҷ����°� ����������
// Car cars[2]= { vCarSome, hCarSome } 
// for (0 .. 2 ) { car[i].moveCar(key) }��� ������ 
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
