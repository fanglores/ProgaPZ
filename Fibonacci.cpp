#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int fib(int dir)
{
	static int a = 1;
	static int b = 1;

	a = a + b;
	b = a - b;
	a = a - b;

	if (dir > 0) b = a + b;
	else a = a - b;

	return b;
}

void parser(int num)
{
	while (fib(1) <= num);

	vector<int> set(0);
	while (num > 0)
	{
		int f = fib(-1);

		if (f <= num)
		{
			num -= f;
			set.push_back(1);
		}
		else set.push_back(0);
	}

	while (fib(-1) >= 1) set.push_back(0);
	//set.push_back(0);

	for (int i = set.size() - 1; i >= 0; i--) cout << set[i];

}

int main()
{
	int num;

	cout << "Enter a positive number: ";
	cin >> num;
	
	parser(num);
	cout << endl << "binary as 1 1 2 3 5 8 13...";
}
