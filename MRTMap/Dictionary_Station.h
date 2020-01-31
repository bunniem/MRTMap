// Dictionary_Station.h - - Specification of Dictionary ADT
#include <string>
#include <iostream>
#include "Station.h"
using namespace std;

const int MAX_SIZE200 = 200;

class Dictionary_Station
{
private:
	struct Node
	{
		string key;   // search key
		Station* item;	// data item
		Node* next;	// pointer pointing to next item
	};

	Node* items[MAX_SIZE200] = { NULL };
	int  size;			// number of items in the Dictionary

public:
	// constructor
	Dictionary_Station();

	// destructor
	//~Dictionary();

	// determine int value for character
	int charvalue(char c);

	// hash function
	int hash(string key);

	// add a new item with the specified key to the Dictionary
	bool add(string newKey, Station* newItem);

	// remove an item with the specified key in the Dictionary
	bool remove(string key);

	// get an item with the specified key in the Dictionary (retrieve)
	Station* get(string key);

	// check if the Dictionary is empty
	bool isEmpty();

	// check the size of the Dictionary
	int getLength();
};
