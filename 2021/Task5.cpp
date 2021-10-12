#include <iostream>
using namespace std;

template <class T>
struct Unit		//а ты просто хранишь дату
{
	T data;
	Unit<T>* prev = nullptr;
	Unit<T>* next = nullptr;
	int calls = 0;
};

template <class T>
class List		//ты двунаправленный
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
	{}

	T get(int)
	{}

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

	void sort()
	{}
};


int main()
{
	List<int>* DataList = new List<int>();
	DataList->push_back(1);
	DataList->push_back(2);
	DataList->push_back(3);
	DataList->print();
}
