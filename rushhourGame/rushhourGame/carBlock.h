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
	Car(int x, int y, int size) { _x = x; _y = y; _carSize = size; }

	void setPosition(const int x,const  int y, const int size);
	void getPosition(int *x, int *y, int *size);
	
	virtual void draw(const int status) = 0;
	virtual int collision(const int nextStatus) =0 ;
	virtual int moveCar(const int key, int *sFlag) = 0;
	virtual int isSelect(const int x, const int y)=0;
	
protected:
	int _x, _y;
	int _carSize;
};

class vCar : public Car {
public:
	vCar() {}
	vCar(int x, int y, int size) : Car(x, y, size) {}

	virtual void draw(const int status);
	virtual int collision(const int nextStatus);
	virtual int moveCar(const int key, int *sFlag);
	virtual int isSelect(const int x,const int y);
};

class hCar : public Car {
public:
	hCar() {}
	hCar(int x, int y, int size) : Car(x, y, size) {}

	virtual void draw(const int status);
	virtual int collision(const int nextStatus);
	virtual int moveCar(const int key, int *sFlag);
	virtual int isSelect(const int x, const int y);
};
