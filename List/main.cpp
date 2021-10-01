#include <iostream>
using namespace std;

#define tab "\t"
#define delimitr "\n======================\n"


template<typename T>
class List
{
	class Element
	{
		Element* pPrev;
		Element* pNext;
		T Data;
	public:
		Element(T Data, Element* pNext = nullptr, Element* pPrev = nullptr) :
			Data(Data), pNext(pNext), pPrev(pPrev)
		{
#ifdef DEBUG
			cout << "EConstructor:" << tab << endl;
#endif // DEBUG
		}
		~Element()
		{
#ifdef DEBUG
			cout << "EDestructor:" << tab << this << endl;
#endif // DEBUG
		}
		friend class List;
	}*Head, *Tail ;
	size_t size;
public:
	class Iterator
	{
		Element* Temp;
	public:
		Iterator(Element* Temp = nullptr) :Temp(Temp)
		{
#ifdef DEBUG
			cout << "ItConstructor" << tab << this << endl;
#endif // DEBUG

		}
		~Iterator()
		{
#ifdef DEBUG
			cout << "ItDestructor:" << tab << this << endl;
#endif // DEBUG

		}

		Iterator& operator++()
		{
			Temp=Temp->pNext;
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
			return this->Temp !=  other.Temp;
		}
		const int& operator*()const
		{
			return this->Temp->Data;
		}
		int& operator*()
		{
			return this->Temp->Data;
		}

	};
	Iterator begin()
	{
		return Head;
	}
	Iterator end()
	{
		return nullptr;
	}
	size_t get_size()const
	{
		return this->size;
	}
	List()
	{
		size = 0;
		Head = Tail = nullptr;
#ifdef DEBUG
		cout << "LConstructor:" << tab << this << endl;
#endif // DEBUG

	}
	List(const initializer_list<T>& il) :List()
	{
		for (T const* it = il.begin(); it != il.end(); it++)		
			push_back(*it);
	}
	List(const List<T>& other) :List()
	{
		cout << "LCopyConstructor:" << tab << this << endl;
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)push_back(Temp->Data);
	}

	~List()
	{
		//while (Head)pop_front();
		while (Tail)pop_back();
#ifdef DEBUG
		cout << "LDestructor:" << tab << this << endl;
#endif // DEBUG

	}

	//				Operators:
	List<T>& operator=(const List<T>& other)
	{
		if (this == &other)return *this;
		while (Head)pop_front();
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)push_back(Temp->Data);
#ifdef DEBUG
		cout << "LCopyAssignement" << tab << this << endl;
#endif // DEBUG

		return *this;
	}

	//				Adding elements:

	void push_front(T Data)
	{
		if (Head ==nullptr && Tail == nullptr) {
			Head = Tail = new Element(Data);
		}
		else {
			/*Element* New = new Element(Data);
			New->pNext = Head;
			Head->pPrev = New;
			Head = New;*/
			Head = Head->pPrev = new Element(Data, Head);
		}
		
		size++;
	}
	void push_back(T Data)
	{
		if (!Head && !Tail)
		{
			return push_front(Data);
		}
		else
		{
			/*Element* New = new Element(Data);
			New->pPrev = Tail;
			Tail->pNext = New;
			Tail = New;*/
			Tail = Tail->pNext = new Element(Data, nullptr, Tail);
			size++;
		}
	}
	/*void insert(int index, int Data)
	{
		
	}*/

	//				Removing elements:
	void pop_front()
	{
		//if (Head == nullptr && Tail == nullptr)return;
		//0) Проверяем не является ли удаляемый элемент списка последним
		if (Head == Tail)
		{
			delete Head;
			Head = Tail = nullptr;
			return;
		}
		//1) Исключаем элемент из списка:
		Head = Head->pNext;
		//2) Удаляем элемент из памяти
		delete Head->pPrev;
		//3) "Забываем" об удалкенном элементе:
		Head->pPrev = nullptr;
		size--;
	}
	void pop_back()
	{
		if (Head == Tail)return pop_front();
		Tail = Tail->pPrev;
		delete Tail->pNext;
		Tail->pNext = nullptr;
		size--;
	}

	//				Methods:
	void print()const
	{
		cout << "Адрес начала списка: " <<Head<< endl;
		for (Element* Temp = Head; Temp; Temp =Temp->pNext)
		{
			cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		}
	}
	void print_reverse()const
	{
		cout << "Адрес конца списка: " << Tail << endl;
		for (Element* Temp = Tail; Temp; Temp=Temp->pPrev)
		{
			cout << Temp->pPrev << tab <<Temp<<tab << Temp->Data << tab << Temp->pNext << endl;
		}
	}
};
//#define BASE_CHECK
//#define ITERATORS_CHECK

void main()
{
	setlocale(LC_ALL, "rus");
#ifdef BASE_CHECK
	int n;
	cout << "Введите размер списка: "; cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		//list.push_back(rand() % 100);
		list.push_back(rand() % 100);
	}

	list.print();
	cout << delimitr;
	list.pop_front();
	list.print();
	list.print_reverse();  
#endif // BASE_CHECK

#ifdef ITERATORS_CHECK
	List list = { 3, 5, 8, 13, 21 };
	list.print();
	/*List list2 = list;
	list2.print();
	list2.print_reverse();*/
	List list2;
	list2 = list;
	//list2.print();
	for (List::Iterator it = list2.begin(); it != list2.end(); it++)
	{
		cout << *it << tab;
	}
	list2.print_reverse();
#endif // ITERATORS_CHECK

	//int arr[] = { 3, 5, 8, 13, 21 };
	//for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	//{
	//	cout << arr[i] << tab;
	//}
	//for(int i =0; i <sizeof(arr) / sizeof(*arr); i++)
	//	cout << *(arr + i) << endl;

	//for (int i : arr) // Range-based for
	//	cout << i << tab;
	//cout << endl;


	List<int> list = { 0, 1, 1, 2, 3, 5, 8, 13, 21 };
	for (int i : list)
	{
		cout << i << tab;
	}
	cout << endl;
}