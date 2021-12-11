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
		x = x;
	}
	void set_y(double y)
	{
		y = y;
	}
}A,B,C;

//#define STRUCT_POINT

void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	//type name;
	int a;	//ќбъ€вл€ем переменную 'a' типа 'int'
	Point A;//ќбъ€вл€ем переменную 'A' типа 'Point'
			//—оздаем объект (экземпл€р) структуры 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << tab << A.y << endl;

	Point* pA = &A;	//—оздаем указатель на объект нашей структуры
	cout << pA->x << tab << pA->y << endl;
#endif // STRUCT_POINT

	Point A;
	cout << A.get_x() << tab << A.get_y() << endl;
}

/*
.  - ќператор пр€мого доступа (Point operator)
-> - ќператор косвенного доступа (Arrow operator)
*/
/*
1. »нкапсул€ци€ (Encapsulation);
ћодификаторы доступа:
private:	доступны только внутри класса.
public:		
protected:
get/set-методы

get (вз€ть, получить)	 - открывают доступ к переменным членам на чтение,
						   т.е., поззвол€ют получить значение той или иной 
						   переменной-члена.
set (задать, установить) - открывают доступ в переменным членам на запись,
						   т.е., позвол€ют задать значение той или иной 
						   переменной-члена.



2. Ќаследование (Inheritance);
3. ѕолиморфизм  (Polymorphism);
*/