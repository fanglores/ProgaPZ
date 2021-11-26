#pragma once
#include <string>
#include <fstream>
using namespace std;

const int STRINGS_PER_RAM = 119304647;
bool IsPathExist(const string& path_to_check);
void print_time();

time_t hash_ram(string dir_path, int len);
time_t str_ram(string dir_path, int len);

struct unit
{
	char* str;
	int hash;

	unit() = delete;

};

class ram_unit
{
private:
	int size;
	unit* cache;
	int l;

public:
	ram_unit() = delete;
	ram_unit(string file_path, int str_in_file);
	int compare();
	void compare_str();

	~ram_unit();
	friend int operator+(const ram_unit& ru1, const ram_unit& ru2);
	friend void operator*(const ram_unit& ru1, const ram_unit& ru2);
};