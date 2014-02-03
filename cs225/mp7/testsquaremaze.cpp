/*
*  testsquaremaze.cpp
*  cs225 Maze MP
*  Performs basic tests of SquareMaze.
*  Written April 2007 by Jonathan Ray
*/

#include <iostream>
#include "dsets.h"
#include "maze.h"
#include "EasyBMP.h"

int main()
{ 
   SquareMaze m;
   m.makeMaze(50,50);
   std::cout << "MakeMaze complete" << std::endl;

   BMP* unsolved = m.drawMaze();
   unsolved->writeToFile("unsolved.bmp");
   delete unsolved;
   std::cout << "drawMaze complete" << std::endl;
   
   m.solveMaze();
   std::cout << "solveMaze complete" << std::endl;

   
   BMP* solved = m.drawMazeWithSolution();
   solved->writeToFile("solved.bmp");
   delete solved;
   std::cout << "drawMazeWithSolution complete" << std::endl;
   
   return 0;
}

