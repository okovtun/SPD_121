#include"List.h"
#include"List.cpp"

//#define BASE_CHECK
//#define COPY_METHODS_CHECK
#define HOME_WORK

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
	int n;
	cout << "Введите размер списка: "; cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
		//list.push_front(rand() % 100);
	}
	list.print();
	list.reverse_print();
	int index;
	int value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	list.insert(index, value);
	list.print();
	list.reverse_print();
	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	list.erase(index);
	list.print();
	list.reverse_print();
#endif // BASE_CHECK

#ifdef COPY_METHODS_CHECK
	List list = { 3,5,8,13,21 };
	list = list;
	list.print();
	list.reverse_print();

	//List list2 = list;
	List list2;
	list2 = list;
	list2.print();
	list2.reverse_print();
#endif // COPY_METHODS_CHECK

#ifdef HOME_WORK
	List<int> list = { 3,5,8,13,21 };
	for (int i : list)
	{
		cout << i << tab;
	}
	cout << endl;
	for (List<int>::ConstReverseIterator it = list.crbegin(); it != list.crend(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
	print(list);

	List<double> d_list = { 2.5, 3.14, 5.2, 8.3 };
	for (double i : d_list)cout << i << tab; cout << endl;
	for (List<double>::ReverseIterator rit = d_list.rbegin(); rit != d_list.rend(); ++rit)
	{
		cout << *rit << tab;
	}
	cout << endl;

	List<std::string> s_list = { "Have", "a", "nice", "day" };
	for (std::string i : s_list)cout << i << tab; cout << endl;
	for (List<std::string>::ReverseIterator rit = s_list.rbegin(); rit != s_list.rend(); ++rit)
	{
		cout << *rit << tab;
	}
	cout << endl;
#endif // HOME_WORK

	/*
	Class object;		//объявление объекта обычного класса
	Class<type> object;	//объявление объекта шаблонного класса

	Class - обращение к обычному классу
	Class<type> - обращение к шаблонному классу
	template<typename T>
	*/
}