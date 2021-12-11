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
		this->x = x;//Encapsulation DONE
		//this - это указатель на объект, для которого вызывается метод
		//Изнутри метода невозможно узнать имя объекта, для которого он вызывается
		//НО всегда можно узнать адрес этого объекта.
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//					Constructors:
	/*Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//				Methods:
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

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

	Point A;	//DefaultConstructor
	double x, y;
	//cout << "Введите координаты точки: "; cin >> x >> y;
	//A.set_x(x);
	//A.set_y(y);
	//cout << A.get_x() << tab << A.get_y() << endl;
	A.print();

	Point B(22, 33);
	B.print();

	Point C = 5;	//Single-argument constructor
	C.print();

	Point D(0, 123);
	D.print();
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

/*
				SPECIAL MEMBERS
Constructor - это метод, который создает объект. А именно, выделяет память под объект,
			  и инициализирует его переменные члены.
~Destructor	-
operator=
*/