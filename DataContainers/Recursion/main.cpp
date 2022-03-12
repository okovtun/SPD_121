#include<iostream>
using namespace std;

void elevator(int floor)
{
	if (floor == 0)
	{
		cout << "Вы в подвале" << endl;
		return;
	}
	cout << "Вы на " << floor << " этаже" << endl;
	elevator(floor-1);
	cout << "Вы на " << floor << " этаже" << endl;
}

void main()
{
	setlocale(LC_ALL, "");
	//cout << "Hello";
	//main();
	int floor;
	cout << "Введите номер этажа: "; cin >> floor;
	elevator(floor);
}