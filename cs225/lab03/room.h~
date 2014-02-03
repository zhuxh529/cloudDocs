#ifndef ROOM_H
#define ROOM_H

#include <string>

#include "letter.h"

using namespace std;

class Room
{
	public:
	string name;
	int capacity;
	int count;
	Letter * letters;
	int letterCount;

	Room();
	Room(const Room & other);
	Room(const string & init_name, int init_capacity);
	Room & operator=(const Room & other);
	~Room();

	void addLetter(const Letter & L);
	int spaceRemaining();
	void print();

	private:
	void clear();
	void copy(const Room & other);
};

#endif
