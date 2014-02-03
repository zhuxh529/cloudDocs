#include <stdlib.h>
#include <iostream>
#include "gradientColorPicker.h"
using namespace std;

gradientColorPicker::gradientColorPicker(RGBApixel fadeColor1, RGBApixel fadeColor2, int radius, int centerX, int centerY)
{
  
 center_x=centerX;
 center_y=centerY;
 r=radius;
 A1=fadeColor1;
 B2=fadeColor2;
}

RGBApixel gradientColorPicker::operator()(int x, int y)
{
	RGBApixel retval;
   double a,b;
   a=(center_x>x)?(center_x-x):(x-center_x);
	b=(center_y>y)?(center_y-y):(y-center_y);
	d=a+b;
   if(d<0) cout<<"wrong>0  line: 22"<<endl;
	
   if(d<=r)
   {
	retval.Red = A1.Red - floor((d*(A1.Red))/r) + floor((d*B2.Red)/r);
	retval.Green = A1.Green - floor((d*(A1.Green))/r) + floor((d*B2.Green)/r);
	retval.Blue = A1.Blue - floor((d*(A1.Blue))/r) + floor((d*B2.Blue)/r);
   }
   else
   {
	 retval.Red = B2.Red;
	retval.Green = B2.Green;
	retval.Blue = B2.Blue;
   }
	return retval;
}
