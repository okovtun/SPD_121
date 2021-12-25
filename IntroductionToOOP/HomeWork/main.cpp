#include <iostream>
#include <Windows.h>
#include <cmath>

class Fraction
{
	int A;
	int a;
	unsigned int b;

public:

	int get_A()const
	{
		return A;
	}
	int get_a()const
	{
		return a;
	}
	unsigned int get_b()const
	{
		return b;
	}
	void set_A(int a)
	{
		this->A = A;
	}
	void set_a(int a)
	{
		this->a = a;
	}
	void set_b(unsigned int b)
	{
		this->b = b;
		b > 0;
	}
	Fraction()
	{
		a = b = 0;
		//std::cout << "DefaultConstructor:\t" << this << std::endl;
	}
	Fraction(int a, unsigned int b)
	{
		this->a = a;
		this->b = b;
		//std::cout << "Constructor\t" << this << std::endl;
	}
	Fraction(int A, int a, unsigned int b)
	{
		this->A = A;
		this->a = a;
		this->b = b;
		//std::cout << "Constructor_1\t" << this << std::endl;
	}
	Fraction(const Fraction& other)
	{
		this->a = other.a;
		this->b = other.b;
		//std::cout << "Copyconstructor: " << this << std::endl;
	}
	~Fraction()
	{
		//std::cout << "Destructor\t" << this << std::endl;
	}

	void print()const
	{
		std::cout << a << "/" << b << std::endl;
	}
	void print_1()const
	{
		std::cout << A << "(" << a << "/" << b << ")" << std::endl;
	}

	Fraction& reduce()
	{
		int a_gcf = (this->a); unsigned int b_gcf = this->b;
		while (a_gcf != 0 && b_gcf != 0)
		{
			if (abs(a_gcf) > b_gcf) { a_gcf = abs(a_gcf) % b_gcf; }
			else { b_gcf = b_gcf % abs(a_gcf); }
		}
		int gcf = a_gcf + b_gcf;
		if (this->a < 0) { this->a = -(abs(this->a) / gcf); }
		else { this->a = this->a / gcf; }
		this->b = this->b / gcf;
		return  *this;
	}
	Fraction& to_proper()
	{
		this->A = (int)this->a / this->b;
		this->a = this->a - this->A * this->b;
		return *this;
	}
	Fraction& to_improper()
	{
		this->a = this->A * this->b + this->a;
		return *this;
	}
	bool operator>(const Fraction& other)
	{
		int comp_1 = this->a * other.b;
		int comp_2 = this->b * other.a;
		if (comp_1 > comp_2) { return  true; }
		else return false;
	}
	bool operator<(const Fraction& other)
	{
		int comp_1 = this->a * other.b;
		int comp_2 = this->b * other.a;
		if (comp_1 < comp_2) { return true; }
		else return false;
	}
	bool operator<=(const Fraction& other)
	{
		int comp_1 = this->a * other.b;
		int comp_2 = this->b * other.a;
		if (comp_1 <= comp_2) { return true; }
		else return false;
	}
	bool operator>=(const Fraction& other)
	{
		int comp_1 = this->a * other.b;
		int comp_2 = this->b * other.a;
		if (comp_1 >= comp_2) { return true; }
		else return false;
	}
	bool operator==(const Fraction& other)
	{
		int comp_1 = this->a * other.b;
		int comp_2 = this->b * other.a;
		if (comp_1 == comp_2) { return true; }
		else return false;
	}
	bool operator!=(const Fraction& other)
	{
		int comp_1 = this->a * other.b;
		int comp_2 = this->b * other.a;
		if (comp_1 != comp_2) { return true; }
		else return false;
	}

