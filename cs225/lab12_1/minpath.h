/*
    Lab 12: Minimum Path
    Written by Sean Massung for CS 225 Spring 2011
*/

#ifndef _PATH_H_
#define _PATH_H_

/*
  Tasks:
    1. Return the shortest distance (in edges) between the node labeled start and the node labeled end.
    2. Label each edge as "MINPATH" if it is part of the minimum path.
  Notes/hints:
    - You may use the stack and queue classes from the STL if you'd like.
    - Assume that this is an *unweighted* graph (ignore the weights).
    - In order to draw (and correctly count) the edges between the two vertices,
        you will have to remember each vertex's "parent" somehow...
*/

#include <stack>
#include <queue>
#include "graph.h"
#include "libdsets/dsets.h"

using std::pair;
using std::stack;
using std::queue;



int minPath(Graph & g, string start, string end);
void searchpath(Graph & g, string start, string end, int n, int & m);


string drawit(Graph & g, string start, string end, int n ,int m, int MM);
void draw(Graph & g, string start, string end, int & m);



// define any helper functions here

#endif