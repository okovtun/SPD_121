#include"String.h"
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
String::String(const char* str) : String(strlen(str) + 1)
{
	for (int i = 0; i < size; i++)this->str[i] = str[i];
	cout << "Constructor:\t" << this << endl;
}
String::String(const String& other) : String(other.str)
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