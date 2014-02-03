#ifndef GRADIENTCOLORPICKER_H
#define GRADIENTCOLORPICKER_H

#include"colorPicker.h"
#include<math.h>
#include<iostream>

class gradientColorPicker : public colorPicker{
  public:
    gradientColorPicker(RGBApixel fadeColor1, RGBApixel fadeColor2, int radius, int centerX, int centerY);
    virtual RGBApixel operator()(int x, int y);



  private:
  double d;
  int center_x;
  int center_y;
  int r;
  RGBApixel A1, B2;
};
#endif