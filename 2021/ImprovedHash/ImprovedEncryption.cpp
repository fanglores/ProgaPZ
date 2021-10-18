#include <map>
#include <bitset>
using namespace std;

/*
<hash> is always <int>, so it takes 4 bytes
<string> max len is 6 <char>s, so it takes 36 bits (4.5 bytes instead of 6 bytes)
In total 9.5 bytes
*/

map<char, bitset<6>> dict =
{
	{'a', bitset<6>{  0 }},
	{'b', bitset<6>{  1 }},
	{'c', bitset<6>{  2 }},
	{'d', bitset<6>{  3 }},
	{'e', bitset<6>{  4 }},
	{'f', bitset<6>{  5 }},
	{'g', bitset<6>{  6 }},
	{'h', bitset<6>{  7 }},
	{'i', bitset<6>{  8 }},
	{'j', bitset<6>{  9 }},
	{'k', bitset<6>{ 10 }},
	{'l', bitset<6>{ 11 }},
	{'m', bitset<6>{ 12 }},
	{'n', bitset<6>{ 13 }},
	{'o', bitset<6>{ 14 }},
	{'p', bitset<6>{ 15 }},
	{'q', bitset<6>{ 16 }},
	{'r', bitset<6>{ 17 }},
	{'s', bitset<6>{ 18 }},
	{'t', bitset<6>{ 19 }},
	{'u', bitset<6>{ 20 }},
	{'v', bitset<6>{ 21 }},
	{'w', bitset<6>{ 22 }},
	{'x', bitset<6>{ 23 }},
	{'y', bitset<6>{ 24 }},
	{'z', bitset<6>{ 25 }},

	{'A', bitset<6>{ 26 }},
	{'B', bitset<6>{ 27 }},
	{'C', bitset<6>{ 28 }},
	{'D', bitset<6>{ 29 }},
	{'E', bitset<6>{ 30 }},
	{'F', bitset<6>{ 31 }},
	{'G', bitset<6>{ 32 }},
	{'H', bitset<6>{ 33 }},
	{'I', bitset<6>{ 34 }},
	{'J', bitset<6>{ 35 }},
	{'K', bitset<6>{ 36 }},
	{'L', bitset<6>{ 37 }},
	{'M', bitset<6>{ 38 }},
	{'N', bitset<6>{ 39 }},
	{'O', bitset<6>{ 40 }},
	{'P', bitset<6>{ 41 }},
	{'Q', bitset<6>{ 42 }},
	{'R', bitset<6>{ 43 }},
	{'S', bitset<6>{ 44 }},
	{'T', bitset<6>{ 45 }},
	{'U', bitset<6>{ 46 }},
	{'V', bitset<6>{ 47 }},
	{'W', bitset<6>{ 48 }},
	{'X', bitset<6>{ 49 }},
	{'Y', bitset<6>{ 50 }},
	{'Z', bitset<6>{ 51 }},

	{'0', bitset<6>{ 52 }},
	{'1', bitset<6>{ 53 }},
	{'2', bitset<6>{ 54 }},
	{'3', bitset<6>{ 55 }},
	{'4', bitset<6>{ 56 }},
	{'5', bitset<6>{ 57 }},
	{'6', bitset<6>{ 58 }},
	{'7', bitset<6>{ 59 }},
	{'8', bitset<6>{ 60 }},
	{'9', bitset<6>{ 61 }}
};
