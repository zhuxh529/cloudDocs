// **************************************************************
// *                                                            *
// *  quadtree.cpp                                              *
// *                                                            *
// *  A quadtree class                                          *
// *                                                            *
// *  CS 225 Fall 2006                                          *
// *                                                            *
// **************************************************************

#include "quadtree.h"

//const
Quadtree::Quadtree()
:root(NULL),dis(0)
{}


//const
Quadtree::Quadtree(const BMP & source, int d)
{
dis=d;
buildTree(source,d);
}

void Quadtree::Printdis()
{
cout<<"the distance is  "<<dis<<endl;
}


// tooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo




//buildtree
void Quadtree::buildTree(const BMP & source, int d)
{

RGBApixel BBQ;


 if(dis>0)
{
 clear(root);

 dis=0;
}


dis=d;
root=new QuadtreeNode;


if(dis!=1) realbuild(source, dis, root, 0, 0, BBQ);
else if(dis==1) 
{
(root->element).Red=source(0,0)->Red;
(root->element).Green=source(0,0)->Green;
(root->element).Blue=source(0,0)->Blue;
setchildren0(root);

}
}






























////////////////////////////////////////////////////////////////////////







// **************************************************************
// *                                                            *
// *  quadtree.cpp                                              *
// *                                                            *
// *  A quadtree class                                          *
// *                                                            *
// *  CS 225 Fall 2006                                          *
// *                                                            *
// **************************************************************

#include <cstddef>
#include <iostream>

using namespace std;

#include "quadtree.h"
#include "EasyBMP.h"



Quadtree::QuadtreeNode::QuadtreeNode()
   {
    nwChild=NULL;
    neChild=NULL;
    seChild=NULL;
    swChild=NULL;
    element=RGBApixel();
   }

/*Quadtree::QuadtreeNode::QuadtreeNode(QuadtreeNode *const &sourceRoot)
   {
   element=sourceRoot->element;
   if(sourceRoot->nwChild!=NULL)
    {
     nwChild=new QuadtreeNode(sourceRoot->nwChild);
     neChild=new QuadtreeNode(sourceRoot->neChild);
     swChild=new QuadtreeNode(sourceRoot->swChild);
     seChild=new QuadtreeNode(sourceRoot->seChild);
    }
   else
    {
    nwChild=NULL;
    neChild=NULL;
    seChild=NULL;
    swChild=NULL;
    }

   }
*/

//constructors
Quadtree::Quadtree()
{
root=NULL;
resolution=-1;
}

Quadtree::Quadtree(BMP &source, int d)
{
resolution=d;
buildTreeWapper(source,root,d,0,0);
}

Quadtree::Quadtree(Quadtree & source)
{
copy(source);
}

//copy
void Quadtree::copy(const Quadtree & source)
{
resolution=source.resolution;
copyWapper(root,source.root);
//root=new QuadtreeNode(source.root);
}

void Quadtree::copyWapper(QuadtreeNode *&root, QuadtreeNode* const&sroot)
{
if(root==NULL) return;
root=new QuadtreeNode();
root->element=sroot->element;
if(sroot->nwChild!=NULL)
copyWapper(root->nwChild,sroot->nwChild);
if(sroot->neChild!=NULL)
copyWapper(root->neChild,sroot->neChild);
if(sroot->swChild!=NULL)
copyWapper(root->swChild,sroot->swChild);
if(sroot->seChild!=NULL)
copyWapper(root->seChild,sroot->seChild);
}


Quadtree::~Quadtree()
{
dele(root);
}

//delete
void Quadtree::dele(QuadtreeNode *& sroot)
{
if(sroot!=NULL)
{
 dele(sroot->nwChild);
 dele(sroot->neChild);
 dele(sroot->swChild);
 dele(sroot->seChild);
delete sroot;
sroot=NULL;
}
}

Quadtree const & Quadtree::operator=(Quadtree const & source)
{
if(this==&source)
  return (*this);
dele(root);
if(source.root==NULL)
  root=NULL;
else
  copy(source);

return (*this);
}

