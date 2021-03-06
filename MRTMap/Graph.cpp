#include "Graph.h"

// constructor
graph::graph(List_Ptr<Station, 1000>* l)
{
	// initialise memory
	for (int i = 0; i < MAX_SIZE1000; ++i)
	{
		items[i] = nullptr;
	}

	stnList = l;
	for (int i = 0; i < stnList->getLength(); ++i)
	{
		List_Ptr<Connection, 30> conn = stnList->get(i)->Connections();
		for (int j = 0; j < conn.getLength(); ++j)
		{
			Node* newNode = new Node();
			newNode->weight = conn.get(j)->Distance();
			newNode->next = nullptr;

			// get station object of connection of a station
			Station* nextStn = conn.get(j)->StationObj();
			for (int k = 0; k < stnList->getLength(); ++k)
			{
				if (stnList->get(k) == nextStn) // get vertex number of station
				{
					newNode->vertex = k;
					break;
				}
			}

			if (items[i] == nullptr)
			{
				items[i] = newNode;
			}
			else
			{
				Node* previous = items[i];
				Node* current = previous;
				while (current != nullptr)
				{
					previous = current;
					current = current->next;
				}
				previous->next = newNode;
			}
		}
	}
}

// find path (using dijkstra's algorithm)
List_Ptr<Station, 100> graph::find_path(Station* src, Station* des, int* finalDist)
{
	// arrays to use for the algorithm
	bool visited[MAX_SIZE1000];				// track which stations are visited
	int distance[MAX_SIZE1000];				// distance from source vertex to other vertex
	int prevVertex[MAX_SIZE1000];			// intermediate vertex
	int temp{};								// used for getting shortest distance
	int srcVertex{}, desVertex{}, vertex{};	// vertex number
	List_Ptr<Station, 100> path;			// list of stations on shortest path
	Node* current;

	// for all stations
	for (int i = 0; i < stnList->getLength(); ++i)
	{
		visited[i] = false;	// set visited status to false
		distance[i] = 999999999;	// set distance to infinity 
		prevVertex[i] = -1;	// set previous vertex to none
	}
	
	// get source and destination vertex
	for (int i = 0; i < stnList->getLength(); ++i)
	{
		if (stnList->get(i) == src)
		{
			distance[i] = 0; // set distance of source vertex to zero
			srcVertex = i;	// get source vertex
		}	
		if (stnList->get(i) == des)
		{
			desVertex = i;	// get destination vertex
		}
	}

	// visit vertices until destination vertex visited
	while (!visited[desVertex])
	{
		// set temp to unvisited vertex distance
		for (int i = 0; i < stnList->getLength(); ++i)
		{
			if (!visited[i])
			{
				temp = distance[i];
				break;
			}
		}

		// get unvisited vertex with smallest known distance from start vertex
		for (int i = 0; i < stnList->getLength(); ++i)
		{
			if (temp >= distance[i] && !visited[i])
			{
				temp = distance[i];
				vertex = i;
			}
		}

		// for current vertex, examine unvisited adjacent vertices
		current = items[vertex];
		while (current != nullptr)
		{
			if (!visited[current->vertex])
			{
				// calculate distance of neighbour from start vertex and compare with known distance
				if (distance[vertex] + current->weight < distance[current->vertex])
				{
					distance[current->vertex] = distance[vertex] + current->weight;	// update known distance to lower distance
					prevVertex[current->vertex] = vertex;	// update previous vertex
				}
			}
			current = current->next;
		}

		// set current vertex to visited
		visited[vertex] = true;
	}

	// find path from source to destination
	path.add(stnList->get(desVertex));
	*finalDist = distance[desVertex];
	while (prevVertex[desVertex] != -1)	// loop till reach source vertex
	{
		path.add(stnList->get(prevVertex[desVertex]));	// add vertices from previous vertex
		desVertex = prevVertex[desVertex];	// go to previous vertex
	}
	return path;
}