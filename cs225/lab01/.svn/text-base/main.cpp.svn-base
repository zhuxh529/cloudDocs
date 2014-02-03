#include <algorithm>
#include <iostream>
#include "EasyBMP.h"

using namespace std;


/**
 * This function accepts a BMP object and integers which define a rectangle as
 * parameters and proceeds to alter the image by modifying all of the pixels that
 * fall into this rectangle by converting them to sepia.  The modified image is
 * then returned.  Visit http://blogs.techrepublic.com.com/howdoi/?p=120 to see
 * how to convert an image pixel to a sepia tone.
 *
 * @param original A BMP object which holds the image data we want to make sepia.
 * @param x The starting x coordinate of the rectangle to change.
 * @param y The starting y coordinate of the rectangle to change.
 * @param width The width of the rectange to change.
 * @param height The height of the rectangle to change.
 *
 * @return The image which has been made sepia.
 **/
BMP makeImageSepia(BMP original, int x, int y, int width, int height)
{
        int w, h;
        int i, j;
        int r, g, b;
        h=original.tellHeight();  
        w=original.tellWidth();
	for (i = x; i < x + width; i++)
	{
		for (j = y; j < y + height; j++)
		{
			r = original(i, j)->Red;
			g = original(i, j)->Green;
			b = original(i, j)->Blue;
			original(i, j)->Red=min(255,(int)((r * .393) + (g *.769) + (b * .189)));
			original(i, j)->Green=min(255,(int)((r* .349) + (g *.686) + (b * .168)));
			original(i, j)->Blue=min(255,(int)((r * .272) + (g *.534) + (b * .131)));
		}
	}



	return original;
}


/**
 * This function accepts a BMP object, integers which define a rectangle, an
 * integer corresponding to the color to change (red, green or blue) and the
 * value to change it by as parameters.  It proceeds to alter the image by
 * modifying all of the pixels that fall into this rectangle by intensifying the
 * given color by the given value (it adds value to the desired color).  The
 * modified image is then returned.
 *
 * @param original A BMP object which holds the image data we want to intensify.
 * @param x The starting x coordinate of the rectangle to change.
 * @param y The starting y coordinate of the rectangle to change.
 * @param width The width of the rectange to change.
 * @param height The height of the rectangle to change.
 * @param color The color (red, green or blue) that we want to intensify.
 * @param value The amount to intensify the desired color.
 *
 * @return The image which has been intensified.
 **/
BMP intensifyImage(BMP original, int x, int y, int width, int height, int color, int value)
{
  
    int i, j;
    int r, g, b;
    for (i = x; i < x + width; i++)
	{
		for (j = y; j < y + height; j++)
		{
			r = original(i, j)->Red;
			g = original(i, j)->Green;
			b = original(i, j)->Blue;
            if (color==0)
			original(i, j)->Red=min(255, (int)(r+value));
            if (color==1)
			original(i, j)->Green=min(255, (int)(g+value));
			if (color==2)
			original(i, j)->Blue=min(255, (int)(b+value));
		}
	}

	return original;
}


/**
 * This function accepts a BMP object and integers which define a rectangle as
 * parameters.  It proceeds to alter the image by modifying all of the pixels
 * that fall into this rectangle by bluring them.  The modified image is then
 * returned.
 *
 * @param original A BMP object which holds the image data we want to blur.
 * @param x The starting x coordinate of the rectangle to change.
 * @param y The starting y coordinate of the rectangle to change.
 * @param width The width of the rectange to change.
 * @param height The height of the rectangle to change.
 *
 * @return The image which has been blured.
 **/
BMP blurImage(BMP original, int x, int y, int width, int height)
{
    int i, j,m;
    int r, g, b;
    for (i = x; i < x + width; i++)
	{
        
		for (j = y; j < y + height;j=j+10)
		{
			r = original(i, j)->Red;
			g = original(i, j)->Green;
			b = original(i, j)->Blue;
           
            for (m=j;m<j+10;m++)
			{
			original(i, m)->Red=min(255, (int)r);
            original(i, m)->Green=min(255, (int)g);
            original(i, m)->Blue=min(255, (int)b);
			}
           
		}
	}



	return original;
}


