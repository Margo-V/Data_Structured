#include <iostream>
using namespace std;


void elevator(int level)
{
	if (level == 0)return;
	//cout << level << endl;
	elevator(level - 1);	//Рекурсивный вызов 
	cout << level << endl;
}
void main()
{
	setlocale(LC_ALL, "rus");
	//cout << "Hello world!" << endl;
	//main();	//Рекурсивный вызов функции main()
	int n;
	cout << "Введите номер этажа: "; cin >> n;
	elevator(n);
}