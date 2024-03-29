#include <iostream>
#include <string>
#include "FileAccesser.h"
#include "RamAccesser.h"

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
			cout << "2. Compare hashes via disk (not recommended)" << endl;
			cout << "3. Compare hashes via RAM" << endl;
			cout << "4. Compare strings via RAM" << endl;
			//more options
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
					4			6 770				38
					5			394 882				8 000
					6			9 540 685			540 627
					*/

					cout << "Generation of the files for " << int(ln) << " symbols took " << t_en - t_st << " ticks" << endl;
					cout << "Current TPS is " << CLOCKS_PER_SEC << endl << endl;
				}
				else cout << "Wrong length!" << endl;
				
				break;
			}

			case 2:
			{
				cout << "Enter length of the string(1..6): ";
				cin >> ln;
				cin.clear();
				cin.sync();
				cout << endl;

				ln = ln - '0';
				if (ln >= 1 && ln <= 6)
				{
					clock_t dt = compare_hash(current_path, int(ln));

					/*
					LENGTH		TICKS(1000cps)		Collisions
					1			1					0
					2			1					0
					3			2					0
					4			2					0
					5
					6
					*/

					cout << "\nComparison of the files for " << int(ln) << " symbols took " << dt << " ticks" << endl;
					cout << "Current TPS is " << CLOCKS_PER_SEC << endl << endl;
				}
				else cout << "Wrong length!" << endl;

				break;
			}

			case 3:
			{
				cout << "Enter length of the string(1..6): ";
				cin >> ln;
				cin.clear();
				cin.sync();
				cout << endl;

				ln = ln - '0';
				if (ln >= 1 && ln <= 6)
				{
					clock_t dt = hash_ram(current_path, int(ln));

					cout << "\nComparison(hash) of the files for " << int(ln) << " symbols took " << dt << " ticks" << endl;
					cout << "Current TPS is " << CLOCKS_PER_SEC << endl << endl;
				}
				else cout << "Wrong length!" << endl;

				break;
			}

			case 4:
			{
				cout << "Enter length of the string(1..6): ";
				cin >> ln;
				cin.clear();
				cin.sync();
				cout << endl;

				ln = ln - '0';
				if (ln >= 1 && ln <= 6)
				{
					clock_t dt = str_ram(current_path, int(ln));

					cout << "\nComparison(string) of the files for " << int(ln) << " symbols took " << dt << " ticks" << endl;
					cout << "Current TPS is " << CLOCKS_PER_SEC << endl << endl;
				}
				else cout << "Wrong length!" << endl;

				break;
			}

			case 6:
			{
				cout << "Enter length of the string(1..6): ";
				cin >> ln;
				cin.clear();
				cin.sync();
				cout << endl;

				ln = ln - '0';

				debug_read(current_path, int(ln));
				break;
			}

			default:
			{
				cout << "Fatal error. Wrong command" << endl;
				cout << "Press any key to try again..." << endl;
				system("pause");

				f = true;
			}
			}
		}
	}
	catch (exception e)
	{
		cout << "Fatal error: " << e.what() << endl;
		system("pause");
		return -1;
	}
	
	system("pause");
	return 0;
}