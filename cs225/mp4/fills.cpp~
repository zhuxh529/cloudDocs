// Note: Make sure you return something from these functions before you run or you may (will) have segfaults

#include "fills.h"
#include <algorithm>
#include <iostream>
using namespace std;


animation DFSfill(BMP& img, int x, int y, colorPicker & fillColor, int tolerance, int frameFreq)
{
	animation anim;//given
   RGBApixel  orig, curr;
   

   
	
   int i, j;//i and j are the width and height of the image
   int p,q;//p and q are counters
   int xx, yy; //xx and yy are the element of the stack
   int f=0; //counter for the framefreq
   int Dtol;// the one that is compared to tolerance
   
   i=img.tellWidth();
   j=img.tellHeight();

   int Orig_R=(*img(x,y)).Red;
	int Orig_G=(*img(x,y)).Green;
	int Orig_B=(*img(x,y)).Blue;
   
  //for(p=0;p<i;i++)
   

	bool proc;
   bool A[i][j];//define the array which keeps track of the bool status 

for(p=0;p<i;p++)
{for(q=0;q<j;q++)
A[p][q]=false;}//initialize
  

   Stack<int> XX;
   Stack<int> YY;//define stack
   
   XX.push(x);
   YY.push(y);//initialze the stack

  //for(i)
   
  
   while(!XX.isEmpty() && !YY.isEmpty())
{
  // RGBApixel RIGHT, DOWN, LEFT, UP;

   xx=XX.pop();
	yy=YY.pop();
   proc= A[xx][yy];
   
 
   Dtol=pow((*img(xx,yy)).Red-Orig_R,2)+pow((*img(xx,yy)).Green-Orig_G,2)+pow((*img(xx,yy)).Blue-Orig_B,2);

//judge if sholud push the around neighbouring pixels onto the stack
   if(tolerance>=Dtol && proc==false)
{
	
  
   (*img(xx,yy)).Red=fillColor(xx,yy).Red;
	(*img(xx,yy)).Green=fillColor(xx,yy).Green;
	(*img(xx,yy)).Blue=fillColor(xx,yy).Blue;

   A[xx][yy]=true;//mark it has been processed

// DFSStack.push(RIGHT);//right
   if((xx+1)<=(i-1))
   {XX.push(xx+1);
   YY.push(yy);
	}


//	DFSStack.push(DOWN);//down
   if( (yy+1)<=(j-1))
	{XX.push(xx);
   YY.push(yy+1);}

//	DFSStack.push(LEFT);//left
	if( (xx-1)>=0)
	{XX.push(xx-1);
   YY.push(yy);}


// DFSStack.push(UP);//up
	if((yy-1)>=0)
   {XX.push(xx);
   YY.push(yy-1);}


   f++;//addframe
   if(f%frameFreq==0)
   {

    anim.addFrame(img);
	}

}}
  
	return anim; // Your code here
}








