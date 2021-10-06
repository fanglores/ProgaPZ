#include <string>
#include <map>
#include <iostream>
using namespace std;

void proc(string& str, map<string, int>& m)
{
	int ps, cs;
	ps = cs = 0;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			
			cs = i;

			string sub = str.substr(ps, cs - ps);
			if (m.find(sub) == m.end()) m.insert(make_pair(sub, 1));
			else m[sub]++;

			ps = cs + 1;
		}
	}

	cs = str.size();
	string sub = str.substr(ps, cs - ps);
	if (m.find(sub) == m.end()) m.insert(make_pair(sub, 1));
	else m[sub]++;

}

int main()
{
	map<string, int> dict;
	string s;

	getline(cin, s);

	proc(s, dict);

	cout << endl;
	for (pair<string, int> p : dict) cout << p.second << ' ' << p.first << endl;
}
