#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Image
{
public:
	fstream img_src;
	int* img_array;
	static int img_num;

	Image()
	{
		string filename = "apple_" + to_string(img_num) + ".bmp";
		img_src.open(filename);
		if (!img_src.is_open())
		{
			cout << "Critical error while opening the image " << filename << endl;
			//return;
		}
		else cout << "Opened " << filename << endl;
		img_num++;
	}

	void iParser()
	{
		char* info = new char[54];
		img_src.read(info, 54);

		int w = *(int*)&info[18];
		int h = *(int*)&info[22];

		int size = 3 * w * h;
		char* data = new char[size];

		img_src.read(data, size);

	}

	~Image()
	{
		delete[] img_array;
	}
};

int Image::img_num = 1;

int main()
{
	Image a1, a2, a3, a4;
	cout << "A";
	a1.iParser();
}
