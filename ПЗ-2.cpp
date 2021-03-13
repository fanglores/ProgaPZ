#include <iostream>
#include <cmath>
using namespace std;

int input(int b1)	//функция считывания числа с разделителем пробел
{
	char c;
	int num = 0;

	getchar();

	while (c = getchar())
	{
		if (c == ' ') break;
		num *= b1;
		if (c >= '0' && c <= '9')
			num += (c - '0');
		else num += (10 + c - 'A');
	}
	
	return num;
}

void processor(int num, int b2)		//функция преобразования числа
{
	int src = num;

	int t = 1;

	for (; num > t; t *= b2); 	//поиск наибольшей степени
	if (num < t) t /= b2;

	int c;
	while (t >= 1)
	{
		c = -1;
		while (num >= 0)
		{
			num -= t;
			c++;
		}

		src -= t * c;
		num = src;
		t /= b2;
		if (c < 10) cout << c;
		else cout << char('A' + c - 10);
	}
}

int main()
{
	int base1, base2;
	int num1;

	cin >> base1;

	if (base1 > 10) num1 = input(base1);
	else cin >> num1;

	cin >> base2;

	processor(num1, base2);
}
