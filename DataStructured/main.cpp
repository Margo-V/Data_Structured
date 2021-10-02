#include <iostream>
using namespace std;

#define tab "\t"
#define delimitr "\n===========================\n"


template <typename T>
class ForwardList 
{
	size_t size;

	class Element
	{
		int Data;
		Element* pNext;
	public:
		Element(T Data, Element* pNext = nullptr) : Data(Data), pNext(pNext) { cout << "EConstr" << endl; }
		~Element(){ cout << "EDestr" << endl; }
		friend class ForwardList;
	}*Head;
public:
	class Iterator 
	{
		Element* Temp;
	public:
		Iterator(Element* Temp = nullptr) :Temp(Temp)
		{
			cout << "ItConstructor:" << tab << this << endl;
		}
		~Iterator()
		{
			cout << "ItDestructor:" << tab << endl;
		}
		Iterator& operator++()//Prefix increment
		{
			Temp = Temp->pNext;
			return *this;
		}
		Iterator operator++(int) 
		{
			Iterator old = *this;
			Temp = Temp->pNext;
			return old;
		}
		bool operator==(const Iterator& other)const
		{
			return this->Temp == other.Temp;
		}
		bool operator!=(const Iterator& other)const
		{
			return this->Temp != other.Temp;
		}
		int& operator*()
		{
			return Temp->Data;
		}
	};
	Iterator begin()
	{
		return this->Head;
	}
	Iterator end()
	{
		return nullptr;
	}


	ForwardList<T>()
	{
		cout << "F-LConstr" << endl;
		Head = nullptr;
		size = 0;
	}

	ForwardList<T>(const ForwardList<T>& other) :ForwardList<T>()
	{
		for (Element* Temp = other.Head; Temp; Temp->pNext)
		{
			push_back(Temp->Data);
		}
	}
	ForwardList<T>(const initializer_list<int>& il) :ForwardList()
	{
		//cout << typeid(il.begin()).name() << endl;
		for (int const* it= il.begin(); it != il.end(); it++)
		{
			this->push_back(*it);
		}
	}
	~ForwardList()
	{
		while (Head)pop_front();
		cout << "F-LDestr" << endl;
	}
	//					Adding elements:
	void push_front(T Data)
	{
		Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;
		size++;
	}
	void push_back(T Data)
	{
		if (Head == nullptr) return push_front(Data);
		Element* Temp = Head;
		while (Temp->pNext)		
			Temp = Temp->pNext;		
		Temp->pNext = new Element(Data);
		size++;
	}
	void insert(int index, T Data)
	{
		if (Head == 0)return push_front(Data);
		if (index >= size)return push_back(Data);
		Element* Temp = Head;
		for (int i = 0; i < index-1; i++)
		{
			Temp = Temp->pNext;
		}
		Element* New = new Element(Data);
		New->pNext = Temp->pNext;
		Temp->pNext = New;
		size++;
	}

	//					Removing elements
	void pop_front()
	{
		Element* Deleted = Head;
		Head = Head->pNext;
		delete Deleted;
		size--;
	}
	void pop_back()
	{
		Element* Temp = Head;
		while (Temp->pNext->pNext)
			Temp = Temp->pNext;
		delete Temp->pNext;
		Temp->pNext = nullptr;
		size--;
	}
	void erase(int index)
	{
		if (Head == 0)return pop_front();
		if (index >= size)return pop_back();
		Element* Temp = Head;
		for (int i = 0; i < index-1; i++)
		{
			Temp = Temp->pNext;
		}
		Element* Del = Temp->pNext;
		Temp->pNext = Del->pNext;
		delete Del;
		size--;
	}

	//					Operators:
	ForwardList<T>& operator=(const ForwardList<T>& other)
	{
		while (Head)pop_front();
		for (Element* Temp = other.Head; Temp; Temp->pNext)
		{
			push_back(Temp->Data);
		}
		return *this;
	}

	void print()
	{
		Element* Temp = Head;
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;
		}
	}
};

//#define INITIALIZE_L
//#define TEST

void main() 
{
	setlocale(LC_ALL, "rus");
	/*ForwardList list;
	int size, index, Data;
	cout << "Введите количество элементов списка: "; cin >> size;
	for (int i = 0; i < size; i++)
	{
		list.push_back(rand() % 15);
	}
	list.print();
	cout << delimitr;*/

#ifdef TEST
	cout << "Введите индекс: "; cin >> index;
	cout << "Введите значение: "; cin >> Data;
	list.insert(index, Data);
	list.print();
	cout << delimitr;
#endif // TEST



	/*cout << "Введите индекс: "; cin >> index;
	list.erase(index);
	list.print();*/
#ifdef INITIALIZE_L
	ForwardList list2 = { 3, 5, 8, 12, 23 };
	list2.print();
#endif // INITIALIZE_L

	ForwardList<int> list = { 3, 5, 8, 13, 21 };
	list.print();
	cout << "Range-based for:" << endl;
	for (int i : list)
		cout << i << tab;
	cout << endl;
	cout << delimitr << endl;



	//cout << "Original for:" << endl;
	//for (ForwardList::Iterator it = list.begin(); it != list.end(); it++)
	////for (ForwardList::Iterator it = list.begin(), end = list.end(); it != end; ++it)
	//{
	//	cout << *it << tab;
	//}
	//cout << delimitr << endl;
}