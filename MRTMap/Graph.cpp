#include "Graph.h"

Graph::Graph(Edge edges[], int n, int N)
{
	// allocate array in memory
	head = new Node * [N];
	this->N = N;

	// initialise head pointers in array to null
	for (int i = 0; i < N; ++i)
		head[i] = nullptr;

	// add edges to the graph
	for (unsigned i = 0; i < n; i++)
	{
		int src = edges[i].src;
		int dest = edges[i].dest;
		int weight = edges[i].weight;

		// insert in the beginning
		Node* newNode = getAdjListNode(dest, weight, head[src]);

		// point head pointer to new node
		head[src] = newNode;

		newNode = getAdjListNode(src, weight, head[dest]);

		// change head pointer to point to the new node
		head[dest] = newNode;
	}
}

// prints the adjacency list
void Graph::printList()
{
	for (int i = 0; i < N; ++i)
	{
		if (head[i] != nullptr)
		{
			cout << "(" << i << ", " << head[i]->val
				<< ", " << head[i]->cost << ") ";
			head[i] = head[i]->next;
		}
		cout << endl;
	}
}