#include <iostream>
#include <string>
#include "FileAccesser.h"

const int ALPHABET_POWER = 62;
//length of string [3..6]
const int LENGTH = 1; 
//number of strings
const unsigned long long int NUMBER_OF_STRINGS = pow(ALPHABET_POWER, LENGTH); 

int main(int argc, char* argv[])
{
	try
	{
		string current_path(argv[0]);
		while (current_path.back() != '\\') current_path.pop_back();

		bool f = true;
		char ans, ln;
		while (f)
		{
			f = false;
			system("cls");
			cout << "Welcome to the hashzone!" << endl << endl;
			cout << "1. Generate files" << endl;
			//cout << "2. ";
			cout << "6. DEBUG reading" << endl << endl << ">>";

			cin >> ans;
			cin.clear();
			cin.sync();
			cout << endl;

			switch (int(ans - '0'))
			{
			case 1:
			{
				cout << "Enter length of the string(1..6): ";
				cin >> ln;
				cin.clear();
				cin.sync();
				cout << endl;

				ln = ln - '0';
				if (ln >= 1 && ln <= 6)
				{
					auto t_st = clock();
					generate_files(current_path, int(ln));
					auto t_en = clock();

					/*
					LENGTH		TICKS(1000cps)		SIZE(MB)
					1			1					<<1
					2			4					<<1
					3			136					1.5
					4			6770				38
					5			394882				8000
					6
					*/

					cout << "Generation of the files for " << LENGTH << " symbols took " << t_en - t_st << " ticks" << endl;
					cout << "Current TPS is " << CLOCKS_PER_SEC << endl;
				}
				else cout << "Wrong length!" << endl;
				
				break;
			}

			case 6:
			{
				debug_read(LENGTH);
				break;
			}

			default:
			{
				cout << "Fatal error. Wrong command" << endl;
				cout << "Press any key to try again..." << endl;
				getchar();

				f = true;
			}
			}
		}
	}
	catch (exception e)
	{
		cout << "Fatal error: " << e.what() << endl;
		getchar();
		return -1;
	}
	
	system("pause");
	return 0;
}