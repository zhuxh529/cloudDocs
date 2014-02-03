#include <iostream>
#include "stack.h"
#include "queue.h"
using namespace std;

void testStack(){
  cout << "Testing Stack..." << endl;
  Stack<int> intStack;
  for(int i=2;i<4;i++){
    intStack.push(i);
  }
  cout << intStack.peek() << endl;
  while( !intStack.isEmpty() ){
    cout << intStack.pop() << " ";
  }
  cout << endl;
}

void testQueue(){
  cout << "Testing Queue..." << endl;
  Queue<int> intQueue;
  for(int i=1;i<5;i++){
    intQueue.enqueue(i);
  }
  cout << intQueue.peek() << endl;

  for(int i=1;i<3;i++){
     cout << intQueue.dequeue() << " "<<endl;;
  }



  for(int i=4;i<7;i++){
    intQueue.enqueue(i);
  }


  for(int i=1;i<4;i++){
     cout << intQueue.dequeue() << " ";
  }

  

  while( !intQueue.isEmpty() ){
    cout << intQueue.dequeue() << " ";
  }
  cout << endl;
}


int main(){
  testStack();
  testQueue();
  return 0;
}
