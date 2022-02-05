#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Human
{
protected:
	std::string last_name;
	std::string first_name;
	unsigned int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}
	Human(const std::string& last_name, const std::string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}
	virtual std::ostream& print(std::ostream& os)const
	{
		os << "\n--------------------------------------------------------------------------\n";
		os << std::left;
		os.width(12);
		os << last_name;
		os.width(12);
		os << first_name;
		os.width(3);
		os << age << " лет";
		return os;
	}
	virtual std::ofstream& print(std::ofstream& os)const
	{
		os << std::left;
		os.width(15);
		os << std::string(typeid(*this).name()) + ":";
		os.width(12);
		os << last_name + ",";
		os.width(12);
		os << first_name + ",";
		os.width(3);
		os << std::right;
		os << age;
		return os;
	}

	virtual ifstream& scan(ifstream& is)
	{
		std::getline(is, last_name, ',');
		std::getline(is, first_name, ',');
		last_name.erase(0, last_name.find_first_not_of(' '));
		first_name.erase(0, first_name.find_first_not_of(' '));
		is >> age;
		return is;
	}
};

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return obj.print(os);
}
std::ofstream& operator<<(std::ofstream& os, const Human& obj)
{
	return obj.print(os);
}
std::ifstream& operator>>(std::ifstream& is, Human& obj)
{
	return obj.scan(is);
}

class Student :public Human
{
	std::string speciality;
	std::string group;
	float rating;
	float attendance;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	float get_rating()const
	{
		return rating;
	}
	float get_attendance()const
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(float rating)
	{
		this->rating = rating;
	}
	void set_attendance(float attendance)
	{
		this->attendance = attendance;
	}

	Student
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& speciality, const std::string& group, float rating, float attendance
	) :Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}
	std::ostream& print(std::ostream& os)const
	{
		/*return Human::print(os) << " "
			<< speciality << " "
			<< group << " "
			<< rating << " "
			<< attendance;*/

		Human::print(os) << " | ";
		os << std::left;
		os.width(22);
		os << speciality;
		os.width(8);
		os << group;
		os.width(4);
		os << rating;
		os.width(4);
		os << attendance;

		return os;
	}
	std::ofstream& print(std::ofstream& os)const
	{
		Human::print(os) << ", ";
		os << std::left;
		os.width(22);
		os << speciality + ",";
		os.width(8);
		os << group + ",";
		os.width(4);
		os << std::to_string(rating) + ",";
		os.width(4);
		os << attendance;

		return os;
	}
	ifstream& scan(ifstream& is)
	{
		Human::scan(is);
		is.ignore();
		std::getline(is, speciality, ',');
		std::getline(is, group, ',');

		speciality.erase(0, speciality.find_first_not_of(' '));
		group.erase(0, group.find_first_not_of(' '));

		std::string rating;
		std::getline(is, rating, ',');
		this->rating = std::stod(rating);//stod() string to double
		is >> attendance;
		return is;
	}
};

class Teacher :public Human
{
	std::string speciality;
	unsigned int experience;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}

	Teacher
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& speciality, unsigned int experience
	) :Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	std::ostream& print(std::ostream& os)const
	{
		//return Human::print(os)	<< " " << speciality << " " << experience;

		Human::print(os) << " | ";
		os << std::left;
		os.width(22);
		os << speciality;

		//os << std::right;
		os.width(4);
		os << experience;
		return os;
	}
	std::ofstream& print(std::ofstream& os)const
	{
		Human::print(os) << ", ";
		os << std::left;
		os.width(22);
		os << speciality + ",";
		os.width(4);
		os << experience;
		return os;
	}
	ifstream& scan(ifstream& is)
	{
		Human::scan(is);
		is.ignore();
		std::getline(is, speciality, ',');
		speciality.erase(0, speciality.find_first_not_of(' '));
		is >> experience;
		return is;
	}
};

