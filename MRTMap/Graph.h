// Graph.h -- Specification of Graph ADT
#pragma once
#include <iostream>
#include "List_Ptr.h"
#include "Station.h"

const int MAX_SIZE1000 = 1000;
class graph
{
private:
	struct Node
	{
		int vertex;   // vertex
		int weight;	// weight
		Node* next;	// pointer pointing to next item
	};

	Node* items[MAX_SIZE1000];	// adjacency list
	List_Ptr<Station, 1000>* stnList;	// list of all stations

public:
	// constructor
	graph(List_Ptr<Station, 1000>* l);

	// find path (using dijkstra's algorithm)
	List_Ptr<Station, 100> find_path(Station* src, Station* des, int* finalDist);
};