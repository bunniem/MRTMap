#include "Dictionary_Line.h"

// constructor
Dictionary_Line::Dictionary_Line() { size = 0; }

int Dictionary_Line::charvalue(char c)
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
int Dictionary_Line::hash(string key)
{
	int hashVal = 0;
	for (size_t i = 0; i < key.length(); ++i)
	{
		hashVal += charvalue(key[i]) * 52;
	}
	hashVal %= MAX_SIZE20; // modulo to wrap and prevent overflow
	return hashVal;
}

// add a new item with the specified key to the Dictionary
bool Dictionary_Line::add(string newKey, Line* newItem)
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
bool Dictionary_Line::remove(string key)
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
Line* Dictionary_Line::get(string key)
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

// check if the Dictionary is empty
bool Dictionary_Line::isEmpty() { return size == 0; }

// check the size of the Dictionary
int Dictionary_Line::getLength() { return size; }
