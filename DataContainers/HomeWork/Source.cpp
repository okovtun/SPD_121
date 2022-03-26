#include<iostream>
#define DEBUG
class Tree
{
protected:
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRigth;
	public:
		Element(int Data, Element* pLeft = NULL, Element* pRigth = NULL)
			:Data(Data), pLeft(pLeft), pRigth(pRigth)
		{
#ifdef DEBUG
			std::cout << "EConstructor:\t" << this << std::endl;
#endif // DEBUG
		}
		~Element()
		{
#ifdef DEBUG
			std::cout << "EDestructor:\t" << this << std::endl;
#endif // DEBUG
		}
		friend class Tree;
		friend class UniqueTree;
	}*Root;
public:
	Element* get_Root()const
	{
		return this->Root;
	}
	Tree() :Root(nullptr)
	{
#ifdef DEBUG
		std::cout << "TConstructor:\t" << this << std::endl;
#endif // DEBUG
	}
	Tree(const std::initializer_list<int>& il) :Root(NULL)
	{
		for (int const* it = il.begin(); it != il.end(); it++)
			insert(*it);
		std::cout << "IT_Constructor:\t" << this << std::endl;
	}
	Tree(const Tree& other) :Root(NULL)
	{
		copy(other);
		std::cout << "Copy_TConstructor:\t" << this << std::endl;
	}
	~Tree()
	{
		clear(Root);
#ifdef DEBUG
		std::cout << "TDestructor:\t" << this << std::endl;
#endif // DEBUG
	}
	Tree& operator=(const Tree& other)
	{
		if (this == &other)return *this;
		if (this != &other)
		{
			clear(Root);
			copy(other);
		}
		return *this;
	}
	Tree& copy(const Tree& other)
	{
		if (other.Root != NULL)
		{
			Root = (other.Root);
			Root->pLeft = (other.Root->pLeft);
			Root->pRigth = (other.Root->pRigth);
		}
		return *this;
	}
	void insert(int Data)
	{
		return insert(Data, this->Root);
	}
	void erase(int index)
	{
		Element* del = Root;
		Element* pdel = NULL;
		while (del && del->Data != index)
		{
			pdel = del;
			if (del->Data > index)del = del->pLeft;
			else del = del->pRigth;
		}
		if (!del)return;
		if (del->pLeft == NULL)
		{
			if (pdel && pdel->pLeft == del)pdel->pLeft = del->pRigth;
			if (pdel && pdel->pRigth == del)pdel->pRigth = del->pRigth;
			delete del;
			return;
		}
		if (del->pRigth == NULL)
		{
			if (pdel && pdel->pLeft == del)pdel->pLeft = del->pLeft;
			if (pdel && pdel->pRigth == del)pdel->pRigth = del->pLeft;
			delete del;
			return;
		}
		Element* rcnd = del->pRigth;
		while (rcnd)rcnd = rcnd->pLeft;
		int rcnd_value = rcnd->Data;
		erase(rcnd->Data);
		del->Data = rcnd_value;
	}
	int minValue()const
	{
		return minValue(Root);
	}
	int maxValue()const
	{
		return maxValue(Root);
	}
	int count()const
	{
		return count(Root);
	}
	int summ()const
	{
		return summ(Root);
	}
	double avg()const
	{
		return (double)summ() / count();
	}
	bool find(int number)const
	{
		Element* tmp = Root;
		while (tmp && tmp->Data != number)
		{
			if (tmp->Data > number)tmp = tmp->pLeft;
			else tmp = tmp->pRigth;
		}
		return tmp;
	}
	void print()const
	{
		print(Root);
		std::cout << std::endl;
	}
private:
	void insert(int Data, Element* Root)
	{
		if (this->Root == NULL)this->Root = new Element(Data);
		if (Root == NULL)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == NULL)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else
		{
			if (Root->pRigth == NULL)Root->pRigth = new Element(Data);
			else insert(Data, Root->pRigth);
		}
	}
	int minValue(Element* Root)const
	{
		if (Root == NULL)return int();
		if (Root->pLeft == NULL)return Root->Data;
		else return minValue(Root->pLeft);
	}
	int maxValue(Element* Root)const
	{
		if (Root == NULL)return int();
		if (Root->pRigth == NULL)return Root->Data;
		else return maxValue(Root->pRigth);
	}
	int count(Element* Root)const
	{
		if (Root == NULL)return 0;
		else return count(Root->pLeft) + count(Root->pRigth) + 1;
	}
	int summ(Element* Root)const
	{
		if (Root == NULL)return 0;
		else return summ(Root->pLeft) + summ(Root->pRigth) + Root->Data;
	}

	void clear(Element* Root)
	{
		if (Root != NULL)
		{
			clear(Root->pLeft);
			clear(Root->pRigth);
			delete Root;
		}
	}
	void print(Element* Root)const
	{
		if (Root == NULL)return;
		print(Root->pLeft);
		std::cout << Root->Data << "\t";
		print(Root->pRigth);
	}
};
class UniqueTree :public Tree
{
	void insert(int Data, Element* Root)
	{
		if (this->Root == NULL)this->Root = new Element(Data);
		if (Root == NULL)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == NULL)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else if (Data > Root->Data)
		{
			if (Root->pRigth == NULL)Root->pRigth = new Element(Data);
			else insert(Data, Root->pRigth);
		}
	}
public:
	void insert(int Data)
	{
		insert(Data, Root);
	}
};
//#define TREE_BASE
void main()
{
#ifdef TREE_BASE
	int n;
	int value;
	srand(10);

	Tree tree;
	std::cout << "Enter number of tree: "; std::cin >> n;
	for (int i = 0; i < n; i++)	tree.insert(rand() % 100);
	tree.print();

	std::cout << "Enter adding value: "; std::cin >> value;
	tree.insert(value);
	tree.print();

	std::cout << "minValue of tree = " << tree.minValue() << std::endl;
	std::cout << "maxValue of tree = " << tree.maxValue() << std::endl;
	std::cout << "count of tree = " << tree.count() << std::endl;
	std::cout << "summ of tree = " << tree.summ() << std::endl;
	std::cout << "avg of tree = " << tree.avg() << std::endl;

	UniqueTree uniquetree;
	for (int i = 0; i < n; i++)	uniquetree.insert(rand() % 100);
	uniquetree.print();

	std::cout << "Enter adding value: "; std::cin >> value;
	tree.insert(value);
	tree.print();

	std::cout << "count of unique_tree = " << uniquetree.count() << std::endl;
	std::cout << "summ of unique_tree = " << uniquetree.summ() << std::endl;
	std::cout << "avg of unique_tree = " << uniquetree.avg() << std::endl;
	std::cout << "sizeof of uniquetree = " << sizeof(uniquetree) << std::endl;
	std::cout << "length of uniquetree = " << sizeof(uniquetree) * uniquetree.count() << std::endl;
#endif // DEBUG

	Tree itree = { 33, 1, 16, 48, 54, 22, 15, 80 };//IT_Constructor
	itree.print();
	int fnd;
	std::cout << "Enter finded == erased number: "; std::cin >> fnd;
	std::cout << "find: " << itree.find(fnd) << std::endl;
	itree.erase(fnd);
	itree.print();
	std::cout << "find: " << itree.find(fnd) << std::endl;

	//Tree ctree = itree;
	//ctree.print();
	/*Tree ctree;
	ctree = itree;
	ctree.print();*/
}