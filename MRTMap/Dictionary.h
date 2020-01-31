// Dictionary.h - - Specification of Dictionary ADT
#include<string>
#include<iostream>
using namespace std;

const int MAX_SIZE201 = 201;

class Dictionary
{
private:
	struct Node
	{
		string key;   // search key
		string item;	// data item
		Node* next;	// pointer pointing to next item
	};

	Node* items[MAX_SIZE201] = { NULL };
	int  size;			// number of items in the Dictionary

public:
	// constructor
	Dictionary();

	// destructor
	//~Dictionary();

	// determine int value for character
	int charvalue(char c);

	// hash function
	int hash(string key);

	// add a new item with the specified key to the Dictionary
	bool add(string newKey, string newItem);

	// remove an item with the specified key in the Dictionary
	bool remove(string key);

	// get an item with the specified key in the Dictionary (retrieve)
	string get(string key);

	// check if the Dictionary is empty
	bool isEmpty();

	// check the size of the Dictionary
	int getLength();

	//------------------- Other useful functions -----------------
	// display the items in the Dictionary
	void print();
};
