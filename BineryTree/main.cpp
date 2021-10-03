#include <iostream>
using namespace std;

class Tree
{
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr) 
			:Data(Data), pLeft(pLeft), pRight(pRight)
		{
#ifdef DEBUG
			this->Data = Data;
			this->pLeft = pLeft;
			this->pRight;
#endif // DEBUG
			cout << "EConstructor: " << this << endl;
		}
		~Element()
		{
			cout << "EDestructor: " << this << endl;
		}
		friend class Tree;
	}*Root;
public:
	Element* getRoot()const
	{
		return Root;
	}
	Tree()
	{
		this->Root = nullptr;
		cout << "TConstructor: " << this << endl;
	}
	~Tree()
	{
		cout << "TDestructor: " << this << endl;
	}

	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)
		{
			this->Root = new Element(Data);
			return;
		}
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else
		{
			if (Root->pRight)insert(Data, Root->pRight);
			else Root->pRight = new Element(Data);
		}
	}
	void print(Element* Root)const
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		cout << Root->Data << "\t";
		print(Root->pRight);
	}
};


void main()
{
	setlocale(LC_ALL, "ru");
	int n;
	cout << "¬ведите размер дерева: "; cin >> n;
	Tree tree;
	for (int i = 0; i < n; i++)
		tree.insert(rand() % 100, tree.getRoot());
	tree.print(tree.getRoot());
}