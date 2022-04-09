#include<iostream>
#include<thread>

using namespace std;
using namespace std::chrono_literals;	//Для временных констант 1s, 1ms,

bool finish = false;

void Plus()
{
	while (!finish)
	{
		cout << "+ ";
		std::this_thread::sleep_for(1s);
	}
}
void Minus()
{
	while (!finish)
	{
		cout << "- ";
		std::this_thread::sleep_for(1s);
	}
}

void main()
{
	std::thread plus_thread(Plus);
	std::thread minus_thread(Minus);

	cin.get();
	finish = true;

	minus_thread.join();
	plus_thread.join();
}