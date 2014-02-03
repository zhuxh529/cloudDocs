#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include "letter.h"
#include "room.h"

class Allocator
{
	public:
	// Initialization
	Allocator(const string & studentFile, const string & roomFile);
    ~Allocator();
	// Solving
	void allocate();
    


	// Printing results
	void printStudents();
	void printRooms();

	private:
	// Initialization
	void createLetterGroups();
	void loadStudents(const string & file);
	void loadRooms(const string & file);

	// Solving
	int  solve();
	Room * largestOpening();
	int  minSpaceRemaining();

	// Member variables
	Letter * alpha;
	Room   * rooms;
	int roomCount;
	int studentCount;
	int totalCapacity;
};

#endif
