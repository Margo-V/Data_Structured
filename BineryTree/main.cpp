#include <iostream>
using namespace std;

#define tab "\t"

class Tree
{
	class Node
	{
		int Data;
		Node* pLeft;
		Node* pRight;
	public:
		Node(int Data, Node* pLeft = nullptr, Node* pRight = nullptr)
			:Data(Data), pLeft(pLeft), pRight(pRight)
		{
			cout << "NConstructor:" << tab << this << endl;
		}
		~Node()
		{
			cout << "NDestructor:" << tab << this << endl;
		}
		friend class Tree;
	}*Root;

public:
	Tree()
	{
		this->Root = nullptr;
		cout << "TConstructor" << tab << this << endl;
	}
	~Tree()
	{
		cout << "TDestructor:" << tab << this << endl;
		clear(Root); 
	}
	Node* getRoot()const
	{
		return Root;
	}

	void insert(int Data)
	{
		insert(Data, Root);
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
	int sum()const
	{
		return sum(Root);
	}
	double avarage()
	{
		return (double)sum(Root) / count(Root);
	}
	void print()const
	{
		print(Root);
		cout << endl;
	}
private:
	void insert(int Data, Node* Root)
	{
		if (this->Root == nullptr)
		{
			this->Root = new Node(Data);
			return;
		}
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Node(Data);
			else insert(Data, Root->pLeft);
		}
		else if (Data > Root->Data)
		{
			if (Root->pRight) insert(Data, Root->pRight);
			else Root->pRight = new Node(Data);
		}
	}
	int minValue(Node* Root)const
	{
		/*if (Root->pLeft == nullptr)return Root->Data;
		else return minValue(Root->pLeft);*/
		Root->pLeft ? minValue(Root->pLeft) : Root->Data;
	}
	int maxValue(Node* Root)const
	{
		Root->pRight ? maxValue(Root->pRight) : Root->Data;
	}
	int count(Node* Root)const
	{
		if (Root == nullptr)return 0;
		else return count(Root->pLeft) + count(Root->pRight) + 1;
	}
	int sum(Node* Root)const
	{
		return !Root ? 0 :  sum(Root->pLeft) + sum(Root->pRight) + Root->Data;
	}
	void print(Node* Root)const
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		cout << Root->Data << tab;
		print(Root->pRight);
	}
	void clear(Node* Root)
	{
		if (Root == nullptr)return;
		clear(Root->pLeft);
		clear(Root->pRight);
		delete Root;
	}
};

void main()
{
	setlocale(LC_ALL, "ru");

	Tree tree;
	int n = 0;
	cout << "Введите количество элементов:" << tab; cin >> n;
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand()%100);
	}
	cout << "Максимальный элемент в дереве: " << tab << tree.maxValue() << endl;
	cout << "Минимальный элемент в дереве: " << tab << tree.minValue() << endl;
	cout << "Количество элементов в дереве: " << tab << tree.count() << endl;
	cout << "Сумма элементов в дереве: " << tab << tree.sum() << endl;
	cout << "Среднее арифметическое элементов в дереве: " << tab << tree.avarage() << endl;
}