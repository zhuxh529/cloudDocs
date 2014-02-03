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
#include "mazereader.h"
using namespace std;

#define READ_SOLUTION_MAZE(width, height)  \
	MazeReader(READ_SOLUTION_BMP(width, height))

void copyMaze(const MazeReader & source, SquareMaze * dest);

int main()
{ 
   SquareMaze m;
   m.makeMaze(100,100);
   std::cout << "MakeMaze complete" << std::endl;

   BMP* unsolved = m.drawMaze();
   unsolved->writeToFile("unsolved.bmp");
   delete unsolved;
   std::cout << "drawMaze complete" << std::endl;


SquareMaze maze;
	MazeReader soln = READ_SOLUTION_MAZE(15, 15);
	copyMaze(soln, &maze);
	maze.solveMaze();

	if (maze.solution.empty())
		FAIL("No solution was generated");
	
	int x = 0;
	int y = 0;
	for (size_t i = 0; i < maze.solution.size(); i++)
	{
		if (soln.isWallInDir(x, y, maze.solution[i]))
			FAIL("Solution passes through walls");
		advancePosition(&x, &y, maze.solution[i]);
	}
}



   m.solveMaze();
   std::cout << "solveMaze complete" << std::endl;
   
   BMP* solved = m.drawMazeWithSolution();
   solved->writeToFile("solved.bmp");
   delete solved;
   std::cout << "drawMazeWithSolution complete" << std::endl;
   
   return 0;
}



void copyMaze(const MazeReader & source, SquareMaze * dest)
{
	dest->makeMaze(source.getWidth(), source.getHeight());
	for (int x = 0; x < source.getWidth(); x++)
	{
		for (int y = 0; y < source.getHeight(); y++)
		{
			if (x < source.getWidth() - 1)
				dest->setWall(x, y, 0, source.isWall(x, y, MazeReader::RIGHTWALL));
			if (y < source.getHeight() - 1)
				dest->setWall(x, y, 1, source.isWall(x, y, MazeReader::DOWNWALL));
		}
	}
}


