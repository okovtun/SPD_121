#include<iostream>
#include<string>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

template<typename T>class List
{
	class Element
	{
		T Data;
		Element* pNext;
		Element* pPrev;
	public:
		Element(T Data, Element* pNext = nullptr, Element* pPrev = nullptr)
			:Data(Data), pNext(pNext), pPrev(pPrev)
		{
			cout << "EConstructor:\t" << this << endl;
		}
		~Element()
		{
			cout << "EDestructor:\t" << this << endl;
		}
		friend class List<T>;
	}*Head, *Tail;
	size_t size;

	class ConstBaseIterator
	{
	protected:
		Element* Temp;
	public:
		ConstBaseIterator(Element* Temp);
		~ConstBaseIterator();

		bool operator==(const ConstBaseIterator& other)const;
		bool operator!=(const ConstBaseIterator& other)const;

		const T& operator*()const;
	};
public:
	class ConstIterator:public ConstBaseIterator
	{
	public:
		ConstIterator(Element* Temp);
		~ConstIterator();
		ConstIterator& operator++();
		ConstIterator operator++(int);
		ConstIterator& operator--();
		ConstIterator operator--(int);
	};
	class ConstReverseIterator:public ConstBaseIterator
	{
	public:
		ConstReverseIterator(Element* Temp);
		~ConstReverseIterator();
		
		ConstReverseIterator& operator++();
		ConstReverseIterator operator++(int);
		ConstReverseIterator& operator--();
		ConstReverseIterator operator--(int);
	};

	class Iterator :public ConstIterator
	{
	public:
		Iterator(Element* Temp) :ConstIterator(Temp) {}
		~Iterator(){}

		T& operator*()
		{
			return ConstBaseIterator::Temp->Data;
		}
	};
	class ReverseIterator :public ConstReverseIterator
	{
	public:
		ReverseIterator(Element* Temp) :ConstReverseIterator(Temp) {}
		~ReverseIterator() {}

		T& operator*()
		{
			return ConstBaseIterator::Temp->Data;
		}
	};
	//////////////////////////////////////////////////////////////////////////////////////
	ConstIterator cbegin()const;
	ConstIterator cend()const;

	ConstReverseIterator crbegin()const;
	ConstReverseIterator crend()const;

	Iterator begin();
	Iterator end();
	ReverseIterator rbegin();
	ReverseIterator rend();
	///////////////////////////////////////////////////////////////////////
	List();
	List(const std::initializer_list<T>& il);
	List(const List& other);
	~List();

	//				Operators
	List& operator=(const List& other);

	//				Addign elements:
	void push_front(T Data);
	void push_back(T Data);
	void insert(int Index, T Data);

	//				Removing elements:
	void pop_front();
	void pop_back();
	void erase(int index);

	//				Methods:
	void print()const;
	void reverse_print()const;
};

template<typename T>List<T>::ConstBaseIterator::ConstBaseIterator(Element* Temp) :Temp(Temp)
{
#ifdef DEBUG
	cout << "BItConstructor:\t" << this << endl;
#endif // DEBUG
}
template<typename T>List<T>::ConstBaseIterator::~ConstBaseIterator()
{
#ifdef DEBUG
	cout << "BItDestructor:\t" << this << endl;
#endif // DEBUG
}

template<typename T>bool List<T>::ConstBaseIterator::operator==(const ConstBaseIterator& other)const
{
	return this->Temp == other.Temp;
}
template<typename T>bool List<T>::ConstBaseIterator::operator!=(const ConstBaseIterator& other)const
{
	return this->Temp != other.Temp;
}

template<typename T>const T& List<T>::ConstBaseIterator::operator*()const
{
	return Temp->Data;
}

template<typename T>List<T>::ConstIterator::ConstIterator(Element* Temp) :ConstBaseIterator(Temp)
{
#ifdef DEBUG
	cout << "CItConstructor:\t" << this << endl;
#endif // DEBUG
}
template<typename T>List<T>::ConstIterator::~ConstIterator()
{
#ifdef DEBUG
	cout << "CItDestructor:\t" << this << endl;
#endif // DEBUG
}
template<typename T>typename List<T>::ConstIterator& List<T>::ConstIterator::operator++()
{
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
	return *this;
}
template<typename T>typename List<T>::ConstIterator List<T>::ConstIterator::operator++(int)
{
	ConstIterator old = *this;
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
	return old;
}
template<typename T>typename List<T>::ConstIterator& List<T>::ConstIterator::operator--()
{
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
	return *this;
}
template<typename T>typename List<T>::ConstIterator List<T>::ConstIterator::operator--(int)
{
	ConstIterator old = *this;
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
	return old;
}

template<typename T>List<T>::ConstReverseIterator::ConstReverseIterator(Element* Temp) :ConstBaseIterator(Temp)
{
#ifdef DEBUG
	cout << "RItConstructor:\t" << this << endl;
#endif // DEBUG
}
template<typename T>List<T>::ConstReverseIterator::~ConstReverseIterator()
{
#ifdef DEBUG
	cout << "RItDestructor:\t" << this << endl;
#endif // DEBUG
}

template<typename T>typename List<T>::ConstReverseIterator& List<T>::ConstReverseIterator::operator++()
{
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
	return *this;
}
template<typename T>typename List<T>::ConstReverseIterator List<T>::ConstReverseIterator::operator++(int)
{
	ConstReverseIterator old = *this;
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
	return old;
}
template<typename T>typename List<T>::ConstReverseIterator& List<T>::ConstReverseIterator::operator--()
{
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
	return *this;
}
template<typename T>typename List<T>::ConstReverseIterator List<T>::ConstReverseIterator::operator--(int)
{
	ConstReverseIterator old = *this;
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
	return old;
}

