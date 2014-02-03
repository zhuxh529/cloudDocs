/**
 * Doubly Linked List (MP 3)
 * Created by Chase Geigle for CS225, Fall 2011
 * Modified by Jack Toole, Fall 2011
 */

/**
 * ~List() -- Destructor (GRADED!)
 *  - Destroys the current list, ensuring memory does not leak
 */
#include <iostream>
template <class T>
List<T>::~List()
{
   clear();
	// your code here
}

/**
 * clear() -- Private Helper
 *  - Clears the list
 */
template <class T>
void List<T>::clear()
{
   ListNode* Z;
   ListNode* Y;
   
   if(length>0)
   {
   Z=head;
	while(Z->next!=NULL)
{
Y=Z;
Z=Z->next;
delete Y;
}
    delete tail;
    tail=NULL;
    head=NULL;
    length=0;
   }
   else if(length==0)
	{tail=NULL;
	head=NULL;
	}  
   Z=NULL;
   Y=NULL;
   

   
	// your code here
}



/**
 * insertFront() -- Insertion Function (GRADED!)
 *  - Inserts a node with the parameter value into the list at the front
 */
template <class T>
void List<T>::insertFront(const T & ndata)
{
   ListNode* A= new ListNode(ndata);
   if(length>0)
  {
   A->next=head;
   head->prev=A;
   A->prev=NULL;
   head=A;
   length=length+1;
  }
   if(length==0)
  {
   head=A;
   tail=A;
   head->prev=NULL;
   head->next=NULL;
	length=1;
  }
 
   
   
	// your code here
}



/**
 * insertBack() -- Insertion Function (GRADED!)
 *  - Inserts a node with the parameter value into the list at the back
 */
template <class T>
void List<T>::insertBack(const T & ndata)
{
   ListNode* B;
   B=new ListNode(ndata);
   if(length>0)
   {
   tail->next=B;
   B->next=NULL;
   B->prev=tail;
   tail=B;
   length=length+1;
   }

	if(length==0)
  {
   head=B;
   tail=B;
   head->prev=NULL;
   head->next=NULL;
	length=1;
  }
  
 
	// your code here
}



/**
 * mixSplit() -- Splitting Function (GRADED!)
 *  - Splits the list following the mixSplit algorithm (given on the MP spec)
 */
template <class T>
List<T> List<T>::mixSplit()
{
   List<T> returned;
   ListNode* C;
	ListNode* D;
	ListNode* cc;
   ListNode* dd, *z;
   int x,y;
	
   
   if(length==0||length==1)
   {
 		return returned;
		}

   if(length==2){
     returned.head=head->next;
     returned.tail=returned.head; 
    (returned.tail)->next=NULL;
    (returned.tail)->prev=NULL;
		tail=head;
      tail->prev=NULL;
      tail->next=NULL;
      length=1;
      returned.length=1;   
      cout<<length<<" =length"<<endl;
   cout<<returned.length<<" =return.length"<<endl; 
      }
  
 if(length>2)
{
  y=length;
  x=length;
  returned.head=head->next;
   C=returned.head;
   D=head;
   cc=C;
   dd=D;
   z=tail;
  if(y%2==1)   
   {
    
    length=(x/2)+1;
	 returned.length=x/2;
   }
  else if(y%2==0)
   {
    
    length=x/2;
	 returned.length=x/2;
   }

	while(C->next!=tail)
   {
   dd=D;
   cc=C;
	D=C->next;
   D->prev=dd; //prev orig
   dd->next=D;
   if(D->next==tail) 
		{
		returned.tail=tail; 
      (returned.tail)->prev=cc;
      cc->next=returned.tail;
      (returned.tail)->next=NULL;
     
      tail=D;
     tail->prev=dd;
     dd->next=tail;
      tail->next=NULL;
        

		break;
		}
   C=D->next;
   C->prev=cc;//prev returned
   cc->next=C;
   	
	}
		
 
  if(C->next==tail)
  {
	returned.tail=C;
   cout<<" I am here              ~~~"<<endl; 
   if(y==3)
   {
    (returned.tail)->prev=NULL;
   }
   else{
   (returned.tail)->prev=cc;
   cc->next=returned.tail;}
   (returned.tail)->next=NULL;

 
   tail->prev=D;
   D->next=tail;
   tail->next=NULL;
   }  
   head->prev=NULL;
  (returned.head)->prev=NULL;
   }

 
   

	return returned; // your code here (replace this line)
}





