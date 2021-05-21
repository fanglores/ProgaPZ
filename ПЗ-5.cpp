#include <iostream>
#include <ctime>
using namespace std;

struct point
{
	int x, y;
	point* next = NULL;
};

//searches end of array
point* search(point* base, bool step = false)
{
	if (step) return base->next;

	if (base->next == NULL) return base;
	else search(base->next);
}

//user adds one element
void add(point* bp)
{
	int x, y;
	point* cp = search(bp);

	cout << "\nEnter \"x y\"\n>>";
	cin >> x >> y;

	cp->next = new point;
	cp->x = x;
	cp->y = y;
}

//writes one random element
void write(point* bp)
{
	point* cp = search(bp);

	cp->next = new point;
	cp->x = rand() % 100;
	cp->y = rand() % 100;
}

//removes one element by key, using shifting all array (instead of rewriting b_ptr)
void remove_k(point* bp)
{
	int k;

	cout << "\nEnter key\n>>";
	cin >> k;

	point* cp = bp;
	for (int i = 0; i < k && cp->next != NULL; i++) cp = cp->next;

	if (cp->next == NULL)
	{
		cout << "Segmentation fault. It seems like we tried to access data beyond the array" << endl;
		return;
	}

	while (cp->next->next != NULL)
	{
		cp->x = cp->next->x;
		cp->y = cp->next->y;
		cp = cp->next;
	}

	cp->x = cp->next->x;
	cp->y = cp->next->y;
	delete cp->next->next;
	cp->next = NULL;
}

//removes one element as one as was entered
void remove_v(point* bp)
{
	point* cp = bp;
	int x, y;
	bool flag = false;

	cout << "\nEnter \"x y\"\n>>";
	cin >> x >> y;

	while (cp->next != NULL && !flag)
	{
		if (cp->x == x && cp->y == y)
		{
			flag = true;

			while (cp->next->next != NULL)
			{
				cp->x = cp->next->x;
				cp->y = cp->next->y;
				cp = cp->next;
			}

			cp->x = cp->next->x;
			cp->y = cp->next->y;
			delete cp->next->next;
			cp->next = NULL;
		}

		cp = cp->next;
	}

	if (!flag) cout << "No elements were found";

}

//edits one element by key
void edit(point* bp)
{
	int k, x, y;

	cout << "\nEnter key\n>>";
	cin >> k;

	cout << "\nEnter \"x y\"\n>>";
	cin >> x >> y;

	point* cp = bp;
	for (int i = 0; i < k && cp->next != NULL; i++) cp = cp->next;

	if (cp->next == NULL)
	{
		cout << "Segmentation fault. It seems like we tried to access data beyond the array" << endl;
		return;
	}

	cp->x = x;
	cp->y = y;
}

//prints all data in array
void print(point* bp)
{
	point* cp = bp;
	while (cp->next != NULL)
	{
		cout << cp->x << " " << cp->y << endl;
		cp = search(cp, 1);
	}
}

int main()
{
	srand(time(0));
	int ans;
	point* b_ptr = new point;

	while (true)
	{
		system("cls");
		cout << "1 - Add new element\n2 - Write new random element\n3 - Remove element by key\n4 - Remove element by value\n5 - Edit element by key\n6 - Print list\n0 - Exit\n\n>>";
		cin >> ans;

		switch (ans)
		{
		case 0: return 0;
		case 1: add(b_ptr); break;
		case 2: write(b_ptr); break;
		case 3: remove_k(b_ptr); break;
		case 4: remove_v(b_ptr); break;
		case 5: edit(b_ptr); break;
		case 6: print(b_ptr); break;
		default: cout << "Fatal read error. Try again\n";
		}

		system("pause");
	}
}