void Quadtree::buildTree(BMP &source, int d)
{
dele(root);
resolution=d;
buildTreeWapper(source,root,d,0,0);
}
void Quadtree::buildTreeWapper(BMP &source, QuadtreeNode *& sroot,int num, int x, int y)
{
sroot=new QuadtreeNode();
if(num==1)
{

sroot->element.Red=source(x,y)->Red;
sroot->element.Blue=source(x,y)->Blue;
sroot->element.Green=source(x,y)->Green;
return;
}

buildTreeWapper(source, sroot->nwChild, num/2,x,y);
buildTreeWapper(source, sroot->neChild, num/2,x+num/2,y);
buildTreeWapper(source, sroot->swChild, num/2,x,y+num/2);
buildTreeWapper(source, sroot->seChild, num/2,x+num/2,y+num/2);
sroot->element.Red=(sroot->nwChild->element.Red+sroot->neChild->element.Red+sroot->swChild->element.Red+sroot->seChild->element.Red)/4;
 sroot->element.Blue=(sroot->nwChild->element.Blue+sroot->neChild->element.Blue+sroot->swChild->element.Blue+sroot->seChild->element.Blue)/4;
 sroot->element.Green=(sroot->nwChild->element.Green+sroot->neChild->element.Green+sroot->swChild->element.Green+sroot->seChild->element.Green)/4;

}

//getPixel
RGBApixel Quadtree::getPixel(int x, int y)
{
if(root==NULL) 
{
return RGBApixel();
}

if(resolution<=x||resolution<=y||x<0||y<0)
 return RGBApixel();

return getPixelWapper(root,x,y,resolution);
}

RGBApixel Quadtree::getPixelWapper(QuadtreeNode *sroot, int x, int y, int num)
{
//basis
if(num==1)
{
return sroot->element;
}

//recursion
if(x<num/2 && y<num/2 && sroot->nwChild!=NULL)
    return getPixelWapper(sroot->nwChild,x,y,num/2);
 else if(x<num/2 && y<num/2)
   return sroot->element;   
else if(x<num/2 && y>=num/2 && sroot->swChild!=NULL)
   return getPixelWapper(sroot->swChild,x,y-num/2,num/2);
 else if(x<num/2 && y>=num/2)
    return sroot->element;
else if(x>=num/2 && y<num/2 && sroot->neChild!=NULL)
   return getPixelWapper(sroot->neChild,x-num/2,y,num/2);
 else if(x>=num/2 && y<num/2)
   return sroot->element;
else if(sroot->seChild!=NULL)//(x>=num/2 && y>=num/2)
   return getPixelWapper(sroot->seChild,x-num/2,y-num/2,num/2);
 else 
    return sroot->element;

}


//decompress
BMP Quadtree::decompress()
{

if(root==NULL)
{
BMP temp;
return temp;
}

BMP decom;
decom.SetSize(resolution,resolution);
for(int x=0;x<resolution;x++)
for(int y=0;y<resolution;y++)
{
(decom)(x,y)->Red=getPixel(x,y).Red;
(decom)(x,y)->Blue=getPixel(x,y).Blue;
(decom)(x,y)->Green=getPixel(x,y).Green;
}

//decompress(decom,root,num,0,0);
 return decom;

}
/*
void Quadtree::decompress(BMP  &decom, QuadtreeNode *&sroot, int num, int x, int y)
{
if(num==1)
{
(decom)(x,y)->Red=sroot->element.Red;
(decom)(x,y)->Blue=sroot->element.Blue;
(decom)(x,y)->Green=sroot->element.Green;
return;
}


decompress(decom, sroot->nwChild,num/2,x,y);
decompress(decom, sroot->neChild,num/2,x+num/2,y);
decompress(decom, sroot->swChild,num/2,x,y+num/2);
decompress(decom, sroot->seChild,num/2,x+num/2,y+num/2);

}
*/
//mp5.2
void Quadtree::clockwiseRotate()
{
if(root==NULL)
return;
clockwiseRotateWapper(root);
}

void Quadtree::clockwiseRotateWapper(QuadtreeNode *&root)
{
if(root->nwChild==NULL)
return;
QuadtreeNode *temp=root->nwChild;
root->nwChild=root->swChild;
root->swChild=root->seChild;
root->seChild=root->neChild;
root->neChild=temp;
clockwiseRotateWapper(root->nwChild);
clockwiseRotateWapper(root->neChild);
clockwiseRotateWapper(root->swChild);
clockwiseRotateWapper(root->seChild);

}
void Quadtree::prune(int t)
{
pruneWapper(root, t);

}

