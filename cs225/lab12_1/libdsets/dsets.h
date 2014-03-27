#ifndef DSETS_H
#define DSETS_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class DisjointSets
{
	private:
	vector<int> body;
	
	
	
	
	public:
   void addelements(int n);
	int find(int n);
	void setunion(int n1, int n2);

};
//#include "dsets.cpp"
#endif