animation BFSfill(BMP& img, int x, int y, colorPicker & fillColor, int tolerance, int frameFreq)
{
	animation anim;//given
   RGBApixel  orig, curr;
   

   
	
   int i, j;//i and j are the width and height of the image
   int p,q;//p and q are counters
   int xx, yy; //xx and yy are the element of the stack
   int f=0; //counter for the framefreq
   int Dtol;// the one that is compared to tolerance
   
   i=img.tellWidth();
   j=img.tellHeight();

   int Orig_R=(*img(x,y)).Red;
	int Orig_G=(*img(x,y)).Green;
	int Orig_B=(*img(x,y)).Blue;
   
  //for(p=0;p<i;i++)
   

	bool proc;
   bool A[i][j];//define the array which keeps track of the bool status 

for(p=0;p<i;p++)
{for(q=0;q<j;q++)
A[p][q]=false;}
  

   Queue<int> XX;
   Queue<int> YY;
   
   XX.enqueue(x);
   YY.enqueue(y);

  //for(i)
   
  
   while(!XX.isEmpty() && !YY.isEmpty())
{
  // RGBApixel RIGHT, DOWN, LEFT, UP;

   xx=XX.dequeue();
	yy=YY.dequeue();
   proc= A[xx][yy];
   
 
   Dtol=pow((*img(xx,yy)).Red-Orig_R,2)+pow((*img(xx,yy)).Green-Orig_G,2)+pow((*img(xx,yy)).Blue-Orig_B,2);
//judge if sholud push the around neighbouring pixels onto the queue
   if(tolerance>=Dtol && proc==false)
{
	
  
   (*img(xx,yy)).Red=fillColor(xx,yy).Red;
	(*img(xx,yy)).Green=fillColor(xx,yy).Green;
	(*img(xx,yy)).Blue=fillColor(xx,yy).Blue;

   A[xx][yy]=true;

// DFSStack.push(RIGHT);//right
   if((xx+1)<=(i-1))
   {XX.enqueue(xx+1);
   YY.enqueue(yy);
	}


//	DFSStack.push(DOWN);//down
   if( (yy+1)<=(j-1))
	{XX.enqueue(xx);
   YY.enqueue(yy+1);}

//	DFSStack.push(LEFT);//left
	if( (xx-1)>=0)
	{XX.enqueue(xx-1);
   YY.enqueue(yy);}


// DFSStack.push(UP);//up
	if((yy-1)>=0)
   {XX.enqueue(xx);
   YY.enqueue(yy-1);}


   f++;
   if(f%frameFreq==0)
   {

    anim.addFrame(img);
	}

}}
  
	return anim; // Your code here
}













animation DFSfillSolid(BMP& img, int x, int y, RGBApixel fillColor, int tolerance, int frameFreq)
{
	animation anim;
   solidColorPicker nmd=solidColorPicker(fillColor);
   anim= DFSfill(img, x, y, nmd, tolerance, frameFreq);
   
  // anim=DFSfill(img, x,y, fillColor, tolerance, frameFreq);
	return anim; // Your code here
}

animation DFSfillGrid(BMP& img, int x, int y, RGBApixel gridColor, int gridSpacing, int tolerance, int frameFreq)
{
	animation anim;
	gridColorPicker nmd=gridColorPicker(gridColor,gridSpacing);
   anim= DFSfill(img, x, y, nmd, tolerance, frameFreq);
	return anim; // Your code here
}

animation DFSfillGradient(BMP& img, int x, int y, RGBApixel fadeColor1, RGBApixel fadeColor2, int radius, int tolerance, int frameFreq)
{
	animation anim;
   gradientColorPicker nmd=gradientColorPicker(fadeColor1,fadeColor2, radius, x,y);
   anim= DFSfill(img, x, y, nmd, tolerance, frameFreq);
	return anim; // Your code here
}

animation BFSfillSolid(BMP& img, int x, int y, RGBApixel fillColor, int tolerance, int frameFreq)
{
	animation anim;
   solidColorPicker nmd=solidColorPicker(fillColor);
   anim= BFSfill(img, x, y, nmd, tolerance, frameFreq);
	return anim; // Your code here
}

animation BFSfillGrid(BMP& img, int x, int y, RGBApixel gridColor, int gridSpacing, int tolerance, int frameFreq)
{
	animation anim;
	gridColorPicker nmd=gridColorPicker(gridColor,gridSpacing);
   anim= BFSfill(img, x, y, nmd, tolerance, frameFreq);
	return anim; // Your code here
}

animation BFSfillGradient(BMP& img, int x, int y, RGBApixel fadeColor1, RGBApixel fadeColor2, int radius, int tolerance, int frameFreq)
{
	animation anim;
	gradientColorPicker nmd=gradientColorPicker(fadeColor1,fadeColor2, radius, x,y);
   anim= BFSfill(img, x, y, nmd, tolerance, frameFreq);
	return anim; // Your code here
}