void Quadtree::pruneWapper(QuadtreeNode *&root, int t)
{
if(root==NULL)
return;
bool temp=pruneRoot(root, t,root->element);
if(temp==true)
{
pruneChild(root->nwChild);
pruneChild(root->neChild);
pruneChild(root->swChild);
pruneChild(root->seChild);
}

pruneWapper(root->nwChild, t);
pruneWapper(root->neChild, t);
pruneWapper(root->swChild, t);
pruneWapper(root->seChild, t);

}

bool Quadtree::pruneRoot(QuadtreeNode *&root, int t, RGBApixel elem)
{

if(root==NULL)
return true;
int diff=(root->element.Red-elem.Red)*(root->element.Red-elem.Red)+(root->element.Green-elem.Green)*(root->element.Green-elem.Green)+(root->element.Blue-elem.Blue)*(root->element.Blue-elem.Blue);

if(diff<=t)
{
return
pruneRoot(root->nwChild,t, elem)&&
pruneRoot(root->swChild,t, elem)&&
pruneRoot(root->neChild,t, elem)&&
pruneRoot(root->seChild,t, elem);

}
return false;
}

void Quadtree::pruneChild(QuadtreeNode *&root)
{
if(root!=NULL)
{
pruneChild(root->nwChild);
pruneChild(root->neChild);
pruneChild(root->swChild);
pruneChild(root->seChild);

delete root;
root=NULL;
}
}
int Quadtree::pruneSize(int t)
{
return pruneSizeWapper(root,t);

}

int Quadtree::pruneSizeWapper(QuadtreeNode *&root, int t)
{
if(root==NULL) return 0;
bool temp=pruneRoot(root, t, root->element);
if(temp==true) return 1;

int nw=pruneSizeWapper(root->nwChild, t);
int ne=pruneSizeWapper(root->neChild, t);
int sw=pruneSizeWapper(root->swChild, t);
int se=pruneSizeWapper(root->seChild, t);

return nw+ne+sw+se;
}

int Quadtree::idealPrune(int numLeaves)
{  
   int max = 195075;// (255*255 + 255*255 + 255*255)
   int num = 0;
   if (numLeaves>=total(root))
      return 0;
   else
   { 
      while (max>1)
      {
         max=max/2;
         if (pruneSize(num)>numLeaves)
            num+= max;
         else 
            num-=max;
      }
      for (int i=-17;i<17;i++)
         if (this->pruneSize(num+i)<=numLeaves)
            return num+i;
   }
}

int Quadtree::total(QuadtreeNode *&root)
{
   int size = 1;
   if(root->nwChild != NULL)
      size = total(root->swChild) + total(root->neChild)+ total(root->swChild) + total(root->seChild);
   return size;
}




/*int Quadtree::idealPrune(int numLeave)
{
int temp=idealPruneWapper(root, numLeave);

}

int Quadtree::idealPruneWapper(QuadtreeNode *&root, int numLeave)
{
if(root==NULL) return 1000000;
int num=pruneSizeWapper(root,diff(root));
if(num>numLeave)
 num=1000000;
int difference=diff(root);
QuadtreeNode *temp=root;
int diff0=idealPruneSearch(root,root,num,difference,numLeave);

}

int Quadtree::idealPruneCompare()
{
if(temp->nwChil==NULL)
 return 1000000;
int diff1=idealPruneCompare(root,temp->nwChild, num, difference, numLeave);
int diff2=idealPruneCompare(root,temp->neChild, num, difference, numLeave);
int diff3=idealPruneCompare(root,temp->swChild, num, difference, numLeave);
int diff4=idealPruneCompare(root,temp->seChild, num, difference, numLeave);

if(diff1>=diff&&diff1>=diff)

}

int Quadtree::idealPruneSearch(QuadtreeNode *&root, QuadtreeNode *&temp, int num, int difference, int numLeave)
{
if(root==NULL) return 1000000;
int numNw=pruneSizeWapper(root,diff(temp->nwChild));
if(numNw>numLeave)
 numNw=1000000;
int numNe=pruneSizeWapper(root,diff(temp->neChild));
if(numNe>numLeave)
 numNe=1000000;
int numSw=pruneSizeWapper(root,diff(temp->swChild));
if(numSw>numLeave)
 numSw=1000000;
int numSe=pruneSizeWapper(root,diff(temp->seChild));
if(numSe>numLeave)
 numSe=1000000;

if(num>numNw)
 { num=nunNw;
   differece=diff(temp->nwChild);
 }
if(num>numNe)
 {
  num=numNe;
  differece=diff(temp->neChild);
 }
if(num>numSw)
{
  num=numSw;
  differece=diff(temp->swChild);
}
if(num>numSe)
{
  num=numSe;
  differece=diff(temp->seChild);
}

return difference;

}

int Quadtree::diff(QuadtreeNode *&root)
{
int diff=(root->element.Red-elem.Red)*(root->element.Red-elem.Red)+(root->element.Green-elem.Green)*(root->element.Green-elem.Green)+(root->element.Blue-elem.Blue)*(root->element.Blue-elem.Blue);

return diff;
}
*/


