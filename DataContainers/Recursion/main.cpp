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
	elevator(floor - 1);
	cout << "Вы на " << floor << " этаже" << endl;
}

long long int factorial(int n)
{
	/*if (n == 0)return 1;
	else return n * factorial(n - 1);*/
	return n == 0 ? 1 : n * factorial(n - 1);
}

double power(double a, int n)
{
	/*if (n == 0)return 1;
	//else if (n < 0)return 1 / a * power(a, n + 1);
	else if (n < 0)return power(1 / a, -n);
	else return a * power(a, n - 1);*/

	return n == 0 ? 1 : n > 0 ? a * power(a, n - 1) : power(1 / a, -n);
}

//#define ELEVATOR
//#define FACTORIAL

void main()
{
	setlocale(LC_ALL, "");
	//cout << "Hello";
	//main();
#ifdef ELEVATOR
	int floor;
	cout << "Введите номер этажа: "; cin >> floor;
	elevator(floor);
#endif // ELEVATOR

#ifdef FACTORIAL
	int n;
	cout << "Введите число для вычисления факториала: "; cin >> n;
	//Здесь main() - вызывающая функция (caller - тот, кто вызывает)
	//а factorial(int n) - вызываемая функция (callee - та, которую вызывают)
	cout << factorial(n) << endl;
#endif // FACTORIAL

	int a;	//основание степени
	int n;	//показатель степени
	cout << "Введите основание степени: "; cin >> a;
	cout << "Введите показатель степени: "; cin >> n;
	cout << power(a, n) << endl;
}