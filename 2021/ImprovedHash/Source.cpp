#include <iostream>
#include "FileAccesser.h"

const int ALPHABET_POWER = 62;
//length of string [3..6]
const int LENGTH = 3; 
//number of strings
const unsigned long long int NUMBER_OF_STRINGS = pow(ALPHABET_POWER, LENGTH); 


/*
0 - STEP-BY-STEP mode
1 - GENERATION mode
2 - PROCESS mode
DEBUG
3 - READ FILE mode
*/
const int PROGRAM_MODE = 3;

int main()
{
	switch(PROGRAM_MODE)
	{
	case 0:
	{
	
		generate_files();
		//compare();
	
	}

	case 1:
	{
		auto t_st = clock();
		generate_files();
		auto t_en = clock();

		/*
		LENGTH		TICKS		SIZE(MB)
		1			1			<<1
		2			4			<<1
		3			136			1.5
		4			6770		38
		5
		6
		*/

		cout << "Generation of the files for " << LENGTH << " symbols took " << t_en - t_st << " ticks" << endl;
	}

	case 2:
	{
	
		//compare
	}

	case 3:
	{
		debug_read(LENGTH);
	}

	default:
		cout << "Fatal error. Wrong PROGRAM_MODE" << endl;
	}
	
	
}