template<typename T>typename List<T>::ConstIterator List<T>::cbegin()const	//cbegin() - const begin
{
	return Head;
}
template<typename T>typename List<T>::ConstIterator List<T>::cend()const
{
	return nullptr;
}

template<typename T>typename List<T>::ConstReverseIterator List<T>::crbegin()const
{
	return Tail;
}
template<typename T>typename List<T>::ConstReverseIterator List<T>::crend()const
{
	return nullptr;
}

template<typename T>typename List<T>::Iterator List<T>::begin()
{
	return Head;
}
template<typename T>typename List<T>::Iterator List<T>::end()
{
	return nullptr;
}
template<typename T>typename List<T>::ReverseIterator List<T>::rbegin()
{
	return Tail;
}
template<typename T>typename List<T>::ReverseIterator List<T>::rend()
{
	return nullptr;
}

template<typename T>List<T>::List()
{
	Head = Tail = nullptr;
	size = 0;
	cout << "LConstructor:\t" << this << endl;
}
template<typename T>List<T>::List(const std::initializer_list<T>& il) :List()
{
	for (T const* it = il.begin(); it != il.end(); it++)
		push_back(*it);
}
template<typename T>List<T>::List(const List& other) :List()
{
	//RAII - Resource Aqusition Is Initialisation 
	//		(Выделение ресурсов это инициализация)
	/*for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
		push_back(Temp->Data);
	cout << "CopyConstrcutor:\t" << this << endl;*/
	*this = other;
}
template<typename T>List<T>::~List()
{
	//while (Head)pop_front();
	while (Tail)pop_back();
	cout << "LDestructor:\t" << this << endl;
}

//				Operators
template<typename T>List<T>& List<T>::operator=(const List<T>& other)
{
	if (this == &other)return *this;
	while (Head)pop_front();
	for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
		push_back(Temp->Data);
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}

//				Addign elements:
template<typename T>void List<T>::push_front(T Data)
{
	if (Head == nullptr && Tail == nullptr)
	{
		Head = Tail = new Element(Data);
		size++;
		return;
	}
	/*Element* New = new Element(Data);
	New->pNext = Head;
	Head->pPrev = New;
	Head = New;*/
	Head = Head->pPrev = new Element(Data, Head);
	size++;
}
template<typename T>
void List<T>::push_back(T Data)
{
	if (Head == nullptr && Tail == nullptr)return push_front(Data);
	Tail = Tail->pNext = new Element(Data, nullptr, Tail);
	size++;
}
template<typename T>void List<T>::insert(int Index, T Data)
{
	if (Index > size)return;
	if (Index == 0)return push_front(Data);
	if (Index == size)return push_back(Data);
	Element* Temp;
	if (Index < size / 2)
	{
		Temp = Head;
		for (int i = 0; i < Index; i++)Temp = Temp->pNext;
	}
	else
	{
		Temp = Tail;
		for (int i = 0; i < size - 1 - Index; i++)Temp = Temp->pPrev;
	}
	Element* New = new Element(Data);
	New->pNext = Temp;
	New->pPrev = Temp->pPrev;
	Temp->pPrev->pNext = New;
	Temp->pPrev = New;
	size++;
}

//				Removing elements:
template<typename T>void List<T>::pop_front()
{
	if (Head == nullptr && Tail == nullptr)return;
	if (Head == Tail)
	{
		delete Head;
		Head = Tail = nullptr;
		size--;
		return;
	}
	Head = Head->pNext;
	delete Head->pPrev;
	Head->pPrev = nullptr;
	size--;
}
template<typename T>void List<T>::pop_back()
{
	if (Head == Tail)return pop_front();
	Tail = Tail->pPrev;
	delete Tail->pNext;
	Tail->pNext = nullptr;
	size--;
}
template<typename T>void List<T>::erase(int index)
{
	if (index == 0)return pop_front();
	if (index == size - 1)return pop_back();
	if (index >= size)return;
	Element* Temp;
	if (index < size / 2)
	{
		Temp = Head;
		for (int i = 0; i < index; i++)Temp = Temp->pNext;
	}
	else
	{
		Temp = Tail;
		for (int i = 0; i < size - index - 1; i++)Temp = Temp->pPrev;
	}
	//1) Исключаем элемент из списка
	Temp->pPrev->pNext = Temp->pNext;
	Temp->pNext->pPrev = Temp->pPrev;
	//2) Удаляем элемент из памяти:
	delete Temp;
	//3)
	size--;
}

//				Methods:
template<typename T>void List<T>::print()const
{
	for (Element* Temp = Head; Temp; Temp = Temp->pNext)
		cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	cout << "Количество элементов в списке: " << size << endl;
}
template<typename T>void List<T>::reverse_print()const
{
	for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
		cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	cout << "Количество элементов в списке: " << size << endl;
}

template<typename T>void print(const List<T>& list)
{
	//				type		name
	//	List<T>::ConstIterator	it
	for (typename List<T>::ConstIterator it = list.cbegin(); it != list.cend(); it++)
	{
		//(*it) *= 10;
		cout << *it << tab;
	}
	cout << endl;
}

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