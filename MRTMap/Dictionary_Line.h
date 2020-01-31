// Dictionary_Line.h - - Specification of Dictionary ADT
#include <string>
#include <iostream>
#include "Line.h"
using namespace std;

const int MAX_SIZE20 = 20;

class Dictionary_Line
{
private:
	struct Node
	{
		string key;   // search key
		Line* item;	// data item
		Node* next;	// pointer pointing to next item
	};

	Node* items[MAX_SIZE20] = { NULL };
	int  size;			// number of items in the Dictionary

public:
	// constructor
	Dictionary_Line();

	// destructor
	//~Dictionary();

	// determine int value for character
	int charvalue(char c);

	// hash function
	int hash(string key);

	// add a new item with the specified key to the Dictionary
	bool add(string newKey, Line* newItem);

	// remove an item with the specified key in the Dictionary
	bool remove(string key);

	// get an item with the specified key in the Dictionary (retrieve)
	Line* get(string key);

	// check if the Dictionary is empty
	bool isEmpty();

	// check the size of the Dictionary
	int getLength();
};
