#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

#define OUT (0)

clock_t p1, p2;

void print(vector<int> v)
{
	cout << "Elapsed time: " << double(p2 - p1) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
	if (OUT)
	{
		cout << "And now it is: ";
		for (auto i : v) cout << i << " ";
		cout << endl;
	}

}

//11s when N = 10^5
vector<int> bubbles(vector<int> v)
{
	cout << "\nHello, Mr. Bubbles!\n";
	p1 = clock();

	for (int i = 0; i < v.size() - 1; i++)
		for (int j = 0; j < v.size() - i - 1; j++)
			if (v[j] > v[j + 1]) swap(v[j], v[j + 1]);

	p2 = clock();
	return v;
}

//8s when N = 10^5
vector<int> cocktail(vector<int> v)
{
	cout << "\nHave a nice day!\n";
	bool swapped = true;
	int start = 0;
	int end = v.size() - 1;

	p1 = clock();

    while (swapped)
    {
        swapped = false;

        for (int i = start; i < end; ++i)
            if (v[i] > v[i + 1]) 
			{
                swap(v[i], v[i + 1]);
                swapped = true;
            }
       
        if (!swapped) break;
        swapped = false;
        --end;

        for (int i = end - 1; i >= start; --i)
            if (v[i] > v[i + 1]) 
			{
                swap(v[i], v[i + 1]);
                swapped = true;
            }

        ++start;
    }

	p2 = clock();
	return v;
}


int partition(vector<int> &vs, int low, int high)
{
	int pivot = vs[high]; 
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
		if (vs[j] < pivot)
		{
			i++;
			swap(vs[i], vs[j]);
		}
	
	swap(vs[i + 1], vs[high]);
	return (i + 1);
}

void block(vector<int>& v, int low, int high)
{
	if (low < high)
	{
		int pi = partition(v, low, high);

		block(v, low, pi - 1);
		block(v, pi + 1, high);
	}
}


//0,033s when N = 10^5!!!
vector<int> qsort(vector<int> v)
{
	cout << "\nGas Gas Gas, I`ll be so quick as a flash...\n";
	p1 = clock();

	block(v, 0, v.size() - 1);
	
	p2 = clock();
	return v;
}

int main()
{
	srand(time(0));

	int N;
	cin >> N;

	vector<int> vect(N);
	for (int i = 0; i < N; i++) vect[i] = rand() % 100;

	if (OUT)
	{
		cout << "\nIt was: ";
		for (auto i : vect) cout << i << " ";
		cout << endl;
	}

	print(bubbles(vect));

	print(cocktail(vect));

	print(qsort(vect));
	
}
