#include<iostream>
#include<array>
#include<vector>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n------------------------------------\n"

//#define STL_ARRAY
#define STL_VECTOR

void main()
{
	setlocale(LC_ALL, "");
#ifdef STL_ARRAY
	//array - это контейнер, который для хранения данных использует статический массив.
	const int N = 5;
	/*int arr[N] = { 3,5,8 };
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;*/
	std::array<int, N> arr = { 3,5,8,13,21 };
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
#endif // STL_ARRAY

#ifdef STL_VECTOR
	//vector - это контейнер, который хранит данные в виде динамического массива.
	std::vector<int> vec = { 0,1,1,2,3,5,8,13,21,34 };
	vec.reserve(25);
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << tab;
	}
	cout << endl;
	cout << "Size:     " << vec.size() << endl;
	cout << "Max size: " << vec.max_size() << endl;
	cout << "Capacity: " << vec.capacity() << endl;
	cout << delimiter << endl;;
	vec.push_back(55);
	vec.shrink_to_fit();
	cout << "Size:     " << vec.size() << endl;
	cout << "Max size: " << vec.max_size() << endl;
	cout << "Capacity: " << vec.capacity() << endl;
	try
	{
		for (int i = 0; i < vec.capacity(); i++)
		{
			cout << vec.at(i) << tab;
			//cout << vec[i] << tab;
		}
		cout << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}

	int index;
	int value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	vec.insert(vec.begin() + index, value);
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
#endif // STL_VECTOR

}