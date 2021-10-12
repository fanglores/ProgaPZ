#include <iostream>
using namespace std;

template <class T>
struct Unit
{
	T data;
	Unit<T>* prev = nullptr;
	Unit<T>* next = nullptr;
	int calls = 0;
};

template <class T>
class List
{
private:
	Unit<T>* head;

public:

	List() 
	{
		head = new Unit<T>;
	}

	List(Unit<T> &item)
	{
		head->prev = item->prev;
		head->next = item->next;
		head->data = item->data;
	}

	~List()
	{
		delete[] head;
	}

	void set(int, T)
	{
		//set algo
		sort();
	}

	T get(int)
	{
		//get algo
		sort();
	}

	void push_back(T val)
	{
		Unit<T>* cur = head;
		while (cur->next != nullptr) cur = cur->next;

		cur->next = new Unit<T>;
		cur->next->prev = cur;
		cur->data = val;
	}

	void print()
	{
		Unit<T>* cur = head;
		while (cur->next != nullptr)
		{
			cout << cur->data << endl;
			cur = cur->next;
		}
	}

	void unit_swap(Unit<T>& u1, Unit<T>& u2)
	{
		Unit<T>* pprev = u1->prev, pnext = u1->next;
		T pdata = u1->data;

		u1->prev = u2->prev;
		u1->next = u2->next;
		u1->data = u2->data;

		u2->prev = pprev;
		u2->next = pnext;
		u2->data = pdata;
	}

	void sort()
	{
		//sort algo
	}
};


int main()
{
	List<int>* DataList = new List<int>();

	DataList->push_back(1);
	DataList->push_back(2);
	DataList->push_back(3);

	DataList->print();
}
