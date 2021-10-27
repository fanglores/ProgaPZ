#pragma once
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

bool IsPathExist(const string& path_to_check);

const int k = 31, mod = 1000000007;
int encrypt(const char*);

void generate_files(string dir_path, int length = LENGTH);

void compare_hash();

void debug_read(int len, int file_n = 0);