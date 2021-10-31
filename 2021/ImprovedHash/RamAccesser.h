#pragma once
#include <string>
#include <fstream>
using namespace std;

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

public:
	ram_unit() = delete;
	ram_unit(string file_path, int str_in_file);

};