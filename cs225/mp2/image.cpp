#include "image.h"
#include "EasyBMP.h"
#include<algorithm>
#include<iostream>

//function invertcolors() starts here
void Image::invertcolors()
{
     using namespace std;
//define variables
    int i,j;
    int hh,ww;
    int r,g,b;
    
//hh gets the width and ww gets the height of the image
	ww=tellWidth();
    hh=tellHeight();
//for every pixel, we subtract its rgb value from 255
    for (i = 0; i <ww; i++)
	{
		for (j = 0; j <hh; j++)
	    {
  			r = (*this)(i, j)->Red;
			g = (*this)(i, j)->Green;
			b = (*this)(i, j)->Blue;
			(*this)(i, j)->Red=255-r;
			(*this)(i, j)->Green=255-g;
			(*this)(i, j)->Blue=255-b;
		}
	}
}



//function flipleft() starts here
void Image::flipleft()
{
    using namespace std;
//define variables
 	int i,j;
    int hh,ww;
    int r,g,b;
   
//hh gets the width and ww gets the height of the image
	ww=tellWidth();
    hh=tellHeight();
//we swap the image according to the central vertical line
     for (i = 0; i <=((ww-1)/2); i++)
	{
		for (j = 0; j <hh; j++)
	    {
//swap procedures go here
			
  			r = (*this)(i, j)->Red;
			g = (*this)(i, j)->Green;
			b = (*this)(i, j)->Blue;
			(*this)(i, j)->Red=(*this)(ww-1-i, j)->Red;
			(*this)(i, j)->Green=(*this)(ww-1-i, j)->Green;
			(*this)(i, j)->Blue=(*this)(ww-1-i, j)->Blue;
            (*this)(ww-1-i, j)->Red=r;
			(*this)(ww-1-i, j)->Green=g;
			(*this)(ww-1-i, j)->Blue=b;
		}
	}
}

//function adjustbrightness starts here
void Image::adjustbrightness(int rr, int gg, int bb)
{
    using namespace std;
//define variables
	int i, j;
    int r, g, b;
    int rrr,ggg,bbb;
//hh gets the width and ww gets the height of the image
	int ww=tellWidth();
    int hh=tellHeight();
//every pixel of the image gets brightened here
    for (i = 0; i <ww; i++)
	{
		for (j = 0; j <hh; j++)
		{
			r = (*this)(i, j)->Red;
			g = (*this)(i, j)->Green;
			b = (*this)(i, j)->Blue;
            rrr=r+rr;
            ggg=g+gg;
            bbb=b+bb;
//compare the value to 255 and 0 to make sure no overflow~
			rrr=min(255, rrr);
			rrr=max(0, rrr);			
			ggg=min(255, ggg);
			ggg=max(0,ggg);
			bbb=min(255, bbb);
			bbb=max(0, bbb);

           
			(*this)(i, j)->Red=rrr;
  
			(*this)(i, j)->Green=ggg;
			
			(*this)(i, j)->Blue=bbb;
		
            

           


            
           
		}
	}

}
