#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<iostream>
#include<math.h>
#include<Windows.h>
using namespace std;

namespace Geometry
{
	//enum (enumeration - перечисление) - это набор именованных констант типа int.
	enum Color
	{
		red = 0x000000FF,
		green = 0x0000FF00,
		blue = 0x00FF0000,
		yellow = 0x0000FFFF,

		console_red = 0xCC,
		console_green = 0xAA,
		console_blue = 0x99,
		console_yellow = 0xEE,
		console_default = 0x07
	};

	class Shape
	{
	protected:
		Color color;
		unsigned int start_x;
		unsigned int start_y;
		unsigned int line_width;
	public:
		Color get_color()const
		{
			return color;
		}
		unsigned int get_start_x()const
		{
			return start_x;
		}
		unsigned int get_start_y()const
		{
			return start_y;
		}
		unsigned int get_line_width()const
		{
			return line_width;
		}
		void set_start_x(unsigned int start_x)
		{
			if (start_x > 800)start_x = 800;
			this->start_x = start_x;
		}
		void set_start_y(unsigned int start_y)
		{
			if (start_y > 800)start_y = 800;
			this->start_y = start_y;
		}
		void set_line_width(unsigned int line_width)
		{
			if (line_width > 50)line_width = 50;
			this->line_width = line_width;
		}

		Shape(unsigned int start_x, unsigned int start_y, unsigned int line_width, Color color) :color(color)
		{
			set_start_x(start_x);
			set_start_y(start_y);
			set_line_width(line_width);
		}
		virtual ~Shape() {}

		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;

		void info()const
		{
			cout << "Площадь фигуры: " << get_area() << endl;
			cout << "Периметр фигуры:" << get_perimeter() << endl;
			draw();
		}
	};

	class Square :public Shape
	{
		double side;
	public:
		double get_side()const
		{
			return side;
		}
		void set_side(double side)
		{
			if (side <= 0)side = 10;
			this->side = side;
		}
		Square(double side, unsigned int start_x, unsigned int start_y, unsigned int line_width, Color color) :
			Shape(start_x, start_y, line_width, color)
		{
			set_side(side);
		}
		~Square() {}

