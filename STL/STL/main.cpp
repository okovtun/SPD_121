#include<iostream>
#include<array>
#include<vector>
#include<deque>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n------------------------------------\n"

//#define STL_ARRAY
//#define STL_VECTOR
#define STL_DEQUE

void main()
{
	setlocale(LC_ALL, "");
#ifdef STL_ARRAY
	//array - ��� ���������, ������� ��� �������� ������ ���������� ����������� ������.
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
	//vector - ��� ���������, ������� ������ ������ � ���� ������������� �������.
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

	/*int index;
	int count;
	int value;
	cout << "������� ������ ������������ ��������: "; cin >> index;
	cout << "������� ���������� ����������: "; cin >> count;
	cout << "������� �������� ������������ ��������: "; cin >> value;
	vec.insert(vec.begin() + index, count, value);*/
	vec.insert(vec.begin() + 3, { 1024, 2048, 3072 });
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
#endif // STL_VECTOR

#ifdef STL_DEQUE
	//deque - ��� ���������, ������� ������������ ����� ������ ������������ ��������
	//(������ ��������).
	std::deque<int> deque = { 3,5,8,13,21 };
	deque.push_back(34);
	deque.push_back(55);
	deque.push_back(89);

	deque.push_front(2);
	deque.push_front(1);
	deque.push_front(1);
	deque.push_front(0);
	for (int i : deque)
	{
		cout << i << tab;
	}
	cout << endl;
#endif // STL_DEQUE

}