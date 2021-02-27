#include <iostream>
#include <cmath>
using namespace std;

int digits(int x)
{
	int n = 0;

	x = abs(x);

	while (x > 0)
	{
		x /= 10;
		n++;
	}

	return n;
}

int rotate(int x)
{
	int y = 0;
	x = abs(x);

	while (x > 0)
	{
		y *= 10;
		y += x % 10;

		x /= 10;
	}

	return y;
}

bool check(int &i, int x)
{
	x = abs(x);
	x /= 10;

	while (x > 0)
	{
		if (x % 10 != 0) return  true;
		x = x / 10;
	}

	i = -1;
	return false;
}

int main()
{
	int x, d;

	cin >> x;

	cout << x << " = ";
	if (x == 0) cout << 0;

	int i = digits(x);
	x = (x < 0 ? -1 : 1) * rotate(x);

	for (; i > 0; i--)
	{
		d = x % 10;

		if (d != 0)
		{
			cout << "10^" << i - 1 << " *" << d;
			if (i != 1 && check(i, x)) cout << " + ";
		}

		x /= 10;
	}

	cout << ";" << endl;
}