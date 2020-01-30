// Graph.h -- Specification of Graph ADT
#pragma once
#include <iostream>
using namespace std;

// Data structure to store edges
struct Edge {
	int src, dest, weight;
};

class Graph
{
private:
	// Data structure to store adjacency list nodes
	struct Node {
		int val, cost;
		Node* next;
	};

	int N;  // number of nodes in the graph

	// Function to allocate new node of Adjacency List
	void getAdjListNode(int src, int dest, int weight)
	{
		Node* newNode = new Node;
		newNode->val = dest;
		newNode->cost = weight;
		newNode->next = nullptr;

		if (head[src] == nullptr)
		{
			head[src] = newNode;
		}
		else
		{
			Node* current = head[src];
			Node* previous = head[src];
			while (current != nullptr)
			{
				previous = current;
				current = current->next;
			}
			// point new node to current head
			previous->next = newNode;
		}
	}
public:
	// A pointer that points to an array of pointers to Node to represent
	// adjacency list
	Node** head;

	// Constructor
	Graph(Edge edges[], int n, int N);

	// prints the adjacency list
	void printList();
};
