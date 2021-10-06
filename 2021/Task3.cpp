#include <string>
#include <iostream>
using namespace std;

const int L = 2; //lenght of string [3..6]
const int N = pow('z' - 'a' + 1, L); //number of strings

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

void generator(Str* arr)
{
	//generator
	int div = 'z' - 'a' + 1;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < L; j++)
			arr[i].s[j] = i / pow(div, j);
	}
}

void h_cmp(Str* arr)
{
	cout << "Hash compare start:" << endl;
	int match = 0, hmatch = 0;
	auto ts = clock();

	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			if (arr[i].hash == arr[j].hash)
			{
				int g;
				hmatch++;

				for (g = 0; g < L; g++)
					if (arr[i].s[g] != arr[j].s[g]) break;
				if (g == L) match++;
			}
	
	auto te = clock();
	cout << "Hash compare end with " << hmatch << " hash matches (" << match << " confirmed). Elapsed time " << te - ts << endl;
}

void s_cmp(Str* arr)
{
	cout << "String compare start:" << endl;
	int match = 0;
	auto ts = clock();

	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			for (int g = 0; g < L; g++)
				if (arr[i].s[g] != arr[j].s[g]) break;

	auto te = clock();
	cout << "String compare end " << match << " matches. Elapsed time " << te - ts << endl;
}

int main()
{
	Str* smas = new Str[N];
	
	generator(smas);

	for (int i = 0; i < N; i++) smas[i].encrypt();

	h_cmp(smas);
	cout << endl << endl;
	s_cmp(smas);
}
