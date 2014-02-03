#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include "EasyBMP.h"
#include "dsets.h"
#include <stdlib.h>

using namespace std;

class SquareMaze
{
public:

  int kuan;
  int gao;
  int S;




	class Node
{
 public:
 bool downwall;
 bool rightwall;
 unsigned int dis;
 bool pass;
 Node()
 :downwall(true), rightwall(true), dis(0), pass(false) {}; 
 //int x, y;



/*	class disN
{
public:
bool up;
bool right;
bool down;
bool left;

int dis;

}
*/

};

vector<Node> mazebody;


public:

void makeMaze(int width, int height);


bool canTravel(int x, int y, int dir);


void setWall(int x, int y, int dir, bool exists);


void solveMaze();



BMP* drawMaze();


BMP* drawMazeWithSolution();



vector<int> solution;
int exit;

///////////////////////////////////////////////////////////////////////
//helper functions

int rightcell(int i);
int downcell(int i);
int leftcell(int i);
int upcell(int i);


bool ifBottom(int i);
bool ifRight(int i);
int getx(int i);
int gety(int i);

void getpath(int i);
void alldis(int initial);
int neighbour(int i);



};

#endif