	Fraction& operator+=(const Fraction& other)
	{
		if (this->b == other.b)
		{
			this->a = this->a + other.a;
			this->b;
		}
		else
		{
			this->a = this->a*other.b + other.a*this->b;
			this->b = other.b*this->b;
		}
		return *this;
	}
	Fraction& operator-=(const Fraction& other)
	{
		if (this->b == other.b)
		{
			this->a = this->a - other.a;
			this->b;
		}
		else
		{
			this->a = this->a * other.b - other.a * this->b;
			this->b = other.b * this->b;
		}
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		this->a = this->a*other.a;
		this->b = this->b*other.b;
		return *this;
	}
	Fraction& operator/=(const Fraction& other)
	{
		this->a *= other.b;
		this->b *= other.a;
		return *this;
	}
}C, B, E, G;
bool Operator_great(const Fraction& left, const Fraction& rigth)
{
	if (left.get_b() == rigth.get_b())
	{
		if (left.get_a() > rigth.get_b()) { return true; }
		else { return false; }
	}
	if (left.get_b() != rigth.get_b())
	{
		if (left.get_a() * rigth.get_b() > rigth.get_a() * left.get_b()) { return true; }
		else { return false; }
	}
}
Fraction operator+(const Fraction& left, const Fraction& rigth)
{
	Fraction result;
	if (left.get_b() == rigth.get_b())
	{
		result.set_a(left.get_a() + rigth.get_a());
		result.set_b(left.get_b());
	}
	else
	{
		result.set_a(left.get_a() * rigth.get_b() + rigth.get_a() * left.get_b());
		result.set_b(left.get_b() * rigth.get_b());
	}

	return result;
}
Fraction operator-(const Fraction& left, const Fraction& rigth)
{
	Fraction result;
	if (left.get_b() == rigth.get_b())
	{
		result.set_a(left.get_a() - rigth.get_a());
		result.set_b(left.get_b());
	}
	else
	{
		result.set_a(left.get_a()*rigth.get_b() - rigth.get_a()*left.get_b());
		result.set_b(left.get_b() * rigth.get_b());
	}
	return result;
}
Fraction operator*(const Fraction& left, const Fraction& rigth)
{
	Fraction result;
	result.set_a(left.get_a() * rigth.get_a());
	result.set_b(left.get_b() * rigth.get_b());
	return result;
}
Fraction operator/(const Fraction& left, const Fraction& rigth)
{
	Fraction result;
	result.set_a(left.get_a() * rigth.get_b());
	result.set_b(left.get_b() * rigth.get_a());
	return result;
}

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	SetConsoleDisplayMode(hConsole, CONSOLE_FULLSCREEN_MODE, &coord);
	bool result_1;
	Fraction D(9, 12); std::cout << "D = "; D.print();
	C = B = E = G = Fraction(3, 8); std::cout << "C = B = E = G = "; C.print();
	Fraction A;
	std::cout << "=============================" << std::endl;
	A = C + D;
	std::cout << "C + D = "; A.print(); A.reduce(); A.print();
	std::cout << "=============================" << std::endl;
	A = C - D;
	std::cout << "C - D = "; A.print(); A.reduce(); A.print();
	std::cout << "=============================" << std::endl;
	A = C * D;
	std::cout << "C * D = "; A.print(); A.reduce(); A.print();
	std::cout << "=============================" << std::endl;
	A = C / D;
	std::cout << "C / D = "; A.print(); A.reduce(); A.print();
	std::cout << "=============================" << std::endl;
	A = (C += D);
	std::cout << "C += D = "; A.print(); A.reduce(); A.print();
	std::cout << "=============================" << std::endl;
	A = (B -= D);
	std::cout << "B -= D = "; A.print(); A.reduce(); A.print();
	std::cout << "=============================" << std::endl;
	A = (E *= D);
	std::cout << "E *= D = "; A.print(); A.reduce(); A.print();
	std::cout << "=============================" << std::endl;
	A = (G /= D);
	std::cout << "G /= D = "; A.print(); A.reduce(); A.print();
	std::cout << "=============================" << std::endl;


	std::cout << "=======================================" << std::endl;

	Fraction K(4, 3, 5);
	Fraction L(23, 5);
	std::cout << "L = "; L.print(); L.to_proper(); std::cout << "L.to_proper = ";  L.print_1();
	std::cout << "=======================================" << std::endl;
	std::cout << "K = "; K.print_1(); std::cout << "K.to_improper = ";  K.to_improper(); K.print();


	std::cout << (Fraction(1, 2) == Fraction(5, 11)) << std::endl;

	return 0;
}