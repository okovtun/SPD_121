#include<iostream>
#include<thread>
#include<conio.h>
#include<Windows.h>
using namespace std;

#define MIN_TANK_VOLUME	40
#define MAX_TANK_VOLUME	80
#define DEFAULT_TANK_VOLUME 60

class Tank
{
	const int VOLUME;
	double fuel_level;
public:
	int get_volume()const
	{
		return VOLUME;
	}
	double get_fuel_level()const
	{
		return fuel_level;
	}
	double give_fuel(double amount)
	{
		if (fuel_level - amount > 0)fuel_level -= amount;
		else fuel_level = 0;
		return fuel_level;
	}
	void fill(double amount)
	{
		if (amount < 0)return;
		if (fuel_level + amount < VOLUME)fuel_level += amount;
		else fuel_level = VOLUME;
	}
	void info()const
	{
		cout << "Volume:    " << VOLUME << " liters\n";
		cout << "Fuel level:" << fuel_level << " liters\n";
	}
	Tank(int volume) :
		VOLUME(volume >= MIN_TANK_VOLUME && volume <= MAX_TANK_VOLUME ? volume : DEFAULT_TANK_VOLUME)
	{
		//this->VOLUME = volume;
		this->fuel_level = 0;
		cout << "Tank is ready" << this << endl;
	}
	~Tank()
	{
		cout << "Tank is over" << this << endl;
	}
};

#define MIN_ENGINE_CONSUMPTION	5
#define MAX_ENGINE_CONSUMPTION	40
#define DEFAULT_ENGINE_CONSUMPTION 12

class Engine
{
	double consumption;	//расход на 100 км
	double consumption_per_second;
	double default_consumption_per_second;
	bool is_started;
public:
	double get_consumption()const
	{
		return consumption;
	}
	double get_consumption_per_second()const
	{
		return consumption_per_second;
	}
	void set_consumption(double consumption)
	{
		this->consumption = consumption >= MIN_ENGINE_CONSUMPTION && consumption <= MAX_ENGINE_CONSUMPTION ? consumption : DEFAULT_ENGINE_CONSUMPTION;
		this->default_consumption_per_second = this->consumption_per_second = this->consumption*3e-5;
	}
	void start()
	{
		is_started = true;
	}
	void stop()
	{
		is_started = false;
	}
	bool started()const
	{
		return is_started;
	}
	void info()const
	{
		cout << "Consumption per 100 km: " << consumption << " liters.\n";
		cout << "Consumption per second: " << consumption_per_second << " liters.\n";
		cout << "Engine is " << (is_started ? "started" : "stopped") << endl;
	}
	Engine(double consumption)
	{
		set_consumption(consumption);
		this->is_started = false;
		cout << "Engine is ready " << this << endl;
	}
	~Engine()
	{
		cout << "Engine is over " << this << endl;
	}
	void speed_consumption_dependency(double speed)
	{
		if (speed == 0)consumption_per_second = default_consumption_per_second;
		else if (speed < 100)consumption_per_second = this->default_consumption_per_second * 10;
		else this->consumption_per_second = pow(this->default_consumption_per_second, 1/speed*100);
	}
};

#define MAX_SPEED_LOW_LIMIT		60
#define MAX_SPEED_HIGH_LIMIT	300
#define DEFUAULT_MAX_SPEED		200

#define Enter	13
#define Escape	27

