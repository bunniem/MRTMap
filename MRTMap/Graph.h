#pragma once
#include <iostream>
using namespace std;

class Graph
{
private:
	// Data structure to store Adjacency list nodes
	struct Node {
		int val, cost;
		Node* next;
	};

	int N;  // number of nodes in the graph

	// Function to allocate new node of Adjacency List
	Node* getAdjListNode(int value, int weight, Node* head)
	{
		Node* newNode = new Node;
		newNode->val = value;
		newNode->cost = weight;

		// point new node to current head
		newNode->next = head;

		return newNode;
	}
public:
	// Data structure to store graph edges
	struct Edge {
		int src, dest, weight;
	};
	// A pointer that points to an array of pointers to Node to represent
	// adjacency list
	Node** head;

	// Constructor
	Graph(Edge edges[], int n, int N);

	// prints the adjacency list
	void printList();
};