/**** Testing/grading functions ****/


// printTree (public interface)
//   - parameters: none
//   - prints the contents of the Quadtree using a preorder traversal
void Quadtree::printTree() const {
   if (root == NULL)
      cout << "Empty tree.\n";
   else
      printTree(root, 1);
}


// operator<< (not a member function)
//   - parameters: ostream & - output stream to be used for output
//                 RGBApixel const & pixel - pixel to be output
//   - prints the contents of the given RGBApixel to the given output stream
ostream & operator<<(ostream & out, RGBApixel const & pixel) {
   out << "(" << (int) pixel.Red << "," << (int) pixel.Green 
       << "," << (int) pixel.Blue << ")";
   return out;
}


// printTree (private helper)
//   - parameters: QuadtreeNode *current - pointer to the root of the
//                    subQuadtree which we wish to print
//                 int level - the current recursion depth; used for
//                    determining when to terminate recursion (see note below)
//   - prints the leaves of the Quadtree using a preorder traversal
void Quadtree::printTree(QuadtreeNode const * current, int level) const {
   // Is this a leaf?
   // Note: it suffices to check only one of the child pointers,
   // since each node should have exactly zero or four children.
   if (current->neChild == NULL) {
      cout << current->element << " at depth " << level << "\n";
      return;
   }

   // This clause added for the sake of grading; we will never call
   // printTree() on quadtrees larger than  512x512.  (This is a
   // necessary restriction, as the grading scripts choke on programs
   // which produce excessive amounts of output.)
   if (level > 7) {
      cout << "Error: infinite loop detected in printTree();"
           << " quadtree has a loop.\n";
      cout << "Aborting program.\n";
      exit(1);
   }

   // Standard preorder traversal
   printTree(current->neChild, level + 1);
   printTree(current->seChild, level + 1);
   printTree(current->swChild, level + 1);
   printTree(current->nwChild, level + 1);
   return;
}


// operator==
//   - parameters: Quadtree const & other - reference to a const Quadtree
//                    object, against which the current Quadtree will be
//                    compared
//   - return value: a boolean which is true if the Quadtrees are deemed
//        "equal", and false otherwise
//   - compares the current Quadtree with the parameter Quadtree, and
//        determines whether or not the two are the same
// Note: this method relies on the private helper method compareTrees()
bool Quadtree::operator==(Quadtree const & other) const {
   return compareTrees(root, other.root);
}


