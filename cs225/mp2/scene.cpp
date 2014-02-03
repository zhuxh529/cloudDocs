#include "scene.h"
#include "image.h"
#include "EasyBMP.h"
#include<algorithm>
#include<iostream>






//	constructs an instance of the class
Scene::Scene(int max)
{
	  mm=max;
    
     img= new Image*[mm];
     for(int i=0; i<mm; i++)
	{
	 
    img[i]=NULL; 	
	
   }
     xx= new int[mm];
     yy= new int[mm];

}

//assignment operator
Scene const & Scene::operator=(Scene const & source)
{
if (this !=( & source))
	{
//clear the contents of img, xx, and yy//
	   totalclr();	
//calling the copy function to make the copy
   copy(source);
		
	}
	return *this;
}


//destructor goes here
Scene:: ~Scene()
{
    
    for(int i=0; i<mm; i++)
	{
		//check NULL
	 if(img[i]!=NULL) 
    {delete img[i];
    img[i]=NULL; 	
	}
   }
   	delete [] img;
      img=NULL;
      delete [] xx;
      xx=NULL;
      delete [] yy;
      yy=NULL;
}



//copy constructor that initializes this scene as an independent copy
// of the original 
Scene:: Scene(Scene const & source)
{
    mm = source.mm;
    img = source.img;
	 xx= new int[mm];
    yy= new int[mm];
    img= new Image*[mm];
          for(int i=0; i<mm; i++){
         xx[i]=source.xx[i];
        }
          for(int i=0; i<mm; i++){
         yy[i]=source.yy[i];
        }
          for(int i=0; i<mm; i++){
         if(source.img[i]==NULL) img[i]=NULL;
         else {
              img[i]=new Image(*source.img[i]);
              
                 }
}
}

// addpicture function goes here

void Scene::addpicture(const char* FileName, int index, int x, int y)
{

if(img[index]!=NULL) {
   delete img[index];
   img[index]=NULL;
}

if(index<0||index>(mm-1)) 
{
cout << "index out of bounds" << endl;

}
img[index]=new Image;
img[index]->readFromFile(FileName);
xx[index]=x;
yy[index]=y;

}


//changemaxlayers goes here
void Scene::changemaxlayers(int newmax)
{
   Image **img2;
   img2=new Image*[newmax];
//if newmax<max
  	if(newmax<mm)
{
 	for(int i=0; i<newmax;i++)
    {
   
	if(img[i]!=NULL){    
   img2[i]=img[i];}
   else img2=NULL;
    }
    for(int i=newmax;i<mm;i++)
    {
	if(img[i]!=NULL) {cout << "invalid newmax" << endl;}
	}
   
}

//if newmax>=max
	if(newmax>=mm)
{
   
	for(int i=0; i<mm; i++)
	{
   if(img[i]!=NULL){    
   img2[i]=img[i];}
   else img2=NULL;
	
	}
    for(int i=mm; i<newmax; i++)
	{img2[i]=NULL;
}
}
 for(int i=0; i<mm; i++)
	{
	 if(img[i]!=NULL) 
    {delete img[i];
    img[i]=NULL; 	
	}
   }
 
   	delete [] img;
     img=NULL;
     
//copy the img2 tp img
img=img2;
for(int i; i<newmax; i++)
{
if (img2[i]!=NULL) img[i]=new Image(*img2[i]);
else img[i]=NULL;
}

//delete img2
for(int i=0; i<newmax; i++)
{
delete img2[i];
}
    delete img2;
mm=newmax;

}

//changelayer function goes here
void Scene::changelayer(int index, int newindex)
{
if(index>=0 && newindex>=0 && index<mm && newindex<mm)
{
   if(index!=newindex)
   {if(img[index]!=NULL)
   {
    delete img[newindex];
    img[newindex]=NULL;
   }
   img[newindex]=img[index];
   img[index]=NULL;
   xx[newindex]=xx[index];
   yy[newindex]=yy[index];
   
img[index]=NULL;
    
   
   }
index=newindex;
}
}

//translate function goes here
void Scene:: translate(int index, int xcoord, int ycoord)
{
  if(index<0||index>=mm||(img[index]==NULL))
 {
	cout << "invalid index" << endl;
 }
	else {xx[index]=xcoord;
	yy[index]=ycoord;}

  
}

//drawscene function goes here
Image Scene::drawscene() const
{
    Image cao;
    int h,w;
    int hm,wm;
    int r, g, b;
    int d,c;
    int aa; 
    int bb;
    aa=0;
    bb=0;
    c=0;
    d=0;
     hm=0;
 	  wm=0;
//to get the largest dimension
	for(int i=0; i<mm; i++)
    {
     if(img[i]==NULL) continue; 
		  h=yy[i]+(img[i]->tellHeight());
        w=xx[i]+(img[i]->tellWidth());
			hm=(hm>h)?hm:h;
			wm=(wm>w)?wm:w;
       
        
    }
  
 //set the new background image   
    cao.setSize(wm, hm);
    cout<<wm<<"....."<<hm<<endl;
 //add the images on the background

    for(int l=0; l<mm; l++)
 {
    if (img[l]==NULL) continue;
    h=img[l]->tellHeight();
    w=img[l]->tellWidth(); 
    aa=xx[l];
    bb=yy[l];
    
	for(int i=xx[l]; i<(aa+w);i++)
     {
		for (int j=yy[l];j<(h+bb) ;j++)
        {
			r = (*img[l])(i-aa, j-bb)->Red;
			g = (*img[l])(i-aa, j-bb)->Green;
			b = (*img[l])(i-aa, j-bb)->Blue;
			cao(i, j)->Red=r;
			cao(i, j)->Green=g;
			cao(i, j)->Blue=b;
        }
     }
     }

    return cao;
    
}


//deletepicture function goes here
void Scene::deletepicture(int index)
{
  if(index<0||index>=mm||(img[index]==NULL))
 {
	cout << "invalid index" << endl;
 }
  else {delete img[index];
        img[index]=NULL;
       }
}

//getpicture funciton goes here
Image* Scene::getpicture(int index) const
{

  if(index<0||index>=mm||(img[index]==NULL))
 {
	cout << "invalid index" << endl;
    return NULL;
 }
 
  return img[index];
}





 	
        
     
    


//here is to clear the img[]
void Scene::clear()
{
	  for(int i=0; i<mm; i++)
	{
	 
    img[i]=NULL; 	
	
   }
   delete img;
     
}


void Scene::totalclr()
{
 for(int i=0; i<mm; i++)
	{
	 if(img[i]!=NULL) 
    {delete img[i];
    img[i]=NULL; 	
	}
   }
   	delete [] img;
  
     delete [] xx;
     xx=NULL;

     delete [] yy;
     yy=NULL;
}



void Scene::copy(const Scene & source)
{
	mm = source.mm;
      
   	xx= new int[mm];
      yy= new int[mm];
      img= new Image*[mm];
          for(int i=0; i<mm; i++){
         xx[i]=source.xx[i];
        }
          for(int i=0; i<mm; i++){
         yy[i]=source.yy[i];
        }
          for(int i=0; i<mm; i++){
			if(source.img[i]==NULL) {img[i]=NULL;}
         else {img[i]=new Image(*source.img[i]);}
              
        }
    
}



