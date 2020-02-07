// List.h - - Specification of List ADT
#pragma once
#include <iostream>
using namespace std;

const int MAX_SIZE100 = 100;

template <typename ItemType>
class List
{
private:
	ItemType items[MAX_SIZE100];
	int     size;

public:

	// constructor
	List() { size = 0; }

	// add an item to the back of the list (append)
	// pre : size < MAX_SIZE
	// post: item is added to the back of the list
	//       size of list is increased by 1
	bool add(ItemType item)
	{
		bool success = size < MAX_SIZE100;
		if (success)
		{
			items[size] = item;    // add to the end of the list
			size++;                // increase the size by 1
		}
		return success;
	}

	// add an item at a specified position in the list (insert)
	// pre : 0 <= index <= size && size < MAX_SIZE
	// post: item is added to the specified position in the list
	//       size of list is increased by 1
	bool add(int index, ItemType item)
	{
		bool success = (index >= 0) && (index <= size) && (size < MAX_SIZE100);
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
	// pre : 0 <= index < size
	// post: item is removed the specified position in the list
	//       size of list is decreased by 1
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
	// pre : 0 <= index < size
	// post: none
	ItemType get(int index)
	{
		bool success = (index >= 0) && (index < size);
		if (success)
			return items[index];
		else
			return "";
	}

	// finds out if an item already exists in the list
	// pre : none
	// post : return true if item exists; otherwise returns false
	bool exist(ItemType item)
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
	// pre : none
	// post: none
	// return true if the list is empty; otherwise returns false
	bool isEmpty() { return size == 0; }

	// check the size of the list
	// pre : none
	// post: none
	// return the number of items in the list
	int getLength() { return size; }

	// display the items in the list
	// pre : none
	// post: none
	// print out items in the list to console
	void print()
	{
		for (int i = 0; i < size; ++i)
		{
			cout << items[i] << endl;
		}
	}
};
