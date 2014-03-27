   
#include "dsets.h"

//add element
void DisjointSets::addelements(int n)
{
int S=body.size();

for(int i=S; i<(S+n); i++)
{
body.push_back(-1);
}

}

//find
int DisjointSets::find(int n)
{
if(body[n]<0) return n;
else return find(body[n]);

}

//setunion goes here
void DisjointSets::setunion(int n1, int n2)
{
	int newsize;
  if (body[n1]>=0) n1=find(n1);
  if (body[n2]>=0) n2=find(n2);

  //if(body[n1]<0 && body[n2]<0){
  //get the new size of the tree
  newsize=body[n1]+body[n2];	

 //compare
  if((-body[n1])<(-body[n2]))
 {
  body[n1]=n2;
  body[n2]=newsize;
 }
 else //reverse
 {
  body[n2]=n1;
  body[n1]=newsize;
 }
// }



}
