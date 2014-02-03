/* kdtree.cpp
 * Implementation of KDTree class
 *	 			
 * Written by Cinda Heeren for CS225 MP6
 * Spring 2009
 * Revision history:
 * 3/31/2009        Created
 * Spring 2011      Modified by Jack Toole
*/

template<int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim> & a, const Point<Dim> & b, int d) const
{
	// Your code here

    if(a[d]<b[d]) return true;
    else if(a[d]>b[d]) return false;
    else return a<b;
    return true;
	

}


template<int Dim>
//template <typename T>
bool KDTree<Dim>::shouldReplace(const Point<Dim> & target, const Point<Dim> & currentBest, const Point<Dim> & potential) const
{
	// Your code here

   double dis_p=0;
   double dis_c=0;
   for(int i=0; i<Dim; i++)
	{dis_p=dis_p+pow((target[i]-potential[i]),2);
    dis_c=dis_c+pow((target[i]-currentBest[i]),2);
	}
  
   if(dis_p<dis_c) return true;
   else if(dis_p>dis_c) return false;
   else return potential<currentBest;

}





template<int Dim>
KDTree<Dim>::KDTree(const vector< Point<Dim> > & newPoints)
{
	// Your code here
   points=newPoints;
   if(!point_index.empty()) point_index.clear();

	int S;
   S=newPoints.size();
	for(int i=0; i<S;i++) 
{
 point_index.push_back(i);
}

  BUILD( point_index, 0, S-1, 0);

}


template<int Dim>
void KDTree<Dim>::BUILD( vector<int> & index, int left, int right, int d)
{
 if(left<right)
 {
  
  int median=left+(right-left)/2;
  int x=select(index, left, right, median, d);
  
  BUILD(index, left, median-1, (d+1)%Dim);
  BUILD(index, median+1, right,(d+1)%Dim);
 }
}



template<int Dim>
int KDTree<Dim>::select( vector<int> & index, int left, int right, const int median, int d)
{
if(left==right) return index[left];
//median=(right+left)/2;

int pivot=partition(index, left, right, median, d);

if(pivot==median)
 return index[median];
else if(median< pivot)
 return select( index, left, pivot-1, median, d);
else return select( index, pivot+1,right, median, d);

}


template<int Dim>
//template <typename T>
int KDTree<Dim>::partition( vector<int> & index, int left, int right, int pivot, int d)
{
double pivotvalue=points[index[pivot]][d];
int store=left;
swap(index[pivot], index[right]);

for(int i=left; i<right ;i++)
 {
  if(points[index[i]][d]<pivotvalue)
	{
	swap(index[i], index[store]);
   store++;
	}
        if(points[index[i]][d]==pivotvalue)
          {
			if(points[index[i]]<points[index[right]])
   		 {
				swap(index[i], index[store]);
  				 store++;
 			  }
 			 }
 }
swap(index[right], index[store]);
return store;

}


template<int Dim>
void KDTree<Dim>::swap(int &r,int &l )
{
  if(r==l) return;
  int temp=r;
  r=l;
  l=temp;
}






template<int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim> & a) const
{

  /* vector<int> index;
   if(!index.empty()) index.empty();
   int S;
   S=points.size();
	for(int i=0; i<S;i++) 
 {
 index.push_back(i);
 }
*/
	int S, in;
   S=point_index.size();
   in=points.size();
   Point<Dim> target, ta;
   ta=points[point_index[(S-1)/2]];
   double dis=0;
   for(int i=0; i<Dim; i++)
		{ dis=dis+pow((a[i]-ta[i]),2);
		}
   
   fun(a ,0 ,0 , S-1, dis, ta);
	return ta; // Replace with your code
}

// define KDTree helper functions here



