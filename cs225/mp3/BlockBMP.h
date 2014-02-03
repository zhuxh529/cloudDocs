/*
   BlockBMP -- A Visualization for MP3
   Created by Chase Geigle for CS225, Fall 2011
*/
#include "EasyBMP.h"

#include <vector>
#include <iostream>
using std::vector;
using std::cerr;
using std::endl;

class BlockBMP : public BMP {
    public:
        BMP genImg( vector<int> vect, int d );
};
