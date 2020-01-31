#pragma once
#include "List.h"
#include "List_Connection.h"

class Station
{
private:
	string name;
	List code;
	List_Connection connection;
	bool interchange = false;

public:
	// constructor
	Station();
	Station(string n, string c);

	// station name
	string Name();

	// add station code
	bool addCode(string c);

	// add connection
	bool addConnection(Connection* c);

	// check if is interchange
	bool isInterchange();
};

