#pragma warning(disable:4326)

#include<iostream>
#include<Windows.h>

using namespace std;
using std::cin;
using std::cout;
using std::endl;;

int StringLength(const char* str);

//////////////////////////////////////////////////////////////////////////////////////
////////////////		CLASS DECLARATION (ОБЪЯВЛЕНИЕ КЛАССА)			//////////////
//////////////////////////////////////////////////////////////////////////////////////

class String;
String operator+(const String& left, const String& right);

class String
{
	int size;	//Размер строки
	char* str;	//Указатель на строку в динамической памяти
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();

	//					Constructors:
	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	~String();

	//					Operators:
	String& operator=(const String& other);
	String& operator+=(const String& other);

	const char& operator[](int i)const;
	char& operator[](int i);

	//					Methods:
	void print()const;
};

//////////////////////////////////////////////////////////////////////////////////////
////////////////	CLASS DECLARATION END (КОНЕЦ ОБЪЯВЛЕНИЯ КЛАССА)		//////////////
//////////////////////////////////////////////////////////////////////////////////////

///--------------------------------------------------------------------------------///

//////////////////////////////////////////////////////////////////////////////////////
////////////////		CLASS DEFINITION (ОПРЕДЕЛЕНИЕ КЛАССА)			//////////////
//////////////////////////////////////////////////////////////////////////////////////
int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}

//					Constructors:
String::String(int size) :size(size), str(new char[size] {})
{
	//Благодаря принимаемому параметру size мы можем создавать строки заданного размера
	cout << "DefaultConst:\t" << this << endl;
}
String::String(const char* str) :String(strlen(str) + 1)
{
	for (int i = 0; i < size; i++)this->str[i] = str[i];
	cout << "Constructor:\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	//Глубокое копирование (Deep copy)
	cout << "CopyConstructor:" << this << endl;
}
String::~String()
{
	delete[] this->str;	//Если конструктор выделяет память при помощи оператора new,
	//то деструктор обязательно должен освобождать эту память оператором delete[],
	//в противном случае будет возникать утечка памяти.
	cout << "Destructor:\t" << this << endl;
}

//					Operators:
String& String::operator=(const String& other)
{
	if (this == &other)return *this;

	int a = 2;
	int b = 3;
	a = b;
	delete[] this->str;
	//Глубокое копирование (Deep copy)
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}
String& String::operator+=(const String& other)
{
	return *this = *this + other;
}

const char& String::operator[](int i)const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}

//					Methods:
void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}

String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		//l-value = r-value;
		result[i] = left[i];
	//result.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		result[left.get_size() - 1 + i] = right[i];
	//result.get_str()[left.get_size() - 1 + i] = right.get_str()[i];
	return result;
}

ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

//////////////////////////////////////////////////////////////////////////////////////
////////////////	CLASS DEFINITION END (КОНЕЦ ОПРЕДЕЛЕНИЯ КЛАССА)		//////////////
//////////////////////////////////////////////////////////////////////////////////////

//#define NULL_TERMINATED_LINES
//#define BASE_CHECK
//#define OPERATOR_PLUS_CHECK

void main()
{
	//setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

#ifdef NULL_TERMINATED_LINES
	'\0';//ASCII-символ с кодом 0.	NULL Terminator
//C-strings - NULL Terminated Lines
//char str[] = { 'H', 'e', 'l', 'l', 'o', 0 };
/*char str[] = "Hello";
cout << str << endl;
str[2] = 0;
cout << str << endl;
const char* str1 = "World";
str1[2] = 0;*/

	const int SIZE = 20;
	char str[SIZE] = {};
	cout << "Введите строку: ";
	//SetConsoleCP(1251);
	//cin >> str;
	cin.getline(str, SIZE);
	//SetConsoleCP(866);
	cout << str << endl;
#endif // NULL_TERMINATED_LINES

#ifdef BASE_CHECK
	String str1;
	str1.print();

	//String str2 = 25;	//Преобразование int в String запрещено при помощи explicit
	String str2(25);	//explicit конструктор можно вызвать только так
	str2.print();

	cout << sizeof("Hello") << endl;
	cout << "StringLength:" << StringLength("Hello") << endl;;

	String str3 = "Hello";
	str3.print();

	str3 = str3;

	String str4 = str3;	//CopyConstructor
	str4.print();

	String str5;
	str5 = str4;	//CopyAssignment
	str5.print();
#endif // BASE_CHECK

#ifdef OPERATOR_PLUS_CHECK
	String str1 = "Hello";
	String str2 = "World";
	String str3 = str1 + str2;
	cout << str3 << endl;	//HelloWorld

	str1 += str2;
	cout << str1 << endl;	//HelloWorld  
#endif // OPERATOR_PLUS_CHECK

	String str1;	//Default constructor
	str1.print();

	String str2 = "Hello";	//Signle-argument constructor
	str2.print();

	String str3 = str2;		//CopyConstructor
	str3.print();

	String str4();	//Здесь НЕ вызывается конструктор по умолчанию, поскольку здесь НЕ создается никаких объектов.
	//Объявляем функцию str4(), которая НЕ принимает никаких параметров, и возвращает значение типа String.
	//Если мы хотим явно вызвать конструктор по умолчанию, то это можно сделать так:
	String str5{};	//Явный вызов конструктора по умолчанию.
}

int StringLength(const char* str)
{
	//Считает размер строки в символах, т.е., без учета Терминирующего нуля
	int i = 0;
	for (; str[i]; i++);
	return i;
}