/**
 * This function accepts a BMP object as a parameter.  It proceeds to alter the
 * image by skewing all of its pixels.  The modified image is then returned.
 * Visit http://keith-hair.net/blog/examples/matrix/skew_diagram.gif to see an
 * example of a skewed image (the middle image is the most relevant).
 *
 * @param original A BMP object which holds the image data we want to skew.
 *
 * @return The image which has been skewed.
 **/
BMP skewImage(BMP original)
{
	BMP skewedImage = original;
	return skewedImage;
}


/**
 * This function accepts a BMP object, integers which define a rectangle and an
 * RGBApixel which corresponds to the desired fill color as parameters.  It
 * proceeds to alter the image by changing the pixels that fall into this
 * rectangle to be the same color as the given RGBApixel.  The modified image is
 * then returned.
 *
 * @param original A BMP object which holds the image data we want to fill.
 * @param x The starting x coordinate of the rectangle to fill.
 * @param y The starting y coordinate of the rectangle to fill.
 * @param width The width of the rectange to fill.
 * @param height The height of the rectangle to fill.
 * @param color The color that we want to use to fill.
 *
 * @return The image which has been filled.
 **/
BMP fillRect(BMP original, int x, int y, int width, int height, RGBApixel color)
{
	return original;
}


/**
 * This function accepts a BMP object, integers which define the starting and
 * ending coordinates of a line and an RGBApixel which corresponds to the desired
 * fill color as parameters.  It proceeds to alter the image by changing the
 * pixels that fall on this line to be the same color as the given RGBApixel.
 * The modified image is then returned.
 *
 * @param original A BMP object which holds the image data we want to color.
 * @param upperX The upper x coordinate of the line to color.
 * @param upperY The upper y coordinate of the line to color.
 * @param lowerX The lower x coordinate of the line to color.
 * @param lowerY The lower y coordinate of the line to color.
 * @param color The color that we want to use to color the line.
 *
 * @return The image which has been colored.
 **/
BMP colorLine(BMP original, int upperX, int upperY, int lowerX, int lowerY, int thickness, RGBApixel color)
{
	return original;
}


/**
 * This function blends, or averages, two BMPs together. That is, each pixel in
 * the returned image consists of the averaged components (red, green, blue) of
 * the two input images.
 *
 * @param firstImage One of the BMPs to be averaged together.
 * @param secondImage The other of the BMPs to be averaged together.
 *
 * @return The averaged image.
 **/
BMP averageImages(BMP firstImage, BMP secondImage)
{
	return firstImage;
}

/**
 * This function turns a rectangle of a BMP into a mosaic - an image consisting
 * of large single-color tiles.
 *
 * @param original Input BMP object
 * @param x The starting x coordinate of the rectangle to change.
 * @param y The starting y coordinate of the rectangle to change.
 * @param width The width of the rectange to change.
 * @param height The height of the rectangle to change.
 *
 * @return The mosaic-d image.
 **/
BMP makeMosaic(BMP original, int x, int y, int width, int height, int tileSize)
{
	return original;
}

/**
 * This function darkens a rectangle of a BMP, decreasing the components
 * (red, green, blue) of each pixel by the given amount
 *
 * @param original Input BMP object
 * @param x The starting x coordinate of the rectangle to change.
 * @param y The starting y coordinate of the rectangle to change.
 * @param width The width of the rectange to change.
 * @param height The height of the rectangle to change.
 * @param amount The integer amount by which to decrease each pixel's
 *			   components.
 *
 * @return The darkened image.
 **/
BMP darken(BMP original, int x, int y, int width, int height, int amount)
{
	return original;
}

/**
 * This function adds random noise to a rectangle of a BMP, using the
 * rand() function (Google "C++ rand").
 *
 * @param original Input BMP object
 * @param x The starting x coordinate of the rectangle to change.
 * @param y The starting y coordinate of the rectangle to change.
 * @param width The width of the rectange to change.
 * @param height The height of the rectangle to change.
 * @param amount A measure of the amount of random variation added.
 *
 * @return The modified image.
 **/
BMP addNoise(BMP original, int x, int y, int width, int height, int amount)
{
	return original;
}


