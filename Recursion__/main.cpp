#include <iostream>
using namespace std;


void elevator(int level)
{
	if (level == 0)return;
	//cout << level << endl;
	elevator(level - 1);	//–екурсивный вызов 
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
	//main();	//–екурсивный вызов функции main()
	int n;
	//cout << "¬ведите номер этажа: "; cin >> n;
	//elevator(n);
	cout << "¬ведите число: "; cin >> n;
	cout << factorial(n);
}