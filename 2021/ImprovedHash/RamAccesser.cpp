#include <string>
#include <fstream>
#include <iostream>
using namespace std;

const int STRINGS_PER_RAM = 119304647;
bool IsPathExist(const string& path_to_check);
void print_time();

struct unit
{
	char* str;
	int hash;
};

class ram_unit
{
private:
	int size;
	unit* cache;
	int l;

public:
	ram_unit() = delete;
	ram_unit(string path, int nos, int len)
	{
		l = len;
		size = nos;
		fstream f_file(path, ios::in | ios::binary);

		cache = new unit[size];

		char* ibuf = new char[4];

		for (int i = 0; i < size; i++)
		{
			cache[i].str = new char[len];

			f_file.read(cache[i].str, len);
			f_file.read(ibuf, 4);
			memcpy(&cache[i].hash, ibuf, 4);
		}

		f_file.close();
	}

	void compare_str()
	{
		int colls = 0;

		for (int i = 0; i < size; i++)
			for (int j = i + 1; j < size; j++)
				for (int k = 0; k < l; k++)
					if (cache[i].str[k] == cache[j].str[k]) colls++;
	}

	int compare()
	{
		int colls = 0;

		for (int i = 0; i < size; i++)
			for (int j = i + 1; j < size; j++)
				if (cache[i].hash == cache[j].hash) colls++;

		return colls;
	}

	~ram_unit()
	{
		delete[] cache;
	}

	friend int operator+ (const ram_unit& ru1, const ram_unit& ru2)
	{
		int colls = 0;

		for (int i = 0; i < ru1.size; i++)
			for (int j = 0; j < ru2.size; j++)
				if (ru1.cache[i].hash == ru2.cache[j].hash) colls++;
	
		return colls;
	}

	friend void operator* (const ram_unit& ru1, const ram_unit& ru2)
	{
		int colls = 0;

		for (int i = 0; i < ru1.size; i++)
			for (int j = 0; j < ru2.size; j++)
				for (int k = 0; k < ru1.l; k++)
					if (ru1.cache[i].str[k] == ru2.cache[j].str[k]) colls++;
	}
};


time_t hash_ram(string dir_path, int len)
{
	long long int NUMBER_OF_STRINGS = pow(62, len);
	long long int collisions = 0;
	string path = dir_path + "\\hashdir\\test_" + to_string(len);

	path = "d:\\hashdir\\test_" + to_string(len);			//!!!!!!!

	if (!IsPathExist(path))
		throw exception("Directory not found");

	path += "\\file";

	int max_file = 0;
	while (IsPathExist(path + to_string(max_file + 1) + ".bin")) max_file++;

	print_time();
	cout << "Init successful! Staring comparison for " << len << "-symbols..." << endl;

	auto t_st = clock();

	for (int i = 0; i <= max_file; i++)
	{
		int tmp = ((i == max_file) ? (NUMBER_OF_STRINGS % STRINGS_PER_RAM) : (STRINGS_PER_RAM));

		ram_unit rm(path + to_string(i) + ".bin", tmp, len);

		//compare with file self
		collisions += rm.compare();

		//compare with others
		for (int i1 = i + 1; i1 <= max_file; i1++)
		{
			int tmp1 = ((i1 == max_file) ? (NUMBER_OF_STRINGS % STRINGS_PER_RAM) : (STRINGS_PER_RAM));

			ram_unit rm1(path + to_string(i1) + ".bin", tmp1, len);

			collisions += (rm + rm1);
		}

		print_time();
		cout << "Second iteration for file" << i << " completed" << endl;
	}

	auto t_en = clock();

	cout << "\nFound collisions: " << collisions << endl;

	return (t_en - t_st);
}

time_t str_ram(string dir_path, int len)
{
	long long int NUMBER_OF_STRINGS = pow(62, len);
	string path = dir_path + "\\hashdir\\test_" + to_string(len);

	path = "d:\\hashdir\\test_" + to_string(len);			//!!!!!!!

	if (!IsPathExist(path))
		throw exception("Directory not found");

	path += "\\file";

	int max_file = 0;
	while (IsPathExist(path + to_string(max_file + 1) + ".bin")) max_file++;

	print_time();
	cout << "Init successful! Staring comparison for " << len << "-symbols..." << endl;

	auto t_st = clock();

	for (int i = 0; i <= max_file; i++)
	{
		int tmp = ((i == max_file) ? (NUMBER_OF_STRINGS % STRINGS_PER_RAM) : (STRINGS_PER_RAM));

		ram_unit rm(path + to_string(i) + ".bin", tmp, len);

		//compare with file self
		rm.compare_str();

		//compare with others
		for (int i1 = i + 1; i1 <= max_file; i1++)
		{
			int tmp1 = ((i1 == max_file) ? (NUMBER_OF_STRINGS % STRINGS_PER_RAM) : (STRINGS_PER_RAM));

			ram_unit rm1(path + to_string(i1) + ".bin", tmp1, len);

			rm * rm1;
		}

		print_time();
		cout << "Second iteration for file" << i << " completed" << endl;
	}

	auto t_en = clock();

	return (t_en - t_st);
}