#include <iostream>
using namespace std;

#define tab "\t"

class Element
{
	Element* pPrev;
	Element* pNext;
	int Data;
public:
	Element(int Data, Element* pNext=nullptr, Element* pPrev=nullptr) :
		Data(Data), pNext(pNext), pPrev(pPrev){}
	~Element(){}

	friend class List;
};

class List
{
	Element* Head;
	Element* Tail;
	size_t size;
public:
	List()
	{
		size = 0;
		Head = Tail = nullptr;
	}
	~List(){}

	//				Adding elements:

	void push_front(int Data)
	{
		if (Head ==nullptr && Tail == nullptr) {
			Head = Tail = new Element(Data);
			return;
		}
		Element* New = new Element(Data);
		New->pNext = Head;
		Head->pPrev = New;
		Head = New;
		size++;
	}
	void push_back(int Data)
	{
		if (Head == nullptr && Tail == nullptr)return push_front(Data);
		Element* New = new Element(Data);
		New->pPrev = Tail;
		Tail->pNext = New;
		Tail = New;
		size++;
	}
	/*void insert(int index, int Data)
	{
		
	}*/

	//				Removing elements:
	/*void pop_front()
	{
		if (Head == nullptr && Tail == nullptr)return;
	}*/

	//				Methods:
	void print()
	{
		Element* Temp = Head;
		for (Element* Temp = Head; Temp; Temp->pNext)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;
		}
	}
	void print_reverse()
	{
		Element* Temp = Tail;
		for (Element* Temp = Tail; Temp; Temp->pPrev)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pPrev << endl;
			Temp = Temp->pPrev;
		}
	}
};

void main()
{
	setlocale(LC_ALL, "rus");
	List list;
	list.push_back(123);
	list.push_back(122);
	list.push_back(121);
	list.print();
	//list.print_reverse();

}