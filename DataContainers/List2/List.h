#pragma once
#include<iostream>
#include<string>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

///////////////////////////////////////////////////////////////////////////////////
////////////////		CLASS DECLARATION - Œ¡⁄ﬂ¬À≈Õ»≈  À¿——¿		///////////////
///////////////////////////////////////////////////////////////////////////////////

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
	class ConstIterator :public ConstBaseIterator
	{
	public:
		ConstIterator(Element* Temp);
		~ConstIterator();
		ConstIterator& operator++();
		ConstIterator operator++(int);
		ConstIterator& operator--();
		ConstIterator operator--(int);
	};
	class ConstReverseIterator :public ConstBaseIterator
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
		~Iterator() {}

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

///////////////////////////////////////////////////////////////////////////////////
///////////		CLASS DECLARATION END -  ŒÕ≈÷ Œ¡⁄ﬂ¬À≈Õ»ﬂ  À¿——¿		///////////////
///////////////////////////////////////////////////////////////////////////////////
template<typename T>void print(const List<T>& list);