/*
   BlockBMP -- A Visualization for MP3
   Created by Chase Geigle for CS225, Fall 2011
*/
#include "BlockBMP.h"

BMP BlockBMP::genImg(vector<int> vect, int d)
{
    // error checking: we need to evenly divide the image into d by d blocks
    if( tellWidth() % d != 0 || tellHeight() % d != 0 )
	{
        cerr << "[BlockBMP]: " << d << " does not divide either width " <<
            tellWidth() << " or height " << tellHeight() << endl;
        return BMP();
    }

    // error checking: vector must be of the correct length
    if( ( tellWidth() / d ) * ( tellHeight() / d ) != vect.size() )
        cerr << "[BlockBMP]: Vector not of correct length (" << vect.size()
            << " vs expected " << ( tellWidth() / d ) * ( tellHeight() / d ) << ")" << endl;

    BMP ret;
    ret.setSize( tellWidth(), tellHeight() );

    int numWidth = tellWidth() / d;

    for( unsigned int i = 0; i < vect.size(); i++ ) {
        int idx = vect[i] % ( ( tellWidth() / d ) * ( tellHeight() / d ) + 1 );
        if( idx <= 0 )
            idx = 1;

        // if idx is different, we modified it above---alert user
        if( idx != vect[i] )
            cerr << "[BlockBMP]: Block number " << vect[i] << " not valid, "
                << "truncated to " << idx << endl;

        int x = ( (idx - 1) % numWidth ) * d;
        int oy = ( (idx - 1) / numWidth ) * d;

        int y = oy;

        int sy = y + d;

        int nx = ( i % numWidth ) * d; 
        int ny = ( i / numWidth ) * d;

        for( int j = nx; j < nx + d; j++ ) {
            for( int k = ny; k < ny + d; k++ ) {
                *ret(j,k) = *operator()(x,y);
                y++;
                if( y == sy ) {
                    y = oy; 
                    x++;
                }
            }
        }
    }

    return ret;
}
