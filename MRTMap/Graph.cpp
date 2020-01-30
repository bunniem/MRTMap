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
	for (int i = 0; i < n; ++i)
	{
		int src = edges[i].src;
		int dest = edges[i].dest;
		int weight = edges[i].weight;

		// allocate new node
		getAdjListNode(src, dest, weight);
		getAdjListNode(dest, src, weight);
	}
}

// prints the adjacency list
void Graph::printList()
{
	Node* current;
	for (int i = 0; i < N; ++i)
	{
		current = head[i];
		while (current != nullptr)
		{
			cout << "(" << i << ", " << current->val
				<< ", " << current->cost << ") ";
			current = current->next;
		}
		cout << endl;
	}
}