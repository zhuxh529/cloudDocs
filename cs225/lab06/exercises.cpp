#include "exercises.h"

int sumDigits(int n)
{
	/*if(n!=0)
   {
	int m;
   m=n%10;
   
   
   n=n/10;
   m=(sumDigits(n)+m);
   return m;
   }
   else 
   { int sum=0;
    return sum;; // Replace this with your code
}
*/


   if(n==0) return 0;
   else
{
int m=n%10;
n=n/10;
 return m+sumDigits(n);


}


}

int triangle(int rows)
{
   if(rows==0)
	return 0; // Replace this with your code



   else
   {

    return triangle(rows-1)+rows;
   }
}