		double get_area()const
		{
			return side * side;
		}
		double get_perimeter()const
		{
			return side * 4;
		}
		void draw()const
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, get_color());
			for (int i = 0; i < side; i++)
			{
				cout << "\t";
				for (int i = 0; i < side; i++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::console_default);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина стороны: " << side << endl;
			Shape::info();
		}
	};

	class Rectangle :public Shape
	{
		double width;
		double length;
	public:
		double get_width()const
		{
			return width;
		}
		double get_length()const
		{
			return length;
		}
		void set_width(double width)
		{
			if (width <= 0)width = 20;
			this->width = width;
		}
		void set_length(double length)
		{
			if (length <= 0)length = 10;
			this->length = length;
		}
		Rectangle(double width, double length, unsigned int start_x, unsigned int start_y, unsigned int line_width, Color color) :
			Shape(start_x, start_y, line_width, color)
		{
			set_width(width);
			set_length(length);
		}
		~Rectangle() {}

		double get_area()const
		{
			return width * length;
		}
		double get_perimeter()const
		{
			return (width + length) * 2;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			//HWND hwnd = GetDesktopWindow();
			//HWND hwnd = FindWindow(NULL, L"Calculator");
			//HWND hwnd = FindWindow(NULL, L"Inheritance - Microsoft Visual Studio");
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			::Rectangle(hdc, start_x, start_y, start_x + width, start_y + length);

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Ширина прямоугольника: " << width << endl;
			cout << "Длина прямоугольника: " << length << endl;
			Shape::info();
		}
	};
	class Circle :public Shape
	{
		double radius;
	public:
		double get_radius()const
		{
			return radius;
		}
		double get_diameter()const
		{
			return radius * 2;
		}
		void set_radius(double radius)
		{
			if (radius <= 0 || radius >= 500)radius = 500;
			this->radius = radius;
		}
		Circle(double radius, unsigned int start_x, unsigned int start_y, unsigned int line_width, Color color) :Shape(start_x, start_y, line_width, color)
		{
			set_radius(radius);
		}
		~Circle() {}

		double get_area()const
		{
			return M_PI * pow(radius, 2);
		}
		double get_perimeter()const
		{
			return 2 * M_PI*radius;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			Ellipse(hdc, start_x, start_y, start_x + get_diameter(), start_y + get_diameter());

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Радиус круга: " << get_radius() << endl;
			cout << "Диаметр круга: " << get_diameter() << endl;
			Shape::info();
		}
	};
	class Triangle :public Shape
	{
	public:
		Triangle(unsigned int start_x, unsigned int start_y, unsigned int line_width, Color color)
			:Shape(start_x, start_y, line_width, color) {}
		~Triangle() {}

		virtual double get_height()const = 0;
	};
	class EquilateralTriangle :public Triangle
	{
		double side;
	public:
		EquilateralTriangle(double side, unsigned int start_x, unsigned int start_y, unsigned int line_width, Color color)
			:Triangle(start_x, start_y, line_width, color)
		{
			set_side(side);
		}
		~EquilateralTriangle() {}
		void set_side(double side)
		{
			if (side < 20)side = 20;
			if (side > 500)side = 500;
			this->side = side;
		}
		double get_side()const
		{
			return side;
		}
		double get_height()const
		{
			//return sqrt(pow(side, 2) - pow(side / 2, 2));
			return side * cos(30 * M_PI / 180);
		}
		double get_area()const
		{
			return get_height()*side / 4;
		}
		double get_perimeter()const
		{
			return side * 3;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			POINT points[] =
			{
				{start_x, start_y + side},
				{start_x + side, start_y + side},
				{start_x + side / 2, start_y + side - get_height()}
			};
			Polygon(hdc, points, sizeof(points) / sizeof(POINT));

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина стороны: " << get_side() << endl;
			cout << "Высота: " << get_height() << endl;
			Shape::info();
		}
	};
	class IsoscalesTriangle :public Triangle
	{
		double base;
		double base_angle;
	public:
		IsoscalesTriangle
		(
			double base, double base_angle,
			unsigned int start_x, unsigned int start_y, unsigned int line_width, Color color
		) :Triangle(start_x, start_y, line_width, color)
		{
			set_base(base);
			set_angle(base_angle);
		}
		void set_base(double base)
		{
			//if (base < 20)base = 20;
			//if (base > 200)base = 200;
			this->base = base;
		}
		void set_angle(double angle)
		{
			//if (angle < 10)angle = 10;
			//if (angle > 89)angle = 89;
			this->base_angle = angle;
		}
		double get_base()const
		{
			return base;
		}
		double get_base_angle()const
		{
			return base_angle;
		}
		double get_side()const
		{
			return get_height()/sin(base_angle* M_PI / 180);
		}
		double get_height()const
		{
			return base / 2 * tan(base_angle*M_PI / 180);
		}
		double get_area()const
		{
			return base / 2 * get_height();
		}
		double get_perimeter()const
		{
			return get_side() * 2 + base;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			POINT points[] =
			{
				{start_x, start_y + get_side()},
				{start_x + base, start_y + get_side()},
				{start_x + base / 2, start_y + get_side() - get_height()},
			};
			
			Polygon(hdc, points, sizeof(points) / sizeof(POINT));

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Основание треугольника: " << get_base() << endl;
			cout << "Сторона треугольника:   " << get_side() << endl;
			cout << "Угол между основанием и стороной: " << get_base_angle() << endl;
			cout << "Высота треугольника:   " << get_height() << endl;
			Shape::info();
		}
	};
}
void main()
{
	setlocale(LC_ALL, "");
	//Shape shape(Color::console_blue);

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD console_rect{ 120,32 };
	SetConsoleDisplayMode(hConsole, CONSOLE_FULLSCREEN_MODE, &console_rect);

	Geometry::Square square(5, 100, 100, 5, Geometry::Color::console_red);
	square.info();

	Geometry::Rectangle rect(150, 80, 500, 100, 5, Geometry::Color::blue);
	rect.info();

	Geometry::Circle circle(150, 500, 250, 5, Geometry::Color::yellow);
	circle.info();

	Geometry::EquilateralTriangle eqt(380, 900, 220, 15, Geometry::Color::green);
	eqt.info();

	Geometry::IsoscalesTriangle isct(180, 91, 100, 100, 1, Geometry::Color::green);
	isct.info();
}