// compareTrees
//   - parameters: QuadtreeNode const * firstPtr - pointer to the root
//                    of a subtree of the "first" Quadtree under
//                    consideration
//                 QuadtreeNode const * secondPtr - pointer to the root
//                    of a subtree of the "second" Quadtree under
//                    consideration
//   - return value: a boolean which is true if the subQuadtrees are deemed
//        "equal", and false otherwise
//   - compares the subQuadtree rooted at firstPtr with the subQuadtree
//        rooted at secondPtr, and determines whether the two are the same
//   - this function only compares the leaves of the trees, as we did not
//     impose any requirements on what you should do with interior nodes
bool Quadtree::compareTrees(QuadtreeNode const * firstPtr,
                            QuadtreeNode const * secondPtr) const {
   if (firstPtr == NULL && secondPtr == NULL)
      return true;

   if (firstPtr == NULL || secondPtr == NULL)
      return false;

   // if they're both leaves, see if their elements are equal
   // note: child pointers should _all_ either be NULL or non-NULL,
   // so it suffices to check only one of each
   if (firstPtr->neChild == NULL && secondPtr->neChild == NULL) {
      if (firstPtr->element.Red != secondPtr->element.Red ||
         firstPtr->element.Green != secondPtr->element.Green ||
         firstPtr->element.Blue != secondPtr->element.Blue)
         return false;
      else
         return true;
   }

   // they aren't both leaves, so recurse
   return (compareTrees(firstPtr->neChild, secondPtr->neChild) &&
           compareTrees(firstPtr->nwChild, secondPtr->nwChild) &&
           compareTrees(firstPtr->seChild, secondPtr->seChild) &&
           compareTrees(firstPtr->swChild, secondPtr->swChild));
}
















///////////////////////////////////////////////////////////////////////////












































// **************************************************************
// *                                                            *
// *  quadtree.cpp                                              *
// *                                                            *
// *  A quadtree class                                          *
// *                                                            *
// *  CS 225 Fall 2006                                          *
// *                                                            *
// **************************************************************

#include "quadtree.h"

//const
Quadtree::Quadtree()
:root(NULL),dis(0)
{}


//const

Quadtree::Quadtree(const BMP & source, int d)
{
dis=d;
RGBApixel BBQ;
root=new QuadtreeNode;
buildT(source, d);

}

void Quadtree::Printdis()
{
cout<<"the distance is  "<<dis<<endl;
}


// tooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo

void Quadtree::buildT(const BMP & source, int d)
{

RGBApixel BBQ;

dis=d;


if(dis!=1) 
{realbuild(source, dis, root, 0, 0, BBQ);
 avg(root,d);
}
else if(dis==1) 
{
(root->element).Red=source(0,0)->Red;
(root->element).Green=source(0,0)->Green;
(root->element).Blue=source(0,0)->Blue;
setchildren0(root);

}
}



//buildtree
void Quadtree::buildTree(const BMP & source, int d)
{

RGBApixel BBQ;

 clear(root);

 dis=d;


root=new QuadtreeNode;


if(dis!=1) 
{realbuild(source, dis, root, 0, 0, BBQ);
 
 avg(root,d);
}
else if(dis==1) 
{
(root->element).Red=source(0,0)->Red;
(root->element).Green=source(0,0)->Green;
(root->element).Blue=source(0,0)->Blue;
setchildren0(root);

}
}

/*
void Quadtree::avg(QuadtreeNode* subroot)
{
if(subroot->nwChild==NULL) return;
avg(subroot->nwChild);
avg(subroot->neChild);
avg(subroot->swChild);
avg(subroot->seChild);

subroot->element.Red = ((subroot->nwChild)->element.Red+ (subroot->neChild)->element.Red+ (subroot->seChild)->element.Red+( subroot->swChild)->element.Red)/4;
subroot->element.Green = ((subroot->nwChild)->element.Green+ (subroot->neChild)->element.Green+ (subroot->seChild)->element.Green+ (subroot->swChild)->element.Green)/4;
subroot->element.Blue = ((subroot->nwChild)->element.Blue+ (subroot->neChild)->element.Blue+ (subroot->seChild)->element.Blue+ (subroot->swChild)->element.Blue)/4;

}
*/


void Quadtree::avg(QuadtreeNode* subroot, int d)
{  if(d<=1)
   {
    return;
   }
   else{
 
   avg(subroot->nwChild,d/2);
   avg(subroot->neChild,d/2);
   avg(subroot->seChild,d/2);
   avg(subroot->swChild,d/2);
   subroot->element.Red = ((subroot->nwChild)->element.Red+(subroot->neChild)->element.Red+(subroot->seChild)->element.Red+(subroot->swChild)->element.Red)/4;
   subroot->element.Green = ((subroot->nwChild)->element.Green+(subroot->neChild)->element.Green+(subroot->seChild)->element.Green+(subroot->swChild)->element.Green)/4;
   subroot->element.Blue = ((subroot->nwChild)->element.Blue+(subroot->neChild)->element.Blue+(subroot->seChild)->element.Blue+(subroot->swChild)->element.Blue)/4;
   }
  
 
}







