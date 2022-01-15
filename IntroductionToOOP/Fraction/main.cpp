#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#define DEBUG

class Fraction;	//Просто объявление класса
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);

class Fraction	//Объявление и описание класса
{
	int integer;		//Целая часть
	int numerator;		//Числитель
	int denominator;	//Знаменатель
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator <= 0)denominator = 1;
		this->denominator = denominator;
	}

	//				Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
#ifdef DEBUG
		cout << "DefaultConstruct:\t" << this << endl;
#endif // DEBUG
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
#ifdef DEBUG
		cout << "1ArgConstructor:" << this << endl;
#endif // DEBUG
	}
	Fraction(double decimal)
	{
		//decimal - десятичная дробь
		//1) Сохраняем целую часть дробного числа:
		integer = decimal;	//implicit coversion (неявное преобразование)
		//2) Убираем целую часть из дробного числа:
		decimal -= integer;
		//3) Вытаскиваем максимально возможное количество десятичных разрядов 
		//из дробной части числа, и сохраняем все эти разряды в числитель:
		denominator = 1e+9;	//1*10^9
		numerator = decimal * denominator;
		reduce();
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
#ifdef DEBUG
		cout << "Constructor\t" << this << endl;
#endif // DEBUG
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
#ifdef DEBUG
		cout << "Constructor\t" << this << endl;
#endif // DEBUG
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
#ifdef DEBUG
		cout << "CopyConstructor:" << this << endl;
#endif // DEBUG
	}
	~Fraction()
	{
#ifdef DEBUG
		cout << "Destructor\t" << this << endl;
#endif // DEBUG
	}

	//				Operators:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
#ifdef DEBUG
		cout << "CopyAssignment:\t" << this << endl;
#endif // DEBUG
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this*other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this/other;
	}

	//				Type-cast operators:
	explicit operator int()const
	{
		return integer;
	}
	explicit operator double()const
	{
		return integer + (double)numerator / denominator;
	}

	//				Methods:
	Fraction& reduce()
	{
		int numerator_gcf = (this->numerator); unsigned int denominator_gcf = this->denominator;
		while (numerator_gcf != 0 && denominator_gcf != 0)
		{
			if (abs(numerator_gcf) > denominator_gcf) { numerator_gcf = abs(numerator_gcf) % denominator_gcf; }
			else { denominator_gcf = denominator_gcf % abs(numerator_gcf); }
		}
		int gcf = numerator_gcf + denominator_gcf;
		if (this->numerator < 0) { this->numerator = -(abs(this->numerator) / gcf); }
		else { this->numerator = this->numerator / gcf; }
		this->denominator = this->denominator / gcf;
		return  *this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction inverted()
	{
		to_improper();
		return Fraction(denominator, numerator);
	}

	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
};

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	);*/
	/*result.set_numerator(left.get_numerator()*right.get_numerator());
	result.set_denominator(left.get_denominator()*right.get_denominator());*/
	//result.to_proper();
	//return result;
	return Fraction	//Явно вызываем конструктор, и создаем временный безымянный объект,
	(//этот объект сразу же возвращается на место вызова.
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	).to_proper();
}
Fraction operator/(Fraction left, Fraction right)
{
	return left * right.inverted();
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())cout << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())cout << "(";
		cout << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())cout << ")";
	}
	else if (obj.get_integer() == 0)cout << 0;
	return os;
}

//#define CONSTRUCTORS_CHECK
//#define OPERATORS_CHECK
//#define TYPE_CONVERSIONS_BASICS
//#define CONVERSIONS_FROM_OTHER_TYPES_TO_CLASS
#define CONVERSIONS_FROM_CLASS_TO_OTHER_TYPES

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A;		//Default constructor
	A.print();

	double b = 5;
	Fraction B = 5;	//Single-argument constructor
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = D;
	E.print();
#endif // CONSTRUCTORS_CHECK

#ifdef OPERATORS_CHECK
	Fraction A(2, 3, 4);
	Fraction B(3, 4, 5);
	Fraction C = A * B;
	C.print();
	(A / B).print();
	A *= B;
	//A.print();
	cout << A << endl;
	//cout << 123 << endl;  
#endif // OPERATORS_CHECK

#ifdef TYPE_CONVERSIONS_BASICS
			//Warning: conversion from type to type possible loss of data.
//		l-value = r-value;
	int a = 2;		//No conversion
	double b = 3;	//Conversion from less to more
	int c = b;		//Conversion from more to less without data loss
	int d = 5.2;	//Conversion from more to less with data loss
	char e = 515;	//Conversion from int to char. Truncation (Усечение, урезание)
					//Arithmetical overflow
	cout << (int)e << endl;
#endif // TYPE_CONVERSIONS_BASICS

#ifdef CONVERSIONS_FROM_OTHER_TYPES_TO_CLASS
	//1. Single-argument constructor
	//2. Assignment operator

	//(type)value - C-Like notation
	//type(value) - Functional notation

	double a = 2;	//Conversion from 'int' to 'double'
	5;//Числовая константа типа 'int'
	Fraction A = (Fraction)5;	//Conversion from 'int' to 'Fraction'
	A;//Переменная типа 'Fraction'
	cout << A << endl;

	Fraction B;	//Default constructor
	cout << "\n--------------------------\n";
	B = Fraction(8);
	cout << "\n--------------------------\n";
	cout << B << endl;
#endif // CONVERSIONS_FROM_OTHER_TYPES_TO_CLASS

	/*
	----------------------------------------------------
	operator type()
	{
		
	}
	----------------------------------------------------
	*/

	/*Fraction A(5);
	int a = A;
	cout << a << endl;
	Fraction B(2, 1, 7);
	double b = B;
	cout << b << endl;*/

	//cout << ((double)Fraction(1, 2) == (double)Fraction(5, 10))<< endl;

	Fraction A = 2.75;	//From double to Fraction
						//From other to class (преобразование другого типа в наш тип)
	cout << A << endl;
}

//23 + 54*(88 - 33)^2 - 123 / 2