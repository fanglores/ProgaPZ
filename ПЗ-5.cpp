#include <iostream>
#include <ctime>
using namespace std;

struct point
{
	int x, y;
};

int n = 2;

void add(point* p)
{
	int x, y;

	if (n >= 10)
	{
		cout << "Fatal error. Array is full.";
		return;
	}

	cout << "\nEnter \"x y\"\n>>";
	cin >> x >> y;

	p[n] = { x, y };
	n++;
}

void remove_k(point* p)
{
	int k;

	cout << "\nEnter key\n>>";
	cin >> k;

	if (k < 0 || k > 9)
	{
		cout << "Fatal read error. Try again";
		return;
	}

	for (int i = k; i < n; i++) p[i] = p[i + 1];
	n--;
}

void remove_v(point* p)
{
	int x, y, k;

	cout << "\nEnter \"x y\"\n>>";
	cin >> x >> y;

	for (k = 0; k < n; k++) if (p[k].x == x && p[k].y == y) break;

	if (k == n) 
	{
		cout << "Fatal error. Element not found";
		return;
	}

	for (int i = k; i < n; i++) p[i] = p[i + 1];
	n--;
}

void write(point* p)
{
	if (n >= 10)
	{
		cout << "Fatal error. Array is full.";
		return;
	}

	p[n] = { rand() % 100, rand() % 100 };
	n++;
}

void edit(point* p)
{
	int k, x, y;

	cout << "\nEnter key\n>>";
	cin >> k;

	if (k < 0 || k > 9)
	{
		cout << "Fatal read error. Try again";
		return;
	}
	
	cout << "\nEnter \"x y\"\n>>";
	cin >> x >> y;

	p[k] = { x, y };
}

void print(point *p)
{
	for (int i = 0; i < n; i++) cout << (p + i)->x << " " << (p + i)->y << endl;
}


int main()
{
	srand(time(0));
	point p_array[10];
	int ans;

	p_array[0] = { rand() % 100, rand() % 100 };
	p_array[1] = { rand() % 100, rand() % 100 };

	while (true)
	{
		system("cls");
		cout << "1 - Add new element\n2 - Write new random element\n3 - Remove element by key\n4 - Remove element by value\n5 - Edit element by key\n6 - Print list\n0 - Exit\n\n>>";
		cin >> ans;

		switch (ans)
		{
			case 0: return 0;
			case 1: add(p_array); break;
			case 2: write(p_array); break;
			case 3: remove_k(p_array); break;
			case 4: remove_v(p_array); break;
			case 5: edit(p_array); break;
			case 6: print(p_array); break;
			default: cout << "Fatal read error. Try again\n";
		}

		system("pause");
	}





}