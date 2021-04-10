#include <Adafruit_NeoPixel.h>
#define PIN 6 // номер порта к которому подключен модуль
#define count_led 64// количество светодиодов 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(count_led, PIN, NEO_GRB + NEO_KHZ800); //first number change does distance between colors

int array[8][8] =
{ {0,0,0,0,1,1,1,1},
  {0,0,0,0,0,0,1,1},
  {3,2,2,0,0,1,0,1}, 
  {2,2,3,2,0,0,0,1},
  {2,4,2,2,0,0,0,0},
  {0,4,0,0,0,0,0,0},
  {0,4,2,0,0,0,2,0},
  {2,2,2,2,2,2,2,2}
};

void iswap(int &a, int &b)
{
	a += b;
  	b = a - b;
  	a -= b;
}

void parse_array()
{
	for(int i = 1; i < 8; i+=2)
      for(int j = 0; j < 4; j++)
      	iswap(array[i][j], array[i][7 - j]);

}

void setup() 
{
  Serial.begin(9600);
  pixels.begin();
  parse_array();
}

auto getColor(int c)
{
	switch(c)
    {
      case 0: return pixels.Color(0,0,0);
      case 1: return pixels.Color(255,255,0);
      case 2: return pixels.Color(0,255,0);
      case 3: return pixels.Color(255,0,0);
      case 4: return pixels.Color(128,64,32);
      default: return pixels.Color(0,0,0);
    }
}

void print()
{
  for (int i = 0; i < count_led; i++)
    {
      pixels.setPixelColor(i,getColor(array[i/8][i%8]));
    }
    pixels.show();
    delay(1000);
}

void clear()
{
  for (int i = 0; i < count_led; i++)
    {
      pixels.setPixelColor(i,pixels.Color(0,0,0));
    }
    pixels.show();
	delay(1000);
}

void loop() 
{
  
  print();
  clear();
  
}