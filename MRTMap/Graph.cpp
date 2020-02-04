#include "Graph.h"

// constructor
graph::graph(List_Station* l)
{
	// initialise memory
	for (int i = 0; i < MAX_SIZE600; ++i)
	{
		items[i] = nullptr;
	}

	stnList = l;
	for (int i = 0; i < stnList->getLength(); ++i)
	{
		List_Connection conn = stnList->get(i)->Connections();
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

// reload graph
void graph::reload()
{
	for (int i = 0; i < stnList->getLength(); ++i)
	{
		List_Connection conn = stnList->get(i)->Connections();
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
List_Station graph::find_path(Station* src, Station* des, int* finalDist)
{
	// arrays to use for the algorithm
	bool visited[MAX_SIZE600];	// track which stations are visited
	bool allVisited = false;
	int dist, srcVertex{}, desVertex{};
	int distance[MAX_SIZE600]; // distance from source vertex to other vertex
	int prevVertex[MAX_SIZE600];	// intermediate vertex
	List_Station path;

	for (int i = 0; i < stnList->getLength(); ++i)
	{
		visited[i] = false;	// set visited of all vertex to false
		distance[i] = 999999999;	// set distance to infinity 
		prevVertex[i] = -1;
	}

	// set distance of source vertex to zero
	for (int i = 0; i < stnList->getLength(); ++i)
	{
		if (stnList->get(i) == src)
		{
			distance[i] = 0;
			srcVertex = i;	// get source vertex
			break;
		}
	}

	// get destination vertex
	for (int i = 0; i < stnList->getLength(); ++i)
	{
		if (stnList->get(i) == des)
		{
			desVertex = i;
			break;
		}
	}

	while (!allVisited)
	{
		// get unvisited vertex with smallest known distance from start vertex
		int temp = distance[0];
		int vertex{};
		for (int i = 0; i < stnList->getLength(); ++i)
		{
			if (temp > distance[i] && !visited[i])
			{
				vertex = i;
			}
		}

		// for current vertex, examine unvisited neighbours
		Node* current = items[vertex];
		while (current != nullptr)
		{
			if (!visited[current->vertex])
			{
				// calculate distance of neighbour from start vertex
				dist = distance[vertex] + current->weight;
				if (dist < distance[current->vertex])
				{
					distance[current->vertex] = dist;
					prevVertex[current->vertex] = vertex;
				}
			}
			current = current->next;
		}
		// set current vertex to visited
		visited[vertex] = true;

		// see if all vertex have been visited
		allVisited = true;
		for (int i = 0; i < stnList->getLength(); ++i)
		{
			if (visited[i] == false)
			{
				allVisited = false;
				break;
			}
		}
	}

	// find path from source to destination
	path.add(stnList->get(desVertex));
	*finalDist = distance[desVertex];
	while (prevVertex[desVertex] != -1)	// loop till reach source vertex
	{
		path.add(stnList->get(prevVertex[desVertex]));	// add vertex from destination to previous to list
		desVertex = prevVertex[desVertex];	// go to previous vertex
	}
	return path;
}