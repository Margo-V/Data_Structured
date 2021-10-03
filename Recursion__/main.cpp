#include <iostream>
using namespace std;


void elevator(int level)
{
	if (level == 0)return;
	//cout << level << endl;
	elevator(level - 1);	//Рекурсивный вызов 
	cout << level << endl;
}
//#define FACTORIAL
//#define FACTORIAL_2
//#define POWER
//#define POWER_2

#ifdef FACTORIAL
int factorial(int number, int result = 1)
{

	if (/*number == 1 || */number == 0)
	{
		return result;
	}
	else
	{
		factorial(number - 1, result *= number);
	}
}
#endif // FACTORIAL

#ifdef POWER
int power(int number, int pow)
{
	if (pow == 0)return 1;

	if (pow == 1)
	{
		return number;
	}
	else
	{
		result
			return  power(number, pow - 1);
	}

	//return pow == 1 ? number : power(number * number, pow - 1);
}
#endif // POWER

#ifdef FACTORIAL_2
int factorial(int n)
{
	/*if (n == 0)return 1;
	return n * factorial(n - 1);*/

	return n == 0 ? 1 : n * factorial(n - 1);
}
#endif // FACTORIAL_2

#ifdef POWER_2
double power(double a, int n)
{
	//if (n == 0)return 1;
	/*if (n > 0)return  a * power(a, n - 1);
	else return 1 / a * power(a, n + 1);*/
	return n == 0 ? 1 : n > 0 ? a * power(a, n - 1) : 1 / a * power(a, n + 1);
}
#endif // POWER_2


void main()
{
	setlocale(LC_ALL, "rus");
	//cout << "Hello world!" << endl;
	//main();	//Рекурсивный вызов функции main()
	//cout << "Введите номер этажа: "; cin >> n;
	//elevator(n);
#ifdef FACTORIAL
	//int n, m;
	cout << "Введите число: "; cin >> n;
	cout << factorial(n);
	//cout << "Введите число: "; cin >> n;
	//cout << "Введите степень числа: "; cin >> m;
	//cout << power(n, m);
#endif // FACTORIAL

#ifdef FACTORIAL_2
	cout << "Введите число для ввычисления факториала: "; cin >> n;
	cout << factorial(n) << endl;
#endif // FACTORIAL_2

#ifdef POWER_2
	int a; //Основание степени
	int n; //Показатель степени
	cout << "Введите основание степени: "; cin >> a;
	cout << "Введите показатель степени: "; cin >> n;
	cout << power(a, n) << endl;

	main();
#endif // POWER_2



}