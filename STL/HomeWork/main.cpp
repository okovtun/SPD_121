#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<conio.h>

#define tab "\t"
#define delimiter "\n------------------------\n"


class Number
{
	std::string number;
public:
	std::string get_number()const
	{
		return number;
	}
	void set_number(const std::string number)
	{
		this->number = number;
	}
	Number()
	{
		std::cout << "N_Default_Constructor:\t" << this << std::endl;
	}
	Number(std::string number) :number(number)
	{
		std::cout << "N_Constructor:\t" << this << std::endl;
	}
	~Number()
	{
		std::cout << "N_Destructor:\t" << this << std::endl;
	}

	bool operator==(const Number& other)const
	{
		return this->number == other.number;
	}
	bool operator!=(const Number& other)const
	{
		return this->number != other.number;
	}
	bool operator>(const Number& other)const
	{
		return this->number > other.number;
	}
	bool operator<(const Number& other)const
	{
		return this->number < other.number;
	}

};

std::ostream& operator<<(std::ostream& os, const Number& obj)
{
	return os << obj.get_number();
}

class Data
{
	std::string field_1;

public:
	const std::string& get_field_1()const
	{
		return field_1;
	}

	void set_field_1(const std::string& field_1)
	{
		this->field_1 = field_1;
	}

	Data()
	{
		std::cout << "Default_D_Constructor" << this << std::endl;
	}
	Data(const std::string field_1) :field_1(field_1)
	{
		std::cout << "D_Constructor:\t" << this << std::endl;
	}
	~Data()
	{
		std::cout << "D_Destructor:\t" << this << std::endl;
	}

	bool operator==(const Data& other)const
	{
		return this->field_1 == other.field_1;
	}
	bool operator!=(const Data& other)const
	{
		return this->field_1 == other.field_1;
	}


	/*void print()const
	{
		std::cout << "Number of caar: " << number << std::endl;
		std::cout << "Data of protocl: " << field_1 << std::endl;
	}*/
};

std::ostream& operator<<(std::ostream& os, const Data& obj)
{
	return os << obj.get_field_1();
}

//std::ostream& operator<<(std::ostream& os, const std::pair<Number, Data>& obj)
//{
//	return os << obj;
//}



void print(std::string& num, std::string& prt)
{
	std::cout << "Number of caar: " << num << std::endl;
	std::cout << "Data of protocl: " << prt << std::endl;
}

void main()
{


	char num[20];
	char prt[100];
	std::vector<std::string> pr;

	int select;
	char end;

	//std::map<std::string, std::string> event;
	std::map<Number, Data> event;
	std::map<Number, Data>::iterator it;

	do
	{
		std::cout << "For enter new elements, press '1'" << std::endl;
		std::cout << "For output elements, press '2'" << std::endl; std::cin >> select;
		switch (select)
		{
		case 1:

			std::cout << "Enter number of caar: ";
			std::cin.ignore();
			std::cin.getline(num, 20);
			std::cout << "Enter data of protocl: "; 
			std::cin.ignore();
			std::cin.getline(prt, 100);
			std::pair<Number, Data>(num, prt);
			if (event.find(Number(num)) == event.end())
			{
				event.insert(std::pair<Number, Data>(num, prt));
			}
			else
			{

			}
			break;

		case 2:
			for (it = event.begin(); it != event.end(); ++it)
			{
				std::cout << "Number of caar: " << it->first << "\n" << "Type of violation: " << it->second << std::endl;
			}
			break;
		}

		std::cout << "To continue press any key, to exit press ESCAPE\n";
		end = _getch();
	} while (end != 27);

}