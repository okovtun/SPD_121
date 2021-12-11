#include<iostream>
using namespace std;

#define tab "\t"

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
		//this - это указатель на объект, для которого вызывается метод
		//Изнутри метода невозможно узнать имя объекта, для которого он вызывается
		//НО всегда можно узнать адрес этого объекта.
	}
	void set_y(double y)
	{
		this->y = y;
	}
}A,B,C;

//#define STRUCT_POINT

void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	//type name;
	int a;	//Объявляем переменную 'a' типа 'int'
	Point A;//Объявляем переменную 'A' типа 'Point'
			//Создаем объект (экземпляр) структуры 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << tab << A.y << endl;

	Point* pA = &A;	//Создаем указатель на объект нашей структуры
	cout << pA->x << tab << pA->y << endl;
#endif // STRUCT_POINT

	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << tab << A.get_y() << endl;
}

/*
.  - Оператор прямого доступа (Point operator)
-> - Оператор косвенного доступа (Arrow operator)
*/
/*
1. Инкапсуляция (Encapsulation);
Модификаторы доступа:
private:	доступны только внутри класса.
public:		
protected:
get/set-методы

get (взять, получить)	 - открывают доступ к переменным членам на чтение,
						   т.е., поззволяют получить значение той или иной 
						   переменной-члена.
set (задать, установить) - открывают доступ в переменным членам на запись,
						   т.е., позволяют задать значение той или иной 
						   переменной-члена.



2. Наследование (Inheritance);
3. Полиморфизм  (Polymorphism);
*/