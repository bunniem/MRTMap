// List_Station.cpp - Implementation of List ADT using Array
#include "List_Station.h"  // header file

// constructor
List_Station::List_Station() { size = 0; }

// add an item to the back of the list (append)
bool List_Station::add(Station* item)
{
	bool success = size < MAX_SIZE500;
	if (success)
	{
		items[size] = item;    // add to the end of the list
		size++;                // increase the size by 1
	}
	return success;
}

// add an item at a specified position in the list (insert)
bool List_Station::add(int index, Station* item)
{
	bool success = (index >= 0) && (index <= size) && (size < MAX_SIZE500);
	if (success)
	{  // make room for the item by shifting all items at
	   // positions >= index toward the end of the
	   // List (no shift if index == size + 1)
		for (int pos = size; pos >= index; pos--)
			items[pos] = items[pos - 1];
		// insert the item
		items[index] = item;
		size++;  // increase the size by 1
	}
	return success;
}

// remove an item at a specified position in the list
void List_Station::remove(int index)
{
	bool success = (index >= 0) && (index < size);
	if (success)
	{  // delete item by shifting all items at positions >
	   // index toward the beginning of the list
	   // (no shift if index == size)
		for (int pos = index; pos < size; pos++)
			items[pos] = items[pos + 1];
		size--;  // decrease the size by 1
	}
}

// get an item at a specified position of the list (retrieve)
Station* List_Station::get(int index)
{
	bool success = (index >= 0) && (index < size);
	if (success)
		return items[index];
	else
		return nullptr;
}

// check if the list is empty
bool List_Station::isEmpty() { return size == 0; }

// check the size of the list
int List_Station::getLength() { return size; }

// display the items in the list
void List_Station::print()
{
	for (int i = 0; i < size; ++i)
	{
		cout << items[i]->Name() << endl;
	}
}