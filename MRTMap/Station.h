#pragma once
#include "List_Ptr.h"
#include "List.h"
#include "Connection.h"

class Station
{
private:
	string name;
	List code;
	List_Ptr<Connection, 30> connections;
	bool interchange = false;

public:
	// constructor
	Station();
	Station(string n, string c);

	// station name
	string Name();

	// station code list
	List Code();

	// list of connections
	List_Ptr<Connection, 30> Connections();

	// add station code
	bool addCode(string c);

	// add connection
	bool addConnection(Connection* conn);

	// remove connection
	bool removeConnection(Connection* conn);

	// check if is interchange
	bool isInterchange();

	// print out all details
	void print();

	// print out name and code only
	void printMin();
};

