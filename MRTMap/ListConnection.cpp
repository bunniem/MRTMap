#include "ListConnection.h"  // header file

// constructor
ListConnection::ListConnection() { size = 0; }

// add an item to the back of the list (append)
bool ListConnection::add(ItemType item)
{
	bool success = size < MAX_SIZE;
	if (success)
	{
		items[size] = item;    // add to the end of the list
		size++;                // increase the size by 1
	}
	return success;
}

// add an item at a specified position in the list (insert)
bool ListConnection::add(int index, ItemType item)
{
	bool success = (index >= 0) && (index <= size) && (size < MAX_SIZE);
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
void ListConnection::remove(int index)
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
ItemType ListConnection::get(int index)
{
	bool success = (index >= 0) && (index < size);
	if (success)
		return items[index];
	else
		return Connection();
}

// check if the list is empty
bool ListConnection::isEmpty() { return size == 0; }

// check the size of the list
int ListConnection::getLength() { return size; }

// display the items in the list
void ListConnection::print()
{
	if (size >= 1)
	{
		cout << "Name\tTel No." << endl;
		cout << "---------------" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << items[i].getName() << "\t" << items[i].getTelNo() << endl;
		}
	}
	else
	{
		cout << "No contacts" << endl;
	}
}