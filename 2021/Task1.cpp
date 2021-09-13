#include <iostream>
using namespace std;

class ArrayClass
{
private:
	int* p;
	int size;

public:
	ArrayClass(int);
	ArrayClass(const ArrayClass&);
	void print();
	~ArrayClass();
	void set(int, int);
	int get(int);
	void push_back(int);
	friend ArrayClass operator + (ArrayClass, ArrayClass);
	friend ArrayClass operator - (ArrayClass, ArrayClass);
};

ArrayClass::ArrayClass(int size)
{
	this->size = size;
	p = new int[size];
}

ArrayClass::ArrayClass(const ArrayClass& ac)
{
	size = ac.size;
	p = new int[size];

	for (int i = 0; i < size; i++)
	{
		p[i] = ac.p[i];
	}
}

ArrayClass::~ArrayClass()
{
	delete[] p;
}

void ArrayClass::print()
{
	for (int i = 0; i < size; i++) cout << p[i] << " ";
	cout << endl;
}

void ArrayClass::push_back(int val)
{
	int* new_mas = new int[size + 1];
	memcpy(new_mas, p, size*sizeof(int));
	new_mas[size] = val;

	size++;
	p = new_mas;
}

void ArrayClass::set(int pos, int val)
{
	if (pos < 0 || pos >= size)
	{
		cout << "Setter error. Array out of bounds" << endl;
		return;
	}
	else if (val < -100 || val > 100)
	{
		cout << "Setter error. Value out of range" << endl;
		return;
	}
	else p[pos] = val;
}

int ArrayClass::get(int pos)
{
	if (pos < 0 || pos >= size)
	{
		cout << "Getter error. Array out of bounds" << endl;
		return -1;
	}
	else return p[pos];
}

ArrayClass operator + (ArrayClass ac1, ArrayClass ac2)
{
	int min_size = ((ac1.size < ac2.size) ? ac1.size : ac2.size);
	ArrayClass out(min_size);
	for (int i = 0; i < min_size; i++) out.set(i, ac1.get(i) + ac2.get(i));
	
	return out;
}

ArrayClass operator - (ArrayClass ac1, ArrayClass ac2)
{
	int min_size = ((ac1.size < ac2.size) ? ac1.size : ac2.size);
	ArrayClass out(min_size);
	for (int i = 0; i < min_size; i++) out.set(i, ac1.get(i) - ac2.get(i));

	return out;
}

int main()
{
	ArrayClass ac1(3);
	for (int i = 0; i < 3; i++) ac1.set(i, i + 1);

	ArrayClass ac2(ac1);

	ac1.push_back(4);
	ac1.print();
	ac2.print();
	cout << "Push back works\n" << endl;
	ac1.set(1, 101); //Setter error
	ac1.set(101, 1); //Setter error
	ac1.get(101); //Getter error
	cout << "Get 3rd element: " << ac1.get(2) << "\n" << endl;
	ArrayClass ac3 = ac1 - ac2;
	ac3.print();
	ArrayClass ac4 = ac1 + ac2;
	ac4.print();
}
