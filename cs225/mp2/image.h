#ifndef _IMAGE_H_
#define _IMAGE_H_


#include <cmath>
#include <cstring> // For memcpy on g++ 4.3+
#include <stdint.h> // for uint8_t, et al.
#include "EasyBMP.h"


#ifdef _MSC_VER 
// MS Visual Studio gives warnings when using 
// fopen. But fopen_s is not going to work well 
// with most compilers, and fopen_s uses different 
// syntax than fopen. (i.e., a macro won't work) 
// So, we'lll use this:
#define _CRT_SECURE_NO_DEPRECATE
#endif




#ifdef __BCPLUSPLUS__ 
// The Borland compiler must use this because something
// is wrong with their cstdio file. 
#include <stdio.h>
#else 
#include <cstdio>
#endif

#ifdef __GNUC__
// If g++ specific code is ever required, this is 
// where it goes. 
#endif

#ifdef __INTEL_COMPILER
// If Intel specific code is ever required, this is 
// where it goes. 
#endif

#ifndef _DefaultXPelsPerMeter_
#define _DefaultXPelsPerMeter_
#define DefaultXPelsPerMeter 3780
// set to a default of 96 dpi 
#endif

#ifndef _DefaultYPelsPerMeter_
#define _DefaultYPelsPerMeter_
#define DefaultYPelsPerMeter 3780
// set to a default of 96 dpi
#endif


//Image is defined here, which includes BMP 
class Image: public BMP	{
 public:
    Image myImage();
//define the three functions we wanna use
	void invertcolors();
	void flipleft();
    void adjustbrightness(int , int , int );
};
#endif





