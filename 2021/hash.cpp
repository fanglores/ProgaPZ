#include <string>
#include <iostream>
using namespace std;

const int n = 100000; //number of strings
const int l = 2; //lenght of string
const bool OUT = !((n > 10) || (l > 10));

int cid = 0;

class Str
{
private:
	const int k = 31, mod = 1e9 + 7;

public:
	int uid;
	string s;
	int hash;
	
	Str()
	{
		uid = cid;
		cid++;
		s = "";
		hash = 0;
	}

	void encrypt()
	{
		int x;
		for (char c : s) 
		{
			x = (int)(c - 'a' + 1);
			hash = (hash * k + x) % mod;
		}
	}
};

void randomizer(Str* arr)
{
	srand(time(NULL));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < l; j++)
			arr[i].s.push_back(static_cast<char>('a' + rand() % ('z' - 'a' + 1)));
}

void h_cmp(Str* arr)
{
	cout << "Hash compare start:" << endl;
	int match = 0;
	auto ts = clock();

	for (int i = 1; i < n; i++)
		if (arr[0].hash == arr[i].hash)
		{
			if (OUT) cout << arr[0].uid << " equals to " << arr[i].uid << endl;
			match++;
		}
	
	auto te = clock();
	cout << "Hash compare end with " << match << " matches. Elapsed time " << te - ts << endl;
}

void s_cmp(Str* arr)
{
	cout << "String compare start:" << endl;
	int match = 0;
	auto ts = clock();

	for (int i = 1; i < n; i++)
		if (arr[0].s == arr[i].s)
		{
			if (OUT) cout << arr[0].uid << " equals to " << arr[i].uid << endl;
			match++;
		}

	auto te = clock();
	cout << "String compare end " << match << " matches. Elapsed time " << te - ts << endl;
}

int main()
{
	Str* smas= new Str[n];
	randomizer(smas);

	if (OUT)
	{
		cout << "Generated strings: " << endl;
		for (int i = 0; i < n; i++)
		{
			cout << smas[i].s << endl;
		}
		cout << endl << endl;
	}

	for (int i = 0; i < n; i++) smas[i].encrypt();

	h_cmp(smas);
	cout << endl << endl;
	s_cmp(smas);
}