//real...................................................................................

void Quadtree::realbuild(const BMP & source, int d, QuadtreeNode* subroot, int x, int y, RGBApixel & BBQ)
{


 d=d/2;
 subroot->nwChild=new QuadtreeNode;
 subroot->neChild=new QuadtreeNode;
 subroot->swChild=new QuadtreeNode;
 subroot->seChild=new QuadtreeNode;

  
if(d>1)
{
 
 realbuild(source, d, subroot->nwChild, x, y, BBQ);

// cout<<BBQ.Red<<"  ";

 realbuild(source, d, subroot->neChild, x+d, y, BBQ);


// cout<<BBQ.Red<<"  ";

 realbuild(source, d, subroot->swChild, x, y+d,BBQ);

// cout<<BBQ.Red<<"  ";

 realbuild(source, d, subroot->seChild, x+d, y+d,BBQ);

 //cout<<BBQ.Red<<endl;



 
 }
 if(d<=1)
{
 (subroot->nwChild->element).Red=(*source(x,y)).Red;
(subroot->nwChild->element).Blue=(*source(x,y)).Blue;
(subroot->nwChild->element).Green=(*source(x,y)).Green;
 
 (subroot->neChild->element).Red=(*source(x+d,y)).Red;
 (subroot->neChild->element).Green=(*source(x+d,y)).Green;
 (subroot->neChild->element).Blue=(*source(x+d,y)).Blue;

 (subroot->swChild->element).Red=(*source(x,y+d)).Red;
 (subroot->swChild->element).Green=(*source(x,y+d)).Green;
 (subroot->swChild->element).Blue=(*source(x,y+d)).Blue;


 (subroot->seChild->element).Red=(*source(x+d,y+d)).Red;
 (subroot->seChild->element).Green=(*source(x+d,y+d)).Green;
 (subroot->seChild->element).Blue=(*source(x+d,y+d)).Blue;



setchildren0(subroot->nwChild);
setchildren0(subroot->neChild);
setchildren0(subroot->swChild);
setchildren0(subroot->seChild);

return;

}
}






void Quadtree::setchildren0(QuadtreeNode* subroot)
{ 
subroot->nwChild=NULL;
subroot->neChild=NULL;
subroot->swChild=NULL;
subroot->seChild=NULL;

}




//BIG THREE

//1. copy constructor*img(x,y)=



Quadtree::Quadtree(const Quadtree & rhs)
{
	dis=rhs.dis;
 if (rhs.root==NULL) root = NULL;
 else
  {
  // root = new QuadtreeNode;
   root = copy(rhs.root);
  }
}



/*Quadtree::Quadtree * Quadtree::copy(Quadtree & other)
{
dis=other.dis;
if(other.root==NULL) return NULL;

root=new QuadtreeNode;

root=copy(other.root);
return this;

}
*/

 Quadtree:: QuadtreeNode * Quadtree::copy(QuadtreeNode *const& subRoot)
{


	// Copy this node and it's children	
   if(subRoot==NULL) return NULL;
	QuadtreeNode * newNode = new QuadtreeNode();
   newNode->element=subRoot->element;
   //newNode=subRoot;
	newNode->nwChild  = copy(subRoot->nwChild );
	newNode->neChild =  copy(subRoot->neChild );
 	newNode->swChild  = copy(subRoot->swChild );
	newNode->seChild =  copy(subRoot->seChild ); 
	return newNode;
}



//2. operator

Quadtree const & Quadtree::operator=(Quadtree const  & rhs)
{
   if(this== &rhs) return (*this);
 

	clear(root);
   if(rhs.root==NULL) root=NULL;
   else{
	//Quadtree();
     dis=rhs.dis;
		root = copy(rhs.root);
	 //if(root==NULL) return img;
   }
     
	return (*this);
}


