// Dictionary.h - - Specification of Dictionary ADT
#include<string>
#include<iostream>
using namespace std;

const int MAX_SIZE4 = 101;
typedef string ItemType;
typedef string KeyType;
typedef bool ItemType5;

class DictionaryStnToCode
{
private:
	struct Node
	{
		KeyType  key;   // search key (Station Name)
		ItemType itemCode;	// data item  (Code)
		ItemType5 interchange;	//bool for interchange
		Node* next;	// pointer pointing to next item
	};

	Node* items[MAX_SIZE4] = { NULL };
	int  size;			// number of items in the Dictionary

public:
	// constructor
	DictionaryStnToCode();

	// destructor
	//~Dictionary();

	// determine int value for character
	int charvalue(char c);

	// hash function
	int hash(KeyType key);

	// add a new item with the specified key to the Dictionary
	bool add(KeyType newKey, ItemType newItem);

	// remove an item with the specified key in the Dictionary
	bool remove(KeyType key);

	// get an item with the specified key in the Dictionary (retrieve)
	ItemType get(KeyType key);

	// check if the Dictionary is empty
	bool isEmpty();

	// check the size of the Dictionary
	int getLength();

	bool replace(KeyType key, ItemType newItem);

	//------------------- Other useful functions -----------------
	// display the items in the Dictionary
	void print();
};
