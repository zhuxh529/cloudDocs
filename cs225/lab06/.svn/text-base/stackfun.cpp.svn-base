
// sum
// adds all the elements in a stack


#include <ostream>
using namespace std;

template <typename T>
T StackFun::sum(stack<T> & s)
{
    // Your code here
    if(s.size()!=0)
    {T x;
 	 x=s.top();
    s.pop();
    int c=x+sum(s);
    s.push(x);
    return c;
    }
   
    else
    return 0; // stub return value (0 for primitive types). Change this!
                // Note: T() is the default value for objects, and 0 for
                // primitive types
}

// scramble
// reorders even sized blocks of items in the queue
// blocks start at size one and increases for each subsequent block
template <typename T>
void StackFun::scramble(queue<T> & q)
{
    
    stack<T> s;
	 queue<T> q2;
    T x, y,z, w;
    T i=1;
    T j=2;
    x=0;
   while(!q.empty()){ 
//111111111111111111111111111111111
      z=q.front();
     cout <<"j is  ="<<j<<endl;
     cout <<"i is  ="<<i<<endl;
      if(z!=i)
		{
      x=(int)q.size();
      if(x>=(j-1)){
      for(int a=i; a< (i+j-1);a++)
      {
      y=q.front();
		q.pop();
 		q2.push(y);
      }
		}
      else if(x<(j-1)){
      y=(int)q.size();
      for(int a=i; a< (i+j-1);a++)
      {
      y=q.front();
		q.pop();
 		q2.push(y);
      }
   	}}
	  
//22222222222222222222222222222222222222
		if(z==i){
      cout <<"i(secend) is  ="<<i<<endl;
      cout <<"j(secend) is  ="<<j<<endl;
       x=(int)q.size();
      cout<<"the size is "<<x<<endl;
   	if(x>=j){
      
    
      for(int a=i; a<(i+j);a++){
      y=q.front();
		q.pop();
 		
     s.push(y);
     }
     for(int a=i; a<(i+j);a++){
     y=s.top();
     s.pop();
     q2.push(y);
	   }
		}

    
     else if(x<j){
   
     w=q.size();
     for(int a=i; a<(i+w);a++){
      y=q.front();
		q.pop();
      s.push(y);
     }
     for(int a=i; a<(i+w);a++){
     y=s.top();
     s.pop();
     q2.push(y);
	   }
     }

     i=i+2*j+1;
 	  j=j+2;
    
   
   } 

  

    // Your code here
}

   while(!q2.empty())
{
 	 y=q2.front();
	 q2.pop();	
     q.push(y);
}

}

// verifySame
template <typename T>
bool StackFun::verifySame(stack<T> & s, queue<T> & q)
{
   
     T lala; // lala is for temperary front element of queue
     T lolo; // lolo is for temperary top element of stack
   
//if not base case
if(!s.empty()){ 
	 //pop out stack one by one
   lolo=s.top();
   s.pop();

   
   //if previous element is equal
	if(verifySame(s,q)) 
   {
     //pop out queue one by one and push it at front of the queue
    lala=q.front();
    q.pop();
    q.push(lala);
   //push back stack
    s.push(lolo);
    if(lala==lolo)
    return true;
    else return false;
   }
   //if previous element is not equal
   else{
   //pop out queue one by one and push it at front of the queue
	 s.push(lolo);
    lala=q.front();
    q.pop();
   //push back stack
    q.push(lala);
    return false;
   }}


//if it's nase case
   else if(s.empty()) return true;
}















