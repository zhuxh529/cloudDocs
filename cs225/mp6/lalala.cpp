

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
	int S;
   S=points.size();
   Point<Dim> tar;
   double dis;
  tar=fun(a ,0 ,0 , S-1, dis);
	return tar; // Replace with your code
}

// define KDTree helper functions here



template<int Dim>
Point<Dim> KDTree<Dim>::fun(const Point<Dim> & a,
             int d, int left, int right, double & dis) const
{

  if(left!=right)
{
   int median=(left+right)/2;
	double x;



//when goes to right
   if(a[d]>points[median][d]) 
   {
	Point<Dim> tar;
	tar=fun(a, (d++)%Dim, median+1, right, dis);
	x=pow((a[d]-points[median][d]),2);

    //if current distance is bigger than previous one
   double tempd=0;
   for(int i=0; i<Dim; i++)
		{ tempd=tempd+pow(a[i]-points[median][i],2);
		}   
   if(tempd>dis) dis=tempd;
   
   //judge if we should go to the subtree in the other side
   if(x<0) cout<<"x is smaller than 0"<<endl;
   if(dis< x) return tar;
	else{	tar=fun(a, (d++)%Dim, left, median-1, dis); 
		  return tar;
       }  
   }
   
//when goes to left

   else//(a[d]<points[median][d]) 
   {
	Point<Dim> tar;
	tar=fun(a, (d++)%Dim, left, median-1, dis);

   x=pow((a[d]-points[median][d]),2);

    //if current distance is bigger than previous one
   double tempd=0;
   for(int i=0; i<Dim; i++)
		{ tempd=tempd+pow(a[i]-points[median][i],2);
		}   
   if(tempd>dis) dis=tempd;
   
   //judge if we should go to the subtree in the other side
   if(x<0) cout<<"x is smaller than 0"<<endl;
   if(dis< x) return tar;
	else{	tar=fun(a, (d++)%Dim, median+1 ,right , dis); 
		  return tar;
       }
	
   }

//if equal operater <
 /*  else 
   {
   
	
	
	
   }
   */
}


//base case
   else
	{
   dis=0;
   for(int i=0; i<Dim; i++)
		{ dis=dis+pow(a[i]-points[left][i],2);
		}
	Point<Dim> tar=points[left];
	return tar;
	}
}













