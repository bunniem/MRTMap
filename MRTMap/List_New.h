// List_New.h - - Specification of List ADT
#pragma once
#include <iostream>
#include "Station.h"
using namespace std;

const int MAX_SIZE1000 = 1000;

template<class ItemType>
class List_New
{
private:
	ItemType* items[MAX_SIZE1000];
	int     size;

public:

	// constructor
	List_New() { size = 0; }

	// add an item to the back of the list (append)
	bool add(ItemType* item)
	{
		bool success = size < MAX_SIZE1000;
		if (success)
		{
			items[size] = item;    // add to the end of the list
			size++;                // increase the size by 1
		}
		return success;
	}

	// add an item at a specified position in the list (insert)
	bool add(int index, ItemType* item)
	{
		bool success = (index >= 0) && (index <= size) && (size < MAX_SIZE1000);
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
	void remove(int index)
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
	ItemType* get(int index)
	{
		bool success = (index >= 0) && (index < size);
		if (success)
			return items[index];
		else
			return nullptr;
	}

	// finds out if an item already exists in the list
	bool exist(ItemType* item)
	{
		for (int i = 0; i < size; i++)
		{
			if (item == items[i])
			{
				// item exists
				return true;
			}
		}
		// if reached this point, item does not exist
		return false;
	}

	// check if the list is empty
	bool isEmpty() { return size == 0; }

	// check the size of the list
	int getLength() { return size; }

	// display the items in the list
	void print()
	{
		for (int i = 0; i < size; ++i)
		{
			cout << items[i] << endl;
		}
	}
};
