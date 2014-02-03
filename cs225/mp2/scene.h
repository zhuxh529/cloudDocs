#ifndef _SCENE_H_
#define _SCENE_H_


#include <cmath>
#include <cstring> // For memcpy on g++ 4.3+
#include <stdint.h> // for uint8_t, et al.
#include "EasyBMP.h"
#include "image.h"



using namespace std;

//Image is defined here, which includes BMP 
class Scene
{
 public:
    
Scene(int max) ;
~Scene();
Scene(Scene const & source);
Scene const & operator=(Scene const & source);
void addpicture(const char* FileName, int index, int x, int y);
void changemaxlayers(int newmax);
void changelayer(int index, int newindex);
void deletepicture(int index);
void translate(int index, int xcoord, int ycoord);
Image* getpicture(int index) const;
Image drawscene() const;


//my add-on functions
void totalclr();
void clear();
void copy(const Scene & source);


private:
int mm;
int *xx, *yy;
Image **img;


};


#endif





