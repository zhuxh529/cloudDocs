#include <algorithm>
#include <vector>
#include <iostream>
#include <utility>

#include "fileio.h"
#include "letter.h"
#include "room.h"
#include "allocator.h"

using namespace std;

int main()
{
	cout << endl;
	Allocator theAllocator("students.txt", "rooms.txt");
	theAllocator.allocate();
	theAllocator.printRooms();
	cout << endl;
}
