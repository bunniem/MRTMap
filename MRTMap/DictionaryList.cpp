#include "DictionaryList.h"

// constructor
DictionaryList::DictionaryList() { size = 0; }

int DictionaryList::charvalue(char c)
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
int DictionaryList::hash(KeyType key)
{
	int hashVal = 0;
	for (size_t i = 0; i < key.length(); ++i)
	{
		hashVal += charvalue(key[i]) * 52;
	}
	hashVal %= MAX_SIZE3; // modulo to wrap and prevent overflow
	return hashVal;
}

// add a new item with the specified key to the Dictionary
bool DictionaryList::add(KeyType newKey, ItemType2 newItem, ItemType3 newItem2)
{
	// determine hash value for index
	int index;
	index = hash(newKey);

	// create newNode
	Node* newNode = new Node();
	newNode->key = newKey;
	newNode->item = newItem;
	newNode->item2 = newItem2;
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
bool DictionaryList::remove(KeyType key)
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
				cout << "\nRemoved : " << key << endl;
				return true;
			}
			previous = current;
			current = current->next;
		}
	}
	// if reached this point, there are no matched keys
	cout << "\nNo matched keys!\n";
	return false;
}

// get an item with the specified key in the Dictionary (retrieve)
ItemType2 DictionaryList::getItem(KeyType key)
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
	cout << "\nNo matched keys!\n";
	return {};
}

// get an item with the specified key in the Dictionary (retrieve)
ItemType3 DictionaryList::getItem2(KeyType key)
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
				return current->item2;
			}
			current = current->next;
		}
	}
	// if reached this point, means that no matched keys
	cout << "\nNo matched keys!\n";
	return {};
}

// replace an item with the specified key in the Dictionary, returns false if item not found
bool DictionaryList::replace(KeyType key, ItemType2 newItem, ItemType3 newItem2)
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
				current->item = newItem;
				current->item2 = newItem2;
				return true;
			}
			current = current->next;
		}
	}
	// if reached this point, means that no matched keys
	return false;
}

// check if the Dictionary is empty
bool DictionaryList::isEmpty() { return size == 0; }

// check the size of the Dictionary
int DictionaryList::getLength() { return size; }