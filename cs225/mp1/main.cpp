#include <algorithm>
#include <iostream>
#include "EasyBMP.h"

using namespace std;

/**
 * This function rotate the image "in.bmp" by 180 degrees
 * original is the image "in.bmp" in BMP format. Width and Height
 * are the parameters of the orignal image. BMP output is the 
 * revised image. 
 **/

BMP reverse(BMP original, int width, int height, BMP output)
{
/**
* declare variables
**/
        
        int i, j;
	    int r, g, b;
		int hh,ww;
/**
* set hh to the most bottom index of vertical line
* set ww to the rightest parameter of horizontal line
**/
        hh=height-1;
        ww=width-1;
/**
* go to every cell of the image and do functions
**/
	for (i = 0; i <=ww; i++)
	{
		for (j = 0; j <=hh; j++)
		{
/**
* get the rgb values from the original image.
**/
			r = original(i, j)->Red;
			g = original(i, j)->Green;
			b = original(i, j)->Blue;
/**
* the following functions rotate the original image by 180 degree.
**/
			output(ww-i, hh-j)->Red=r;
			output(ww-i, hh-j)->Green=g;
			output(ww-i, hh-j)->Blue=b;
		}
	}



	return output;
}



/**
* function main starts here
**/
int main()
{
/**
* define test1 and output as BMP image
**/
  BMP test1;
  BMP output;
/**
* loads "in.bmp" into test1.
**/
  test1.readFromFile("in.bmp");
//test1.readFromFile("in.bmp");
/**
* loads "in.bmp" into output.
**/
  output.readFromFile("in.bmp");
/**
* call function reverse to rotate the test1 by 180 degree.and
* load the reversed image to image output
**/
  output = reverse(test1, test1.tellWidth(),
                test1.tellHeight(), output);
/**writes the image output to the disk
**/
  output.writeToFile("out.bmp");
return 0;

}
