// List.h - - Specification of List ADT
#pragma once
#include <iostream>
using namespace std;

const int MAX_SIZE10 = 10;

class List
{
private:
	string items[MAX_SIZE10];
	int     size;

public:

	// constructor
	List();

	// add an item to the back of the list (append)
	// pre : size < MAX_SIZE
	// post: item is added to the back of the list
	//       size of list is increased by 1
	bool add(string item);

	// add an item at a specified position in the list (insert)
	// pre : 0 <= index <= size && size < MAX_SIZE
	// post: item is added to the specified position in the list
	//       size of list is increased by 1
	bool add(int index, string item);

	// remove an item at a specified position in the list
	// pre : 0 <= index < size
	// post: item is removed the specified position in the list
	//       size of list is decreased by 1
	void remove(int index);

	// get an item at a specified position of the list (retrieve)
	// pre : 0 <= index < size
	// post: none
	string get(int index);

	// finds out if an item already exists in the list
	// pre : none
	// post : return true if item exists; otherwise returns false
	bool exist(string item);

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

	void replace(int index, string item);
};