/*
Quadtree const & Quadtree::operator=(Quadtree const & source)
{

if(this==&source)
  return (*this);
clear(root);
if(source.root==NULL)
  root=NULL;
else
  {root=copy(source.root);
   dis=source.dis;
  }

return (*this);
}
*/







//3. destructor
Quadtree::~Quadtree()
{
clear(root);
}


//clear
void Quadtree::clear(QuadtreeNode* subRoot)
{
   if (subRoot == NULL) return;
	
	clear(subRoot->nwChild);
	clear(subRoot->neChild);
	clear(subRoot->swChild);
	clear(subRoot->seChild);
	delete subRoot;
   subRoot=NULL;

}

//................................


/*
RGBApixel  Quadtree::getPixel(int x,int y)
{  return getPixelhelper( x, y, dis,root)->element;
  
}

Quadtree:: QuadtreeNode* Quadtree::  getPixelhelper(int x, int y,int d, QuadtreeNode* subroot)
{ int midx = d/2;
 int midy = d/2;
 d=d/4;
while(subroot->neChild!=NULL)
{ 
  
  if(x<midx&&y<midy)
   {subroot = subroot->nwChild;
   midx = midx-d;
   midy = midy-d;}
        
  else if(x>=midx&&y<midy)
  {subroot = subroot->neChild;
  midx = midx+d;
  midy = midy-d;}

  else if(x<midx&&y>=midy)
  {subroot = subroot->swChild;
  midx = midx-d;
  midy = midy+d;}

  else if(x>=midx&&y>=midy)
  {subroot = subroot->seChild;
  midx = midx+d;
  midy = midy+d;} 
  d=d/2;
}
 return subroot;}

*/


//getpixel

RGBApixel Quadtree::getPixel(int x, int y)
{
 int d=dis;
 int xx=0;
 int yy=0;
 RGBApixel A;
 if(x>=d || y>=d || x<0 || y<0 || root==NULL) return RGBApixel();
 gotu(x, y, dis, root, A);
 return A; 
}



void Quadtree::gotu(int x, int y, int d, QuadtreeNode* subroot, RGBApixel & B)
{
/*
if(subroot->nwChild==NULL) 
{
B=subroot->element;
return ;
}
*/
//if(d!=0)
{
	if(xx==x && yy==y) 
 {
	B.Red=(subroot->element).Red;
	B.Green=(subroot->element).Green;
	B.Blue=(subroot->element).Blue;
  return;
 }






	if( (x< (xx+d/2) && x>=xx) && (y<(yy+d/2) && y>=yy) ) 
    gotu(x, y, d/2, subroot->nwChild, xx, yy, B);
  
   if( (x<(xx+d) && x>=(xx+d/2)) && (y<(yy+d/2) && y>=yy) ) 
    gotu(x, y, d/2, subroot->neChild, xx+d/2, yy, B);

   if( (x<(xx+d/2) && x>=xx) && (y<(yy+d) && (y>=(yy+d/2))) ) 
    gotu(x, y, d/2, subroot->swChild, xx, yy+d/2, B);

	 if( (x<(xx+d) && x>=(xx+d/2)) && (y<(yy+d) && (y>=(yy+d/2))) ) 
    gotu(x, y, d/2, subroot->seChild, xx+d/2, yy+d/2, B);
  
}


}







BMP Quadtree::decompress()
{
 int d=dis;
 int x=0;
 int y=0;
 BMP img;

 img.setSize(dis, dis);
 if(root==NULL) return img;
 
 for(int i=0; i<d; i++)
{for(int j=0; j<d; j++)
 {
 (*img(i,j)).Red=getPixel(i,j).Red;
 (*img(i,j)).Green=getPixel(i,j).Green;
 (*img(i,j)).Blue=getPixel(i,j).Blue;
 }
}
 
 return img;

}






 void Quadtree::clockwiseRotate()
{
if(root!=NULL)
clock(root);
}


 void Quadtree::clock(QuadtreeNode* subroot)
{
 if (subroot==NULL) return;
if(subroot->nwChild!=NULL)
{
QuadtreeNode* A;
QuadtreeNode* B;
QuadtreeNode* C;
QuadtreeNode* D;

A=subroot->nwChild;
B=subroot->neChild;
C=subroot->swChild;
D=subroot->seChild;

subroot->nwChild=C;
subroot->neChild=A;
subroot->swChild=D;
subroot->seChild=B;

clock(A);
clock(B);
clock(C);
clock(D);
}
 
}