/**
 * interleaveWith() -- Interleaving Function (GRADED!)
 *  - Interleaves the parameter list with the current list
 *  - Should leave the parameter list empty
 */
template <class T>
void List<T>::interleaveWith(List<T> &L2 /* declare secondlist here and in .h */)
{
	// your code here
   ListNode* E1;
   ListNode* E2;
   ListNode* F1;
   ListNode* F2;
   ListNode* H1, *H2;

H1=head;
H2=L2.head;

if(H1==NULL && H2!=NULL)
{
length=L2.length;
L2.length=0;
head=L2.head;
L2.head=NULL;

tail=L2.tail;
L2.tail=NULL;

}


if(H1==NULL && H2==NULL) return;
if(H1!=NULL && H2==NULL) return;



if(H1!=NULL && H2!=NULL) 
{
   E1=head;
   E2=L2.head;
   F1=E1->next;
   F2=E2->next;

   this->length=this->length+L2.length;
 
   
while(E1!=tail)
   {
   F1=E1->next;
	E1->next=E2;
   E2->prev=E1;

   F2=E2->next;
   E2->next=F1;
   F1->prev=E2;

   E1=F1;
   E2=F2;
   if(E2==L2.tail) 
{  
   if(E1==tail)
   {
	 E1->next=E2;
    E2->prev=E1;
    tail=L2.tail;
    break;
   }
   else{
   F1=E1->next;
	E1->next=E2;
   E2->prev=E1;
  
   
   E2->next=F1;
   F1->prev=E2;
   break;
   }
} 
  }

if(E1==tail)
{
    
    E1->next=E2;
    E2->prev=E1;
    tail=L2.tail;
}


L2.head=NULL;
L2.tail=NULL;
L2.length=0;

   
}
}




template <class T>
void List<T>::sort()
{
  
 
  if(length>1)
  {
List<T> left, right;
int middle=length/2;

ListNode* A;
A=head;


for(int i=0; i<middle; i++)
{
A=A->next;
}

left.head=head;
left.tail=A->prev;
left.tail->next=NULL;
A->prev=NULL;
left.length=middle;


right.head=A;
right.tail=tail;
right.length=length-left.length;




head=NULL;
tail=NULL;
length=0;



right.sort();
left.sort();
merge(right,left);



  }
else return;

}

//merge //

template <class T>
void List<T>::merge(List<T> &right, List<T> &left)
{

  while(left.length>0||right.length>0)
{
  if(left.length>0 && right.length>0)
   {
		if(((left.head)->data)<((right.head)->data))
      { append(left);
      }
     else{append(right);
   }
	}
     else if(right.length>0)
   { append(right);
   }
     else if(left.length>0)
   { append(left);
   }
}
}


template <class T>
void List<T>::append(List<T> & L)
{
  ListNode* A;
 

 
  if(length!=0 && L.length!=0)
{
   length=length+1;
	tail->next=L.head;
   L.head->prev=tail;
	tail=tail->next;
}
   else if(length==0 && L.length!=0)
{
   length=1;
	head=L.head;
	tail=L.head;
   
}

 


 {if(L.length==1)
{
	L.length=0;
	L.head=NULL;
	L.tail=NULL;
}

  else
{
   L.length=L.length-1;
   A=L.head;
	L.head=L.head->next;
   A->next=NULL;
   L.head->prev=NULL;
   
	
}

}
}








































