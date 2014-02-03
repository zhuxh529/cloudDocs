/**
 * maptiles.cpp
 *	 			
 * mapTiles() function
 *	 			
 * Author: Jack Toole
 *	 			
 * Developed for CS225 PhotoMosaic MP
 * Fall 2011
 */
	 			
#include "maptiles.h"
#include <iostream>
#include <map>

using namespace std;

/**
 * Map the image tiles into a mosaic canvas which closely
 * matches the input image.
 *	 			
 * @param theSource The input image to construct a photomosaic of
 * @param theTiles The tiles image to use in the mosaic
 */
MosaicCanvas * mapTiles(SourceImage const & theSource, vector<TileImage> const & theTiles)
{
   int row=theSource.getRows();
   int column=theSource.getColumns();
   RGBApixel x, y;
   
   MosaicCanvas *target=new MosaicCanvas(row, column);
	Point<3> pp, qq, tar;
   vector< Point<3> > vt;


    int S=theTiles.size();
   for(int a=0; a<S; a++)
   {
	
   x=theTiles[a].getAverageColor();
   
   pp[0]=x.Red;
	pp[1]=x.Green;
	pp[2]=x.Blue;
   vt.push_back(pp);
   }
   
  
	KDTree<3> tree(vt);
   
   for(int i=0; i<row; i++)
   {
	for(int j=0;j<column; j++)
   {
	y=theSource.getRegionColor(i,j);
   qq[0]=y.Red;
	qq[1]=y.Green;
	qq[2]=y.Blue;
	tar=tree.findNearestNeighbor(qq);	// error here
	int b=0;
 /*  while(tar!=vt[b])
   {
	b++;
   }
*/
   //if(tar==vt[b])
int k=0;
for(b=0; b<S;b++)
{
if(tar==vt[b]) break;
}	

//if(k>1) cout<<k<<"   =k is here "<<endl;

target->setTile(i,j,theTiles[b]);
	
	}}
   
   
  
	return target; // Replace with your own code
}

// You are encouraged to add your own helper functions here

