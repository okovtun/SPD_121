#include<iostream>
using namespace std;

class Vehicle	//Транспортное средство
{
	unsigned int speed;
public:
	virtual void move() = 0;//Чисто виртуальный метод, он делает класс абстрактным.
};

class GroundVehicle :public Vehicle //Наземное транортное средство
{

};

class Car :public GroundVehicle
{
public:
	void move()
	{
		cout << "Машина едит на 4х колесах" << endl;
	}
};
class Bike :public GroundVehicle
{
public:
	void move()
	{
		cout << "Мотоцик едит на 2х колесах" << endl;
	}
};

class AirVehicle :public Vehicle
{
	double height;
};
class Plain :public AirVehicle
{
public:
	void move()
	{
		cout << "Самолет летит с большой скоростью, но для его всзлета и посадки нужна взлетная полоса" << endl;;
	}
};
class Helicopter :public AirVehicle
{
public:
	void move()
	{
		cout << "Вертолет взлетает с места, но перемещается на невысокой скорости" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	//Vehicle vehicle;	//Невозможно создать экземпляр абстрактного класса
	//GroundVehicle car;
	
	Car bmw;
	bmw.move();

	Bike HarleyDevidson;
	HarleyDevidson.move();

	Plain boeing;
	boeing.move();

	Helicopter apache;
	apache.move();
}

//virtual type name() = 0;
//virtual type name()const = 0;