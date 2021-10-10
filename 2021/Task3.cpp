#include <string>
#include <iostream>
using namespace std;

const int DIV = 'z' - 'a' + 1;
const int L = 3; //lenght of string [3..6]
const unsigned long long int N = pow(DIV, L); //number of strings

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

unsigned long long int pow(int x, int a)
{
	unsigned long long int pw = 1;
	for (int i = 0; i < a; i++) pw *= x;

	return pw;
}

void print(Str* arr)
{
	cout << endl << string(70, '=') << endl;
	for (int i = 0; i < N; i++)
	{
		cout << arr[i].uid << ' ' << arr[i].s << endl;
		getchar();
	}

	cout << string(70, '=') << endl;
}

void generator(Str* arr)
{
	typedef unsigned long long int ulli;

	ulli dir = N / DIV; //number of character in a row
	ulli dim = 1;		//number of char groups
	for (int i = 0; i < L; i++)		//for every string character
	{
		cout << "~~~DEBUG~~~\t" << i << " char init" << endl;
		for(int g = 0; g < dim; g++)				//for each character group
			for (int j = 0; j < DIV; j++)			//for every letter in alphabet
				for (ulli k = 0; k < dir; k++)		//for every chunk of strings (chunk == dir)
				{
					arr[dir * (j + DIV * g) + k].s.push_back('a' + j);
				}

		dir /= DIV;
		dim *= DIV;
	}

	cout << "~~~DEBUG~~~\tGenerated " << N << " strings" << endl << endl;
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
	cout << "Hash compare end with " << hmatch << " hash matches (" << match << " confirmed). Elapsed time " << (double)(te - ts)/CLOCKS_PER_SEC << endl;
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
	cout << "String compare end " << match << " matches. Elapsed time " << (double)(te - ts) / CLOCKS_PER_SEC << endl;
}

int main()
{
	Str* smas = new Str[N];
	
	generator(smas);
	//print(smas);
	
	for (int i = 0; i < N; i++) smas[i].encrypt();

	h_cmp(smas);
	cout << endl << endl;
	s_cmp(smas);
	
}
