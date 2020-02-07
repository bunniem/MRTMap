// Graph.h -- Specification of Graph ADT
#pragma once
#include <iostream>
#include "List_Station.h"
#include "List_New.h"

const int MAX_SIZE600 = 600;
class graph
{
private:
	struct Node
	{
		int vertex;   // vertex
		int weight;	// weight
		Node* next;	// pointer pointing to next item
	};

	Node* items[MAX_SIZE600];	// adjacency list
	List_New<Station>* stnList;	// list of all stations

public:
	// constructor
	graph(List_New<Station>* l);

	// find path (using dijkstra's algorithm)
	List_New<Station> find_path(Station* src, Station* des, int* finalDist);
};