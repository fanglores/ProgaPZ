#include <string>
#include <map>
#include <iostream>
using namespace std;

int main()
{
	map<string, int> dict;
	string s = "ab";

	while (cin >> s)
	{
		if (s == "/exit") break;
		dict[s]++;
	}

	cout << endl;
	for (pair<string, int> p : dict) cout << p.second << ' ' << p.first << endl;
}
