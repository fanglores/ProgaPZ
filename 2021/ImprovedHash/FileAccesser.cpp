#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <direct.h>
using namespace std;

extern const int LENGTH;
extern const int ALPHABET_POWER;
extern const long long unsigned int NUMBER_OF_STRINGS;

//for 1GB file
const int STRINGS_PER_FILE = 119304647;

bool IsPathExist(const string& s)
{
	struct stat buffer;
	return (stat(s.c_str(), &buffer) == 0);
}

const int k = 31, mod = 1000000007;
int encrypt(const char* str)
{
	int hash = 0;
	for (int i = 0; i < LENGTH; i++)
		hash = (hash * k + str[i]) % mod;

	return hash;
}

void generate_files(string dir_path, int len = LENGTH)
{
	if (!IsPathExist(dir_path))
	{
		if(_mkdir(dir_path.c_str()) != 0) throw exception("Error while creating directory");
		//create dir hashdir
	}

	char* buf = new char[len];
	for (int i = 0; i < len; i++) buf[i] = '0';

	char* ibuf = new char[4];
	int hash;

	int cnt = 0;
	char file_cnt = '0';
	
	string path = dir_path + "hashdir\\test_";
	path.push_back(static_cast<char>('0' + len));

	if (!IsPathExist(path))
	{
		if (_mkdir(path.c_str()) != 0) throw exception("Error while creating directory");
		//create dir test_x
	}

	path += "\\file";

	fstream gen_file(path + file_cnt + ".bin", ios::out | ios::binary);

	while (buf[len - 1] <= 'z')
	{
		if (cnt == STRINGS_PER_FILE)
		{
			cnt = 0;
			file_cnt++;
			gen_file.close();
			gen_file = fstream(path + file_cnt + ".bin", ios::out | ios::binary);
		}

		gen_file.write(buf, len);

		hash = encrypt(buf);
		memcpy(ibuf, &hash, 4);
		gen_file.write(ibuf, 4);

		cnt++;
		buf[0]++;

		for (int i = 0; i < len; i++)
		{
				 if (buf[i] == '9' + 1)	 buf[i] = 'A';
			else if (buf[i] == 'Z' + 1)  buf[i] = 'a';
			else if (buf[i] == 'z' + 1 && i != len - 1)
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