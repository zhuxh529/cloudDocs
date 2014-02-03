#include <iostream>
using namespace std;



template<class T>
 void Stack<T>::push(T const & newItem)
{
  
  myStack.push_front(newItem);
 
}


template<class T>
T Stack<T>:: pop()
{
  if(isEmpty()) return NULL;
  else {T x = peek();
  myStack.pop_front();
  return x;
 }
}

template<class T>
T Stack<T>::peek()  const
{
 if(isEmpty()) return NULL;
 else return myStack.front(); 
}

template<class T>
bool Stack<T>::isEmpty() const
{
 if(myStack.empty()) return true;
 else return false;
}
