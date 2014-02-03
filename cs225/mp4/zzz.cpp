#include <iostream>
#include "stack.h"
#include "queue.h"
using namespace std;

void testStack(){
  cout << "Testing Stack..." << endl;
  Stack<int> intStack;
  for(int i=1;i<2;i++){
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
  for(int i=1;i<1;i++){
    intQueue.enqueue(i);
  }
  cout << intQueue.peek() << endl;
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














(*img(xx,yy)).Red=fillColor(xx,yy).Red;
(*img(xx,yy)).Green=fillColor(xx,yy).Green;
(*img(xx,yy)).Blue=fillColor(xx,yy).Blue;