/**
 * This function desaturates a rectangle of a BMP, averaging the
 * components (red, green, blue) of each pixel with a grey of the
 * given brightness.
 *
 * @param original Input BMP object
 * @param x The starting x coordinate of the rectangle to change.
 * @param y The starting y coordinate of the rectangle to change.
 * @param width The width of the rectange to change.
 * @param height The height of the rectangle to change.
 * @param amount The integer amount by which to decrease each pixel's
 *			   components.
 *
 * @return The darkened image.
 **/
BMP desaturate(BMP original, int x, int y, int width, int height, int brightness)
{
	return original;
}


/**
 * This function accepts a BMP object as a parameter.  It proceeds to alter the 
 * image by tiling it (it should repeat it a number of times in a tiled 
 * pattern).  The modified image is then returned.  Visit 
 * http://www.blong.com/Articles/Kylix%20Tutorial/Part10/TiledUnionJack1.png
 * to see an example of a tiled image.
 *
 * @param original A BMP object which holds the image data we want to tile.
 *
 * @return The image which has been tiled.
 **/
BMP tileImage(BMP original)
{
	return original;
}



/**
 * The main function in this program (the starting point of the execution of our
 * code).
 *
 * @return An integer indicating whether execution was successful.
 **/

int main()
{
	BMP test1;
	BMP test2;
	BMP output;
	RGBApixel yellow;
	yellow.Red = yellow.Green = 255;
	yellow.Blue = 0;
	test1.readFromFile("back.bmp");
	test2.readFromFile("merge.bmp");

	// Individual tests
	output = makeImageSepia(test1, 50, 50, test1.tellWidth() - 100, test1.tellHeight() - 100);
	output.writeToFile("sepia.bmp");

	output = intensifyImage(test1, 50, 50, test1.tellWidth() - 100, test1.tellHeight() - 100, 0, 100);
	output.writeToFile("intensify.bmp");

	output = blurImage(test1, 50, 50, test1.tellWidth() - 100, test1.tellHeight() - 100);
	output.writeToFile("blur.bmp");

	output = skewImage(test1);
	output.writeToFile("skew.bmp");

	output = fillRect(test1, 50, 50, test1.tellWidth() - 100, test1.tellHeight() - 100, yellow);
	output.writeToFile("fillrect.bmp");

	output = colorLine(test1, 50, 50, test1.tellWidth() - 100, test1.tellHeight() - 100, 10, yellow);
	output.writeToFile("colorline.bmp");

	output = averageImages(test1, test2);
	output.writeToFile("average.bmp");

	output = makeMosaic(test1, 50, 50, test1.tellWidth() - 100, test1.tellHeight() - 100, 20);
	output.writeToFile("mosaic.bmp");

	output = darken(test1, 50, 50, test1.tellWidth() - 100, test1.tellHeight() - 100, 100);
	output.writeToFile("darken.bmp");

	output = addNoise(test1, 50, 50, test1.tellWidth() - 100, test1.tellHeight() - 100, 100);
	output.writeToFile("addnoise.bmp");

	output = desaturate(test1, 50, 50, test1.tellWidth() - 100, test1.tellHeight() - 100, 100);
	output.writeToFile("desaturate.bmp");

	output = tileImage(test1);
	output.writeToFile("tile.bmp");

	output = skewImage(test1);
	output.writeToFile("skew.bmp");

	// Combined tests
	output = makeImageSepia(output, 50, 50, 100, 100);
	output = intensifyImage(output, 300, 400, 200, 150, 0, 100);
	output = blurImage(output, 150, 350, 10, 150);
	output = skewImage(output);
	RGBApixel fill;
	fill.Red = 255;
	fill.Green = 128;
	fill.Blue = 0;
	output = fillRect(output, 50, 100, 200, 150, fill);
	output = colorLine(output, 267, 50, 200, 150, 10, fill);
	output = averageImages(output, test2);
	output = makeMosaic(output, 140, 90, 200, 150, 20);
	output = darken(output, 400, 200, 200, 150, 100);
	output = addNoise(output, 250, 180, 110, 150, 100);
	output = desaturate(output, 30, 60, 250, 150, 100);
	output = tileImage(output);

	BMP overlay;
	overlay.readFromFile("overlay.bmp");
	output = averageImages(output, overlay);
	output.writeToFile("combined.bmp");

	return 0;
}

