#include "ListString.h"

// constructor
ListString::ListString() { size = 0; }

// add an item to the back of the list (append)
bool ListString::add(ItemType item)
{
	// create a new node to store the item
	Node* newNode = new Node();
	newNode->item = item;
	newNode->next = NULL;

	// add new node to the list
	if (isEmpty())
	{
		firstNode = newNode;
	}
	else
	{
		Node* current = firstNode;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newNode;
	}
	size++;
	return true;
}

bool ListString::add(int index, ItemType item)
{
	bool valid = index >= 0 && index <= size;
	if (valid)
	{
		// create a new node to store the item
		Node* newNode = new Node();
		newNode->item = item;
		newNode->next = NULL;

		// add new node to the list at the specified location
		if (index == 0)
		{
			newNode->next = firstNode;
			firstNode = newNode;
		}
		else
		{
			Node* nodeBeforeIndex = firstNode;
			// move to the node before the specified index
			for (int i = 0; i < index - 1; i++)
			{
				nodeBeforeIndex = nodeBeforeIndex->next;
			}
			// make newNode point to next node
			newNode->next = nodeBeforeIndex->next;
			// make node before newNode point to newNode
			nodeBeforeIndex->next = newNode;
		}
		size++;
		return true;
	}
	return false;
}

bool ListString::remove(int index)
{
	bool valid = index >= 0 && index < size;
	if (valid)
	{
		if (index == 0)
		{
			Node* newFirstNode = firstNode->next;
			delete firstNode;
			firstNode = newFirstNode;
		}
		else
		{
			Node* nodeToDelete = firstNode;
			Node* nodeBeforeIndex = firstNode;
			// move to the node to be deleted
			for (int i = 0; i < index; i++)
			{
				nodeBeforeIndex = nodeToDelete;
				nodeToDelete = nodeToDelete->next;
			}
			// make node before index point to node after index
			nodeBeforeIndex->next = nodeToDelete->next;
			// free up memory from removed node
			delete nodeToDelete;
		}
		size--;
		return true;
	}
	return false;
}

ItemType ListString::get(int index)
{
	bool valid = index >= 0 && index < size;
	if (valid)
	{
		Node* nodeToGet = firstNode;
		// move to the node
		for (int i = 0; i < index; i++)
		{
			nodeToGet = nodeToGet->next;
		}
		// return node based on index
		return nodeToGet->item;
	}
}

// check if the list is empty
bool ListString::isEmpty() { return size == 0; }

// check the size of the list
int ListString::getLength() { return size; }

// display all the items in the list
void ListString::print()
{
	Node* printNode = firstNode;
	cout << "\n--------------------------------\n";
	for (int i = 0; i < size; i++)
	{
		cout << printNode->item << endl;
		printNode = printNode->next;
	}
	cout << "--------------------------------\n";
}