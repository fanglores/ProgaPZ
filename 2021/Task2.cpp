#include <iostream>
using namespace std;

template <typename T>
class Array
{
private:
	T* p;
	int size;

public:
	Array(int size)
	{
		this->size = size;
		p = new T[size];
	}

	Array(const Array &arr)
	{
		size = arr.size;
		p = new T[size];

		for (int i = 0; i < size; i++) p[i] = arr.p[i];
	}

	void print()
	{
		for (int i = 0; i < size; i++) cout << p[i] << " ";
		cout << endl;
	}

	~Array()
	{
		delete[] p;
	}

	void set(int pos, T val)
	{
		if (pos < 0 || pos >= size)
			cout << "Setter error. Array out of bounds" << endl;
		else p[pos] = val;
	}

	int get(int pos)
	{
		if (pos < 0 || pos >= size)
		{
			cout << "Getter error. Array out of bounds" << endl;
			return -1;
		}
		else return p[pos];
	}

	void push_back(T val)
	{
		T* new_mas = new T[size + 1];
		memcpy(new_mas, p, size * sizeof(T));
		new_mas[size] = val;

		size++;
		p = new_mas;
	}

	double dist(Array& ar)
	{
		int sq = 0.0;
		for (int i = 0; i < size; i++) sq += (p[i] - ar.p[i]) * (p[i] - ar.p[i]);

		return sqrt(sq);
	}

	friend ostream& operator << (ostream& os, const Array &ar)
	{
		for (int i = 0; i < ar.size; i++) os << ar.p[i] << ' ';
		os << endl;

		return os;
	}

	Array& operator=(const Array& ar) 
	{
		if (this == &ar) return *this;
		
		size = ar.size;
		p = new T[size];
		for (int i = 0; i < size; i++) p[i] = ar.p[i];

		return *this;
	}
};

class ArrayClass
{
private:
	int* p;
	int size;

public:
	ArrayClass(int size)
	{
		this->size = size;
		p = new int[size];
	}

	ArrayClass(const ArrayClass& ac)
	{
		size = ac.size;
		p = new int[size];

		for (int i = 0; i < size; i++)
		{
			p[i] = ac.p[i];
		}
	}

	void print()
	{
		for (int i = 0; i < size; i++) cout << p[i] << " ";
		cout << endl;
	}

	~ArrayClass()
	{
		delete[] p;
	}

	void set(int pos, int val)
	{
		if (pos < 0 || pos >= size) throw out_of_range("Array out of bounds");
		if (val < -100 || val > 100) throw invalid_argument("Element out of range");
		
		p[pos] = val;
	}

	int get(int pos)
	{
		if (pos < 0 || pos >= size) throw out_of_range("Array out of bounds");
		
		return p[pos];
	}

	void push_back(int val)
	{
		int* new_mas = new int[size + 1];
		memcpy(new_mas, p, size * sizeof(int));
		new_mas[size] = val;

		size++;
		p = new_mas;
	}

	friend ArrayClass operator + (ArrayClass, ArrayClass);
	friend ArrayClass operator - (ArrayClass, ArrayClass);
};

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
	try
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
	catch (bad_alloc e)
	{
		cout << "Error while initiating array" << endl << e.what() << endl;
	}
	catch (out_of_range e)
	{
		cout << "Error while accessing array element" << endl << e.what() << endl;
	}
	catch (invalid_argument e)
	{
		cout << "Error while setting arguments" << endl << e.what() << endl;
	}
}
