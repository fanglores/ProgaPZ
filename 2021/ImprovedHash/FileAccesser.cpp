#include <iostream>
#include <fstream>
#include <string>
using namespace std;

extern const int LENGTH;
extern const int ALPHABET_POWER;
extern const long long unsigned int NUMBER_OF_STRINGS;

//for 1GB file
const int STRINGS_PER_FILE = 119304647;

/*
void generate_files_bits()
{
	int* mas = new int[LENGTH];
	unsigned long long int cnt = 0;
	short unsigned int file_cnt = 0;

	string path = "d:\\hashdir\\test_";
	path.push_back(static_cast<char>('0' + LENGTH));
	path += "\\file0.bin";

	fstream gen_file(path);
	delete& path;

	while (mas[LENGTH - 1] != ALPHABET_POWER - 1)
	{
		if (cnt % STRINGS_PER_FILE == 0)
		{
			file_cnt++;
			string path = "d:\\hashdir\\test_";
			path.push_back(static_cast<char>('0' + LENGTH));
			path += "\\file";
			path.push_back(file_cnt);
			path += ".bin";

			gen_file = fstream(path);
			delete& path;
		}

		//parse bitset to *char
		//currently is unavailable
		//gen_file.write();

		cnt++;
		mas[0]++;

		for (int i = 0; i < LENGTH - 1; i--)
		{
			if (mas[i] == ALPHABET_POWER)
			{
				mas[i] = 0;
				mas[i + 1]++;
			}
			else break;
		}
	}

}
*/

const int k = 31, mod = 1000000007;
int encrypt(const char* str)
{
	int hash = 0;
	for (int i = 0; i < LENGTH; i++)
		hash = (hash * k + str[i]) % mod;

	return hash;
}

void generate_files()
{
	char* buf = new char[LENGTH];
	for (int i = 0; i < LENGTH; i++) buf[i] = '0';

	char* ibuf = new char[4];
	int hash;

	int cnt = 0;
	char file_cnt = '0';
	
	string path = "d:\\hashdir\\test_";
	path.push_back(static_cast<char>('0' + LENGTH));
	path += "\\file";

	fstream gen_file(path + file_cnt + ".bin", ios::out | ios::binary);

	while (buf[LENGTH - 1] <= 'z')
	{
		if (cnt == STRINGS_PER_FILE)
		{
			cnt = 0;
			file_cnt++;
			gen_file.close();
			gen_file = fstream(path + file_cnt + ".bin", ios::out | ios::binary);
		}

		gen_file.write(buf, LENGTH);

		hash = encrypt(buf);
		memcpy(ibuf, &hash, 4);
		gen_file.write(ibuf, 4);

		cnt++;
		buf[0]++;

		for (int i = 0; i < LENGTH; i++)
		{
				 if (buf[i] == '9' + 1)	 buf[i] = 'A';
			else if (buf[i] == 'Z' + 1)  buf[i] = 'a';
			else if (buf[i] == 'z' + 1 && i != LENGTH - 1)
			{
				buf[i] = '0';
				buf[i + 1]++;
			}
			else break;
		}
	}

	gen_file.close();
	delete[] buf;
}

void debug_read(int l, int f = 0)
{
	cout << "Reading file" << f << " from " << l << "-symbols. Press any key to confirm" << endl;
	getchar();

	string path = "d:\\hashdir\\test_";
	path.push_back(static_cast<char>('0' + l));
	path += "\\file";

	fstream read_file(path + static_cast<char>('0' + f) + ".bin", ios::in | ios::binary);

	char* buf = new char[l];
	char* ibuf = new char[4];
	int hs;

	for (int k = 0; k < STRINGS_PER_FILE && k < NUMBER_OF_STRINGS; k++)
	{
		read_file.read(buf,  l);
		read_file.read(ibuf, 4);
		memcpy(&hs, ibuf, 4);

		for (int i = 0; i < l; i++) cout << buf[i];
		cout << ' ' << hs << endl;
		//getchar();
	}

	read_file.close();
}