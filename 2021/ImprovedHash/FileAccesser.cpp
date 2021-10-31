#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <direct.h>
#include <time.h>
using namespace std;

const int ALPHABET_POWER = 62;

int LENGTH;
long long unsigned int NUMBER_OF_STRINGS;

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

void generate_files(string dir_path, int len)
{
	LENGTH = len;
	NUMBER_OF_STRINGS = pow(ALPHABET_POWER, LENGTH);

	dir_path += "hashdir";

	if (!IsPathExist(dir_path))
		if(_mkdir(dir_path.c_str()) != 0) throw exception("Error while creating main directory");

	char* buf = new char[len];
	for (int i = 0; i < len; i++) buf[i] = '0';

	char* ibuf = new char[4];
	int hash;

	int cnt = 0;
	int file_cnt = 0;
	
	string path = dir_path + "\\test_" + to_string(len);

	if (!IsPathExist(path))
		if (_mkdir(path.c_str()) != 0) throw exception("Error while creating sub directory");

	path += "\\file";

	fstream gen_file(path + to_string(file_cnt) + ".bin", ios::out | ios::binary);

	while (buf[len - 1] <= 'z')
	{
		if (cnt == STRINGS_PER_FILE)
		{
			cnt = 0;
			file_cnt++;
			gen_file.close();
			gen_file = fstream(path + to_string(file_cnt) + ".bin", ios::out | ios::binary);
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

void print_time()
{
	auto tstmp = time(NULL);
	auto tm = localtime(&tstmp);
	cout << tm->tm_hour << ':' << tm->tm_min << ':' << tm->tm_sec << ": ";
}

clock_t compare_hash(string dir_path, int len)
{
	LENGTH = len;
	NUMBER_OF_STRINGS = pow(ALPHABET_POWER, LENGTH);

	int collisions = 0;
	string path = dir_path + "\\hashdir\\test_" + to_string(len);

	if (!IsPathExist(path))
		throw exception("Directory not found");

	path += "\\file";

	int max_file = 0;
	while (IsPathExist(path + to_string(max_file + 1) + ".bin")) max_file++;

	char* buf = new char[len]; char* t_buf = new char[len];
	char* ibuf = new char[4]; char* t_ibuf = new char[4];
	int hs, t_hs;

	print_time();
	cout << "Init successful! Staring comparison for " << len << "-symbols..." << endl;
	
	auto t_st = clock();

	//for each file
	for (int i = 0; i <= max_file; i++)			
	{
		fstream f_file(path + to_string(i) + ".bin", ios::in | ios::binary);
		int tmp = ((i == max_file) ? (NUMBER_OF_STRINGS) : (STRINGS_PER_FILE));

		//compare inside first taken file
		for (int j = 0; j < tmp; j++)		
		{
			f_file.seekg((len + 4) * j, f_file.beg);

			f_file.read(buf, len);
			f_file.read(ibuf, 4);
			memcpy(&hs, ibuf, 4);

			for (int j1 = j + 1; j1 < tmp; j1++)
			{
				f_file.seekg((len + 4) * j1, f_file.beg);

				f_file.read(t_buf, len);
				f_file.read(t_ibuf, 4);
				memcpy(&t_hs, t_ibuf, 4);

				if (hs == t_hs)
				{
					/*
					//debug collision check
					for (int g = 0; g < len; g++) cout << buf[g];
					cout << ' ' << hs << " & ";
					for (int g = 0; g < len; g++) cout << t_buf[g];
					cout << ' ' << t_hs << endl << endl;
					*/
					collisions++;
				}
			}
		}
		
		print_time();
		cout << "first iteration for file" << i << " completed" << endl;

		//for each next file
		for (int i1 = i + 1; i1 <= max_file; i1++)
		{
			fstream s_file(path + to_string(i1) + ".bin", ios::in | ios::binary);
			int tmp1 = ((i1 == max_file) ? (NUMBER_OF_STRINGS) : (STRINGS_PER_FILE));

			f_file.seekg(0, f_file.beg);

			//compare each str in file
			for (int j = 0; j < tmp; j++)		
			{
				f_file.read(buf, len);
				f_file.read(ibuf, 4);
				memcpy(&hs, ibuf, 4);

				//with each str in file+1
				for (int j1 = 0; j1 < tmp1; j1++)
				{
					s_file.read(t_buf, len);
					s_file.read(t_ibuf, 4);
					memcpy(&t_hs, t_ibuf, 4);

					if (hs == t_hs) collisions++;
				}
			}

			print_time();
			cout << "second iteration for file" << i << " with file" << i1 << " completed" << endl;
			s_file.close();
		}

		print_time();
		cout << "file" << i << " processed..." << endl;

		f_file.close();
	}
	auto t_en = clock();

	cout << "\nFound collisions: " << collisions << endl;

	return (t_en - t_st);
}





void debug_read(string path, int len, int f = 0)
{
	LENGTH = len;
	NUMBER_OF_STRINGS = pow(ALPHABET_POWER, LENGTH);

	cout << "Reading file" << f << " from " << len << "-symbols. Press any key to confirm" << endl;
	cin.clear();
	cin.sync();
	getchar();

	path += "\\hashdir\\test_" + to_string(len) + "\\file" + to_string(f) + ".bin";

	fstream read_file(path, ios::in | ios::binary);

	char* buf = new char[len];
	char* ibuf = new char[4];
	int hs;

	for (int k = 0; k < STRINGS_PER_FILE && k < NUMBER_OF_STRINGS; k++)
	{
		read_file.read(buf,  len);
		read_file.read(ibuf, 4);
		memcpy(&hs, ibuf, 4);

		for (int i = 0; i < len; i++) cout << buf[i];
		cout << ' ' << hs << endl;
	}

	read_file.close();
}