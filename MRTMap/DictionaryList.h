// DictionaryList.h - - Specification of Dictionary ADT
#include<string>
#include<iostream>
#include "List.h"
using namespace std;

const int MAX_SIZE = 101;
typedef List ItemType2;
typedef string KeyType;

class DictionaryList
{
private:
	struct Node
	{
		KeyType  key;   // search key
		ItemType2 item;	// data item
		Node* next;	// pointer pointing to next item
	};

	Node* items[MAX_SIZE] = { NULL };
	int  size;			// number of items in the Dictionary

public:
	// constructor
	DictionaryList();

	// destructor
	//~DictionaryList();

	// determine int value for character
	int charvalue(char c);

	// hash function
	int hash(KeyType key);

	// add a new item with the specified key to the Dictionary
	bool add(KeyType newKey, ItemType2 newItem);

	// remove an item with the specified key in the Dictionary
	bool remove(KeyType key);

	// get an item with the specified key in the Dictionary (retrieve)
	ItemType2 get(KeyType key);

	// check if the Dictionary is empty
	bool isEmpty();

	// check the size of the Dictionary
	int getLength();
};
