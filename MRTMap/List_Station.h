// List_Station.h - - Specification of List ADT for Station objects
#pragma once
#include "Station.h"
#include <iostream>
using namespace std;

const int MAX_SIZE500 = 500;

class List_Station
{
private:
	Station* items[MAX_SIZE500];
	int     size;

public:

	// constructor
	List_Station();

	// add an item to the back of the list (append)
	// pre : size < MAX_SIZE
	// post: item is added to the back of the list
	//       size of list is increased by 1
	bool add(Station* item);

	// add an item at a specified position in the list (insert)
	// pre : 0 <= index <= size && size < MAX_SIZE
	// post: item is added to the specified position in the list
	//       size of list is increased by 1
	bool add(int index, Station* item);

	// remove an item at a specified position in the list
	// pre : 0 <= index < size
	// post: item is removed the specified position in the list
	//       size of list is decreased by 1
	void remove(int index);

	// get an item at a specified position of the list (retrieve)
	// pre : 0 <= index < size
	// post: none
	Station* get(int index);

	// finds out if an item already exists in the list
	// pre : none
	// post : return true if item exists; otherwise returns false
	bool exist(Station* item);

	// check if the list is empty
	// pre : none
	// post: none
	// return true if the list is empty; otherwise returns false
	bool isEmpty();

	// check the size of the list
	// pre : none
	// post: none
	// return the number of items in the list
	int getLength();

	void print();

	void replace(int index, Station item);
};
