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

vector<bool> used;
void dfs(int v, vector<vector<int>> &m) 
{
	used[v] = true;
	for (auto i = m[v].begin(); i != m[v].end(); i++)
		if (i != 0 && !used[*i])
			dfs(*i, m);
}

void stack_func()
{
	int N;
	cin >> N;

	vector<vector<int>> matrix(N, vector<int>(N, 0));
	used.resize(N, false);

	int x;
	for (int i = 0; i < N; i++)
	{
		matrix[i][i] = 1;	//из вершины всегда можно попасть в неё саму

		do
		{
			cin >> x;
			if (x != 0) matrix[i][x - 1] = 1;

		} while (cin.peek() != '\n');
	}

	//debug matrix output
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << matrix[i][j] << ' ';
		cout << endl;
	}

	for (int i = 0; i < N; i++) dfs(i + 1, matrix);
	
	//debug matrix output
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << matrix[i][j] << ' ';
		cout << endl;
	}
}

int main()
{
	//map_func();
	//vector_func();
	stack_func();
}