template<int Dim>
void KDTree<Dim>::fun(const Point<Dim> & a, int d, int left, int right, double & dis, Point<Dim> &ta) const
{

  if(left<right)
{
   int median=(left+right)/2;
   Point<Dim> medpoint;
   medpoint=points[point_index[median]];
	double x;



//when goes to right
   if(a[d]>medpoint[d]) 
   {
	
	fun(a, (d+1)%Dim, median+1, right, dis, ta);
	x=pow((a[d]-medpoint[d]),2);

    //if current distance is bigger than previous one
   double tempd=0;
   for(int i=0; i<Dim; i++)
		{ tempd=tempd+pow((a[i]-medpoint[i]),2);
		}   

   if(tempd<dis) 
    {dis=tempd;
    ta=medpoint;
    }
   else if(tempd==dis)
   {
    if(medpoint<ta)
    {dis=tempd;
    ta=medpoint;
    }
   }
   
   //judge if we should go to the subtree in the other side

   if(dis< x) return;
	else{	fun(a, (d+1)%Dim, left, median-1, dis, ta); 
		  return ;
       }  
   }
   
//when goes to left

   else if(a[d]<medpoint[d]) 
   {
	
	fun(a, (d+1)%Dim, left, median-1, dis, ta);

   x=pow((a[d]-medpoint[d]),2);

    //if current distance is bigger than previous one
   double tempd=0;
   for(int i=0; i<Dim; i++)
		{ tempd=tempd+pow((a[i]-medpoint[i]),2);
		}   
   if(tempd<dis) 
   {dis=tempd;
    ta=medpoint;
   }
   else if(tempd==dis)
   {
    if(medpoint<ta)
    {dis=tempd;
    ta=medpoint;
    }
   }
   //judge if we should go to the subtree in the other side

   if(dis< x) return ;
	else{	fun(a, (d+1)%Dim, median+1 ,right , dis, ta); 
		  return ;
       }
	
   }

//if equal operater <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  else 
   {
   if(a<medpoint)
    { 
   
    
		
	fun(a, (d+1)%Dim, left, median-1, dis, ta);

   x=pow((a[d]-medpoint[d]),2);

    //if current distance is bigger than previous one
   double tempd=0;
   for(int i=0; i<Dim; i++)
		{ tempd=tempd+pow((a[i]-medpoint[i]),2);
		}   

   
   if(tempd<dis) 
   {dis=tempd;
    ta=medpoint;
   }
    else if(tempd==dis)
   {
    if(medpoint<ta)
    {dis=tempd;
    ta=medpoint;
    }
   }
   //judge if we should go to the subtree in the other side

   if(dis< x) return;
	else{	fun(a, (d+1)%Dim, median+1 ,right , dis, ta); 
		  return ;
       }
    }
	

	else
   {

	fun(a, (d+1)%Dim, median+1, right, dis, ta);
	x=pow((a[d]-medpoint[d]),2);

    //if current distance is bigger than previous one
   double tempd=0;
   for(int i=0; i<Dim; i++)
		{ tempd=tempd+pow((a[i]-medpoint[i]),2);
		}   
   if(tempd<dis) 
    {dis=tempd;
    ta=medpoint;
    }
      else if(tempd==dis)
   {
    if(medpoint<ta)
    {dis=tempd;
    ta=medpoint;
    }
   }
   
   //judge if we should go to the subtree in the other side

   if(dis< x) return ;
	else{	fun(a, (d+1)%Dim, left, median-1, dis, ta); 
		  return;
       }  
   }
	
	
   }
 
}


//base case
   else //if(left==right)
	{
    Point<Dim> gotu;
    gotu=points[point_index[left]];
   
   double tempd=0;
   for(int i=0; i<Dim; i++)
		{ tempd=tempd+pow((a[i]-points[point_index[left]][i]),2);
		}
   if(tempd<dis)
   {
	dis=tempd;
	ta=points[point_index[left]];
	return ;
	}
   else if(tempd==dis)
   {
    if(gotu<ta)
    {dis=tempd;
    ta=gotu;
    }
   }
	
   else return;
   }

//if(right<left)
/*   else 
 { 
double tempd=0;
   for(int i=0; i<Dim; i++)
		{ tempd=tempd+pow((a[i]-points[point_index[left]][i]),2);
		}
   if(tempd<dis)
   {
	dis=tempd;
	ta=points[point_index[left]];
	return ;
	}
	
   else return;
 }
   */

}