class Graduate :public Student
{
	std::string subject;
public:
	const std::string& get_subject()const
	{
		return subject;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}
	Graduate
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& speciality, const std::string& group, float rating, float attendance,
		const std::string& subject
	) :Student(last_name, first_name, age, speciality, group, rating, attendance)
	{
		set_subject(subject);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}
	std::ostream& print(std::ostream& os)const
	{
		return Student::print(os) << " | " << subject;
	}
	std::ofstream& print(std::ofstream& os)const
	{
		Student::print(os) << ", " << subject;
		return os;
	}
	ifstream& scan(ifstream& is)
	{
		Student::scan(is);
		std::getline(is, subject);
		subject[subject.find(',')] = ' ';
		subject.erase(0, subject.find_first_not_of(' '));
		return is;
	}
};

Human* humanFactory(std::string& type)
{
	if (type.find("class Student") != std::string::npos)return new Student("", "", 0, "", "", 0, 0);
	if (type.find("class Graduate") != std::string::npos)return new Graduate("", "", 0, "", "", 0, 0, "");
	if (type.find("class Teacher") != std::string::npos)return new Teacher("", "", 0, "", 0);
	return nullptr;
}

//#define INHERITANCE_CHECK
//#define POLYMORPHISM_CHECK
#define READ_FROM_FILE_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef INHERITANCE_CHECK
	Human human("Тупенко", "Василий", 18);
	human.print();

	Student student("Pinkman", "Jessie", 20, "Chemistry", "WW_121", 90, 85);
	student.print();

	Teacher teacher("White", "Walter", 50, "Chemistry", 20);
	teacher.print();

	Graduate graduate("Schrader", "Hank", 40, "Criminalistic", "WW_121", 95, 55, "How to catch Heisenberg");
	graduate.print();
#endif // INHERITANCE_CHECK

#ifdef POLYMORPHISM_CHECK
	//Generalisation:
	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 20, "Chemistry", "WW_121", 90, 85),
		new Teacher("White", "Walter", 50, "Chemistry", 20),
		new Graduate("Schrader", "Hank", 40, "Criminalistic", "WW_121", 95, 55, "How to catch Heisenberg"),
		new Student("Vercetty", "Tomas", 30, "Criminalistic", "Vice", 98, 95),
		new Teacher("Diaz", "Ricardo", 50, "Weapons distribution", 30)
	};

	//cout << "\n----------------------------------\n";
	//Specialisation:
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		//group[i]->print();
		cout << *group[i] << endl;;
		//cout << "\n----------------------------------\n";
	}

	ofstream fout("group.txt");
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		fout << *group[i] << endl;
	}
	fout.close();
	system("notepad group.txt");

	//Очистка памяти:
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete group[i];
	}
#endif // POLYMORPHISM_CHECK

#ifdef READ_FROM_FILE_CHECK
	Human** group = nullptr;
	ifstream fin("group.txt");
	int n = 0;//Размер файла в строках
	if (fin.is_open())
	{
		//1) Считаем размер файла:
		std::string buffer;
		while (!fin.eof())
		{
			std::getline(fin, buffer);
			if (buffer.find("class") != std::string::npos)n++;
		}

		//2) Выделяем память под массив указателей:
		group = new Human*[n] {};
		cout << fin.tellg() << endl;

		//3) Возвращаемся в начало файла, для того, чтобы прочитать его:
		fin.clear();
		fin.seekg(0);
		cout << fin.tellg() << endl;

		//4) Читаем файл, и загружаем его строки в память:
		std::string type;
		for (int i = 0; i < n; i++)
		{
			cout << fin.tellg() << endl;
			std::getline(fin, type, ':');
			group[i] = humanFactory(type);
			fin >> *group[i];
		}

		fin.close();
	}
	else
	{
		cerr << "Error: file not found" << endl;
	}

	for (int i = 0; i < n; i++)
	{
		cout << *group[i] << endl;
	}

	for (int i = 0; i < n; i++)
	{
		delete group[i];
	}
	delete[] group;

#endif // READ_FROM_FILE_CHECK

}