#pragma once
#include "List.h"
#include "List_Connection.h"

class Station
{
private:
	string name;
	List code;
	List_Connection connections;
	bool interchange = false;

public:
	// constructor
	Station();
	Station(string n, string c);

	// station name
	string Name();

	// station code list
	List Code();

	// add station code
	bool addCode(string c);

	// add connection
	bool addConnection(Connection* conn);

	// check if is interchange
	bool isInterchange();

	// print out all details
	void print();

	// print out name and code only
	void printMin();
};

