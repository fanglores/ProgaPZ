#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void map_func()
{
	map<string, int> dict;
	string s;

	while (cin >> s)
	{
		if (s == "/exit") break;
		dict[s]++;
	}

	cout << endl;
	for (pair<string, int> p : dict) cout << p.second << ' ' << p.first << endl;
}

void vector_func()
{
	srand(time(NULL));

	int n1, n2;
	cin >> n1 >> n2;

	map<int, int> num;
	vector<int> v1(n1), v2(n2);

	int sum1 = 0, sum2 = 0;

	cout << "First vector: ";
	for (int& a : v1)
	{
		a = rand() % 201 - 100;
		sum1 += a;
	
		cout << a << ' ';
	}

	cout << "\nSecond vector: ";
	for (int& a : v2)
	{
		a = rand() % 201 - 100;
		sum2 += a;

		if (find(v1.begin(), v1.end(), a) != v1.end()) num[a]++;
		cout << a << ' ';
	}

	cout << "\n\nAverage in first vector: " << (float)sum1 / n1;
	cout << "\nAverage in second vector: " << (float)sum2 / n2;

	cout << "\n\nMatching elements: ";
	for (pair<int, int> p : num)
		cout << p.first << ' ';
}

int main()
{
	//map_func();
	vector_func();

}
