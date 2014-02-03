#include <iostream>
#include <algorithm>


using namespace std;






// MinHeap
//	 - constructor 
//	 - inserts oneDatum into array vector 
//	 - initializes size to 1
template <class T>
void buildHeap(vector<T> & array)
{
	// Your code here
	int S=array.size();
	/*for(int i=parent(array, S-1);i>=0;i--)
	   {//gobuild(array,i, S);
     heapifyDown(array, i);
*/

  for(int i=1; i<S; i++)
{
heapifyUp(array, i);
}


}}

template <class T>
void gobuild(vector<T> & array, int i, int size)
{
	bool jixu=true;
   // int minChild;
	int right, left, min;
   
	
	//if(right>=S) minChild=left;

  // minChild=(array[right]<array[left])?right:left;
  if(i>=size || i>=size/2) return;
	for(int k=0;(k+1)<=(size/2);k++)
   {
	right=rightChild(array, k );
	left=leftChild(array, k );
	if(array[k]>array[right] || array[k]>array[left])
	{jixu=false;
	break;
   }
	}

   if(jixu==true) return;
	//if(i>=size) return;
 
	right=rightChild(array, i );
	left=leftChild(array, i );
   

	if(left<size && array[i]>array[left])
   {min=left;}

   else min=i;
 
   if(right<size && array[min]>array[right])
   min=right;

   T r, l, me;
   r= array[right];
	l=array[left];
	me=array[i];
   //cout<<i<<"  "<<left<<"  "<<right<<endl ;
  // cout<< "left=" << l << endl;
	//cout<< "right=" << r << endl;

	if(min!=i) {
	swap(array[i], array[min]);
	
	gobuild(array, min, size);}



}




// removeMin
//	- returns an element of type T that is the least
//	  element in the heap.  
//	- removes that element from the heap and reheapifies 
template <class T>
T removeMin(vector<T> & array)
{
	if (array.empty())
	{
		std::cout << "empty heap" << std::endl;
		return T();
	}

	T temp = array[0];
	array[0] = array.back();
	array.pop_back();
	heapifyDown(array, 0);
	return temp;
}


// insert
//	- insElem - the item to be inserted into the minHeap
//	- performs the insert and reheapifies
template <class T>
void heapInsert(vector<T> & array, T const & insElem)
{
	array.push_back(insElem);
	heapifyUp(array, array.size()-1);
}


// heapifyDown
//  - helper function traverses tree restoring heap property
template<class T>
void heapifyDown(vector<T> & array, int cIndex)
{
	// Your code here
   int S=array.size();
   int minChild;
	int right, left;
   
	right=rightChild(array, cIndex );
	left=leftChild(array, cIndex );
	//if(right>=S) minChild=left;

   minChild=minchild(array, cIndex);

	if(2*(cIndex+1)-1< S)
 {
	if(array[cIndex]>array[minChild])
	{
	swap(array[cIndex],array[minChild]);
	heapifyDown(array, minChild);
	}
 }
	
}

// heapifyUp
//  - helper function traverses tree restoring heap property
template<class T>
void heapifyUp(vector<T> & array, int cIndex)
{
	if (cIndex > 0)
	{
		int tempParent = parent(array, cIndex);
		if (array[cIndex] < array[tempParent])
		{
			swap(array[cIndex], array[tempParent]);
			heapifyUp(array, tempParent);
		}
	}
}

// parent
//  - returns the index of the parent of cIndex
template<class T>
inline int parent(const vector<T> & array, int cIndex)
{
	return (cIndex+1)/2-1;
}


// rightChild 
//  - returns the index of the right child of cIndex
template<class T>
inline int rightChild(const vector<T> & array, int cIndex)
{
	return 2*(cIndex+1);
}

// leftChild 
//  - returns the index of the left child of cIndex
template<class T>
inline int leftChild(const vector<T> & array, int cIndex)
{
	return 2*(cIndex+1)-1;
}

// print
//  - prints out the heap's array
template<class T>
void print(const vector<T> & array)
{
	std::cout << "[ ";
	for (unsigned int i = 0; i < array.size(); i++)
		std::cout << array[i] << ' ';
	std::cout << ']';
}


template<class T>
inline int minchild(const vector<T> & array, int cIndex)
{
int x;
int r, l;
r=rightChild(array, cIndex);
l=leftChild(array, cIndex);

x=array[r]<array[l]?r:l;
return x;
}




