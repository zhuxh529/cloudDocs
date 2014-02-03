// **************************************************************
// *                                                            *
// *  quadtree.h                                                *
// *                                                            *
// *  Quadtree class                                            *
// *                                                            *
// *  CS 225 Spring 2007                                        *
// *                                                            *
// **************************************************************

#ifndef QUADTREE_H
#define QUADTREE_H

#include "EasyBMP.h"
#include <iostream>
using namespace std;


class Quadtree
{
	private:

	// A simple class representing a single node of a Quadtree.
	// You may want to add to this class; in particular, it could probably
	// use a constructor or two...
	class QuadtreeNode
	{
		public:
		QuadtreeNode* nwChild;  // pointer to northwest child
		QuadtreeNode* neChild;  // pointer to northeast child
		QuadtreeNode* swChild;  // pointer to southwest child
		QuadtreeNode* seChild;  // pointer to southeast child

		RGBApixel element;  // the pixel stored as this node's "data"

      QuadtreeNode()
      :nwChild(NULL), neChild(NULL),swChild(NULL), seChild(NULL), element(RGBApixel())
     {}
     
	};
	
	QuadtreeNode* root;    // pointer to root of quadtree
	int dis;

	public:
	Quadtree(); //constructor null
   ~Quadtree();
   
   
   Quadtree(const BMP & source, int d); // constructorvoid avg(QuadtreeNode* subroot)
	Quadtree(const Quadtree & rhs);

	void buildTree(const BMP & source, int d);
   void buildT(const BMP & source, int d);
	void realbuild(const BMP & source, int d, QuadtreeNode* subroot, int x, int y, RGBApixel & BBQ);
   void avg(QuadtreeNode* subroot, int d);
	//void realbuild(int x, int y,int d, const BMP& source, QuadtreeNode* subroot)   ;

	void setchildren0(QuadtreeNode* subroot);

   void Printdis();
  
   Quadtree * copy(Quadtree & other);

	QuadtreeNode * copy(QuadtreeNode *const& subRoot);
   //Quadtree & operator=(const Quadtree * rhs);
   //void operator=(const Quadtree & rhs);
    Quadtree const & operator=(Quadtree const & source);

	void clear(QuadtreeNode* &subroot);

	RGBApixel getPixel(int x, int y) const;
	void gotu(int x, int y, int d, QuadtreeNode const* subroot, RGBApixel & B) const;
//QuadtreeNode*  getPixelhelper(int x, int y,int d, QuadtreeNode* subroot);

   //RGBApixel getPixel(int x, int y) const;
//RGBApixel const & getPixel(QuadtreeNode const * curNode,
                                     //  int x, int y, int res) const;


   BMP decompress() const;
	//void depress(BMP &img, QuadtreeNode* subroot, int x, int y, int d); 
  void decompress(QuadtreeNode const * curNode, BMP & target,
                   int x, int y, int res) const;



   void clockwiseRotate();
   void clock(QuadtreeNode* subroot);

//    prune
	void prune(int i);
   void prunehelp(int i, QuadtreeNode* subroot);
   bool compare(QuadtreeNode* nw, QuadtreeNode* ne, QuadtreeNode* sw, QuadtreeNode* se, int i);
	RGBApixel average(QuadtreeNode* nw, QuadtreeNode* ne, QuadtreeNode* sw, QuadtreeNode* se);
int getdif(RGBApixel ta, RGBApixel total) const;


   void  gettol(QuadtreeNode const* subroot, int i, bool &tol, RGBApixel const & top ) const;



 void size(int i, QuadtreeNode const* subroot, int &a) const;
   int pruneSize(int i) const;
   int idealPrune(int i) const;
   int search(int low, int high, int x) const;
	
	
	
	
	
	/**** Functions added for testing/grading ****/
	/**** Do not remove this line!            ****/
	#include "quadtree_given.h"
};

#endif
