// Dictionary_Ptr.h - - Specification of Dictionary ADT
#include <string>
#include <iostream>
#include "Line.h"
#include "List.h"
using namespace std;

template<typename ItemType>
class Dictionary_Ptr
{
private:
	struct Node
	{
		string key;   // search key
		ItemType* item;	// data item
		Node* next;	// pointer pointing to next item
	};

	Node* items[100] = { NULL };
	int  size;			// number of items in the Dictionary

public:
	// constructor
	Dictionary_Ptr() { size = 0; }

	int charvalue(char c)
	{
		if (isalpha(c))
		{
			if (isupper(c))
				return (int)c - (int)'A';
			else
				return (int)c - (int)'a' + 26;
		}
		else
			return -1;
	}

	// hash function
	int hash(string key)
	{
		int hashVal = 0;
		for (size_t i = 0; i < key.length(); ++i)
		{
			hashVal += charvalue(key[i]) * 52;
		}
		hashVal %= 100; // modulo to wrap and prevent overflow
		return hashVal;
	}

	// add a new item with the specified key to the Dictionary
	bool add(string newKey, ItemType* newItem)
	{
		// determine hash value for index
		int index;
		index = hash(newKey);

		// create newNode
		Node* newNode = new Node();
		newNode->key = newKey;
		newNode->item = newItem;
		newNode->next = NULL;

		if (items[index] == NULL)
		{
			items[index] = newNode;
		}
		else
		{
			// go through the linked list
			Node* previous = items[index];
			Node* current = previous;
			while (current != NULL)
			{
				// duplicate key
				if (current->key == newKey)
				{
					delete newNode;
					return false;
				}
				previous = current;
				current = current->next;
			}
			// if reached this point, there are no duplicate keys
			previous->next = newNode;
		}
		size++;
		return true;
	}

	// remove an item with the specified key in the Dictionary
	bool remove(string key)
	{
		// determine hash value for index
		int index;
		index = hash(key);

		if (items[index] != NULL)
		{
			// go through the linked list
			Node* previous = items[index];
			Node* current = previous;
			while (current != NULL)
			{
				// match key
				if (current->key == key)
				{
					previous->next = current->next;
					if (current == previous) // first node in linked list
					{
						if (current->next == NULL)
						{
							items[index] = NULL;
						}
						else
						{
							items[index] = current->next;
						}
					}
					delete current->item;
					delete current;
					size--;
					return true;
				}
				previous = current;
				current = current->next;
			}
		}
		// if reached this point, there are no matched keys
		return false;
	}

	// get an item with the specified key in the Dictionary (retrieve)
	ItemType* get(string key)
	{
		// determine hash value for index
		int index;
		index = hash(key);

		if (items[index] != NULL)
		{
			// go through the linked list
			Node* current = items[index];
			while (current != NULL)
			{
				// match key
				if (current->key == key)
				{
					return current->item;
				}
				current = current->next;
			}
		}
		// if reached this point, means that no matched keys
		return nullptr;
	}

	// get station / line names
	List<string> getNames()
	{
		List<string> keyList;
		Node* current;
		for (int i = 0; i <	100; ++i)
		{
			if (items[i] != NULL)
			{
				current = items[i];
				while (current != NULL)
				{
					keyList.add(current->item->Name());
					current = current->next;
				}
			}
		}
		return keyList;
	}

	// check if the Dictionary is empty
	bool isEmpty() { return size == 0; }

	// check the size of the Dictionary
	int getLength() { return size; }

};