class Car
{
	Engine engine;
	Tank tank;
	bool driver_inside;
	int speed;
	const int MAX_SPEED;
	int accelleration;
	struct Control
	{
		std::thread panel_thread;
		std::thread engine_idle_thread;		//холостой ход двигателя
		std::thread free_wheeling_thread;	//движение по инерции
	}control;
public:
	Car(int consumption, int volume, int max_speed) :
		engine(consumption),
		tank(volume),
		MAX_SPEED(max_speed >= MAX_SPEED_LOW_LIMIT && max_speed <= MAX_SPEED_HIGH_LIMIT ? max_speed : DEFUAULT_MAX_SPEED)
	{
		driver_inside = false;
		speed = 0;
		accelleration = MAX_SPEED / 10;
		cout << "Your car is ready to go " << this << endl;
	}
	~Car()
	{
		cout << "Your car is over " << this << endl;
	}
	void fill(double amount)
	{
		tank.fill(amount);
	}
	void get_in()
	{
		driver_inside = true;
		//panel();
		control.panel_thread = std::thread(&Car::panel, this);
	}
	void get_out()
	{
		driver_inside = false;
		system("CLS");
		if (control.panel_thread.joinable())control.panel_thread.join();
		cout << "You are out of your car" << endl;
	}
	void start_engine()
	{
		if (driver_inside && tank.get_fuel_level())
		{
			engine.start();
			control.engine_idle_thread = std::thread(&Car::engine_idle, this);
		}
	}
	void stop_engine()
	{
		engine.stop();
		if (control.engine_idle_thread.joinable())
		{
			control.engine_idle_thread.join();
		}
	}
	void control_car()
	{
		char key;
		do
		{
			key = _getch();
			switch (key)
			{
			case Enter:driver_inside ? get_out() : get_in(); break;
			case 'F':case 'f':
				double fuel;
				cout << "Введите объем топлива: "; cin >> fuel;
				fill(fuel);
				break;
			case 'I':case 'i'://Ignition - зажигание
				engine.started() ? stop_engine() : start_engine();
				break;
			case 'W':case 'w':
				if (driver_inside && engine.started())
				{
					if (speed < MAX_SPEED)speed += accelleration;
					if (speed > MAX_SPEED)speed = MAX_SPEED;
					if (!control.free_wheeling_thread.joinable())
						control.free_wheeling_thread = std::thread(&Car::free_wheeling, this);
					std::this_thread::sleep_for(1s);
				}
				break;
			case 'S':case 's':
				if (driver_inside && speed > 0)
				{
					speed -= accelleration;
					if (speed < 0)speed = 0;
					std::this_thread::sleep_for(1s);
				}
				break;
			case Escape:
				speed = 0;
				stop_engine();
				get_out();
				break;
			}
			if (!engine.started() && control.engine_idle_thread.joinable())
				control.engine_idle_thread.join();
			if (speed == 0 && control.free_wheeling_thread.joinable())
				control.free_wheeling_thread.join();
			engine.speed_consumption_dependency(speed);
		} while (key != Escape);
	}
	void free_wheeling()
	{
		while (speed > 0)
		{
			speed--;
			if (speed < 0)speed = 0;
			std::this_thread::sleep_for(1s);
		}
	}
	void engine_idle()
	{
		while (engine.started() && tank.give_fuel(engine.get_consumption_per_second()))
		{
			if (tank.get_fuel_level() == 0)engine.stop();
			std::this_thread::sleep_for(1s);
		}
	}
	void panel()const
	{
		while (driver_inside)
		{
			system("CLS");
			for (int i = 0; i < speed/3; i++)cout << "|";
			cout << endl;
			cout << "Speed:\t" << speed << " km/h\n";
			cout << "Fuel level: " << tank.get_fuel_level() << " liters.";
			if (tank.get_fuel_level() < 5)
			{
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, 0xCF);
				cout << "LOW FUEL";
				SetConsoleTextAttribute(hConsole, 0x07);
			}
			cout << endl;
			cout << "Engine is " << (engine.started() ? "started" : "stopped") << endl;
			cout << "Consumption per second: " << engine.get_consumption_per_second() << " liters.\n";
			std::this_thread::sleep_for(200ms);
		}
	}
};

//#define TANK_CHECK
//#define ENGINE_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef TANK_CHECK
	Tank tank(100);
	int amount;
	do
	{
		tank.info();
		cout << "Введите объем топлива: "; cin >> amount;
		tank.fill(amount);
	} while (true);
#endif // TANK_CHECK

#ifdef ENGINE_CHECK
	Engine engine(3);
	engine.info();
#endif // ENGINE_CHECK

	Car bmw(10, 60, 250);
	bmw.control_car();
}