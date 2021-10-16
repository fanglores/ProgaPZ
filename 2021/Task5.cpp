#include <iostream>
using namespace std;

template <class T>
struct Unit
{
	int uid;
	T data;

	Unit<T>* prev = nullptr;
	Unit<T>* next = nullptr;

	int calls = 0;

	Unit() = delete;

	Unit(int id)
	{
		uid = id;
	}
};

template <class T>
class List
{
private:
	int size = 0;
	Unit<T>* head;

public:

	List() 
	{
		head = new Unit<T>(size);
	}

	~List()
	{
		delete[] head;
	}

	void set(int id, T val)
	{
		Unit<T>* cur = head;
		while (cur->uid != id && cur->next != nullptr)
			cur = cur->next;

		if (cur->uid == id)
		{
			cur->calls++;
			cur->data = val;

			sort(cur);
		}
		else
		{
			cout << "Setter error:";
			cout << "No matching records were found" << endl;
		}
	}

	T get(int id)
	{
		Unit<T>* cur = head;
		while (cur->uid != id && cur->next != nullptr) 
			cur = cur->next;
		
		if (cur->uid == id)
		{
			cur->calls++;
			sort(cur);
			return cur->data;
		}
		else
		{
			cout << "Getter error:";
			cout << "No matching records were found. Returned first element." << endl;
			return head->data;
		}


	}

	void push_new(Unit<T>* item)
	{
		size++;
		(item->next) = new Unit<T>(size);
		(item->next)->prev = item;
	}

	void push_back(T val)
	{
		Unit<T>* cur = head;
		while (cur->next != nullptr) cur = cur->next;
		
		push_new(cur);
		cur->data = val;
	}

	void print()
	{
		Unit<T>* cur = head;
		while (cur->next != nullptr)
		{
			cout << cur->uid << ' ';
			cout << cur->data << endl;
			cur = cur->next;
		}
	}

	void unit_swap(Unit<T>* u1, Unit<T>* u2)
	{
		T pdata = u1->data;
		int id = u1->uid;
		int cls = u1->calls;

		u1->data = u2->data;
		u1->uid = u2->uid;
		u1->calls = u2->calls;

		u2->data = pdata;
		u2->uid = id;
		u2->calls = cls;
	}



	void sort(Unit<T>* cur)
	{
		while (cur->prev != nullptr)
		{
			if (cur->prev->calls < cur->calls)
				unit_swap(cur->prev, cur);
			else break;

			cur = cur->prev;
		}
	}
};


int main()
{
	List<int>* DataList = new List<int>();

	DataList->push_back(0);
	DataList->push_back(1);
	DataList->push_back(2);
	DataList->push_back(3);
	DataList->push_back(4);
	DataList->push_back(5);
	DataList->push_back(6);
	DataList->push_back(7);
	DataList->push_back(8);
	DataList->push_back(9);

	DataList->get(9);
	DataList->get(9);
	DataList->get(9);

	DataList->get(5);
	DataList->get(5);

	DataList->get(0);

	DataList->print();
}