//prune goes here
	void Quadtree::prune(int i)
{
	
  prunehelp(i,root);


}





















   void Quadtree::prunehelp(int i, QuadtreeNode* subroot)
{
   if(subroot->nwChild==NULL) return;

   
   bool tol=false;
   RGBApixel top;
   top=subroot->element;
   gettol(subroot,i, tol, top);
   // tol=compare(subroot->nwChild, subroot->neChild, 
   //       subroot->swChild, subroot->seChild, i);

   if(tol==false) 
   {
clear(subroot->nwChild);
subroot->nwChild=NULL;
clear(subroot->neChild);
subroot->neChild=NULL;
clear(subroot->swChild);
subroot->swChild=NULL;
clear(subroot->seChild);
subroot->seChild=NULL;
return;
 
}
	prunehelp(i,subroot->nwChild);
	prunehelp(i,subroot->neChild);
	prunehelp(i,subroot->swChild);
	prunehelp(i,subroot->seChild);
return;
  
}


void  Quadtree::gettol(QuadtreeNode* subroot, int i, bool & tol, RGBApixel & top )
{
if(subroot->nwChild==NULL) 
{
 int d;
 d=getdif(subroot->element, top);
 if(d>i) tol=true;
}
else{
gettol(subroot->nwChild, i, tol, top);
gettol(subroot->neChild, i, tol, top);
gettol(subroot->swChild, i, tol, top);
gettol(subroot->seChild, i, tol, top);
return;
}


}







bool  Quadtree::compare(QuadtreeNode* nw, QuadtreeNode* ne, QuadtreeNode* sw, QuadtreeNode* se, int i)
{
int dnw, dne, dsw, dse ;
RGBApixel total;
total=average(nw, ne, sw, se);

 dnw=getdif(nw->element, total);
 dne=getdif(ne->element, total);
 dsw=getdif(sw->element, total);
 dse=getdif(se->element, total);

 if(dnw<=i && dne<=i && dsw<=i && dse<=i)
return true;
 else return false;
}

//get average
RGBApixel Quadtree::average(QuadtreeNode* nw, QuadtreeNode* ne, QuadtreeNode* sw, QuadtreeNode* se)
{
RGBApixel BBQ;
BBQ.Red=( (nw->element).Red+(ne->element).Red+ (sw->element).Red + (se->element).Red )/4;
BBQ.Green=( (nw->element).Green+(ne->element).Green+ (sw->element).Green + (se->element).Green )/4;
BBQ.Blue=( (nw->element).Blue+(ne->element).Blue+ (sw->element).Blue + (se->element).Blue )/4;
return BBQ;
}


int Quadtree::getdif(RGBApixel ta, RGBApixel  total)
{
 int x;
 x=pow(ta.Red-total.Red,2)+pow(ta.Green-total.Green,2)+pow(ta.Blue-total.Blue,2);
 return x;
}



   int Quadtree::pruneSize(int i)
{
int a=0;
size(i, root, a);
return a;
}




   void Quadtree::size(int i, QuadtreeNode* subroot, int & a)
{
   if(subroot->nwChild==NULL) 
   { a++;
   return;
}
   
   bool tol=false;
   RGBApixel top;
   top=subroot->element;
   gettol(subroot,i, tol, top);
   // tol=compare(subroot->nwChild, subroot->neChild, 
   //       subroot->swChild, subroot->seChild, i);

   if(tol==false) 
   {
   a++;
   return;
 
}
	size(i,subroot->nwChild,a);
	size(i,subroot->neChild,a);
	size(i,subroot->swChild,a);
	size(i,subroot->seChild,a);
return;
  
}









   int Quadtree::idealPrune(int i)
{
 int x=search(0,105075,i);
 while(pruneSize(x)==i) x=x-1;
 x=x+1;
 
return x;
}

   int Quadtree::search(int low, int high, int x)
{
int mid=(low+high)/2;
if(pruneSize(mid)>x) return search(mid+1, high, x);
else if(pruneSize(mid)<x) return search(low, mid-1, x);
else return mid;
}
	

















