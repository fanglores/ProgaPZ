#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
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


void dfs(int v, vector<vector<int>>& m)
{
	vector<bool> used(m.size(), false);
	stack<int> q;

	while (v != -1)
	{
		if (used[v] == false)
		{
			used[v] = true;

			for (int i = 0; i < m.size(); i++)
				if (m[v][i] == 1 && used[i] == false) q.push(i);
		}

		if (q.size() > 0)
		{
			v = q.top();
			q.pop();
		}
		else v = -1;
	}

	//print row of attainability
	for (bool a : used) cout << a << ' ';
	cout << endl;
}
		
void stack_func()
{
	int N;
	cin >> N;

	vector<vector<int>> matrix(N, vector<int>(N, 0));

	int x;
	for (int i = 0; i < N; i++)
	{
		do
		{
			cin >> x;
			if (x != 0) matrix[i][x - 1] = 1;

		} while (cin.peek() != '\n');
	}

	/*
	//debug matrix output
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << matrix[i][j] << ' ';
		cout << endl;
	}
	cout << endl << endl;
	*/

	for (int i = 0; i < N; i++) dfs(i, matrix);
}

int main()
{
	//map_func();
	//vector_func();
	stack_func();
}
