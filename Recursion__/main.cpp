#include <iostream>
using namespace std;


void elevator(int level)
{
	if (level == 0)return;
	//cout << level << endl;
	elevator(level - 1);	//����������� ����� 
	cout << level << endl;
}

int factorial(int number, int result =1)
{
	
	if (number == 1 || number == 0)
	{
		return result;
	}
	else
	{
		factorial(number - 1, result *= number);
	}
}

void main()
{
	setlocale(LC_ALL, "rus");
	//cout << "Hello world!" << endl;
	//main();	//����������� ����� ������� main()
	int n;
	//cout << "������� ����� �����: "; cin >> n;
	//elevator(n);
	cout << "������� �����: "; cin >> n;
	cout << factorial(n);
}