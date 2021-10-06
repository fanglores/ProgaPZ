#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Image
{
public:
	fstream img_src;
	int* img_array;
	int width, height;
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

		char* info = new char[54];
		img_src.read(info, 54);

		width = *(int*)&info[18];
		height = *(int*)&info[22];

		img_array = new int[width * height];
		img_src.read(reinterpret_cast<char*>(img_array), width * height);
	}

	~Image()
	{
		delete[] img_array;
		img_src.close();
	}
};

int Image::img_num = 1;

double operator+(const Image& im1, const Image& im2)
{
	unsigned long int sq = 0;
	for (int i = 0; i < im1.width * im1.height; i++)
		sq += (im1.img_array[i] - im2.img_array[i]) * (im1.img_array[i] - im2.img_array[i]);

	return sqrt(sqrt(sq));
}

int main()
{
	Image a1, a2, a3, a4;

	cout << "Image 1 and 2 match = " << a1 + a2 << endl;
	cout << "Image 1 and 3 match = " << a1 + a3 << "\t- the best match" << endl;	//optional
	cout << "Image 1 and 4 match = " << a1 + a4 << endl;

	cout << "Image 2 and 3 match = " << a2 + a3 << endl;
	cout << "Image 2 and 4 match = " << a2 + a4 << endl;

	cout << "Image 3 and 4 match = " << a3 + a4 << endl;
}
