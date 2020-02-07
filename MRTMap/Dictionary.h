// Dictionary.h - - Specification of Dictionary ADT
#include <string>
#include <iostream>
using namespace std;

template <typename ItemType>
class Dictionary
{
private:
	struct Node
	{
		string key;   // search key
		string item;	// data item
		Node* next;	// pointer pointing to next item
	};

	Node* items[100] = { NULL };
	int  size;			// number of items in the Dictionary

public:
	// constructor
	Dictionary() { size = 0; }

	/* convert char to integers */
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

	/* hash function to convert key into index of array */
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

	/* add a new item with the specified key to the Dictionary */
	// pre : key does not exist in the dictionary
	// post: entry created in dictionary with specified key and item
	// returns true if entry is added; otherwise return false (key already exists)
	bool add(string newKey, string newItem)
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

	/* remove an item with the specified key in the Dictionary */
	// pre : key exists in the dictionary
	// post: entry removed with specified key
	// returns true if entry is removed; otherwise returns false (key does not exist)
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

	/* get an item with the specified key in the Dictionary (retrieve) */
	// pre : key exists in the dictionary
	// post: none
	// returns the item with the specified key
	ItemType get(string key)
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
		return {};
	}

	/* check if the Dictionary is empty */
	bool isEmpty() { return size == 0; }

	/* check the size of the Dictionary */
	int getLength() { return size; }

	/* display the items in the Dictionary */
	void print()
	{
		if (isEmpty())
		{
			cout << "\nList is empty!\n" << endl;
		}
		else
		{
			Node* current;
			for (int i = 0; i < 100; ++i)
			{
				if (items[i] != NULL)
				{
					current = items[i];
					while (current != NULL)
					{
						cout << current->key << "\t" << current->item << endl;
						current = current->next;
					}
				}
			}
		}
	}

};
