#pragma once
#include "List_Ptr.h"
#include "List.h"
#include "Connection.h"

class Station
{
private:
	string name;
	List<string> code;
	List_Ptr<Connection, 30> connections;
	bool interchange = false;

public:
	// constructor
	Station();
	Station(string n, string c);

	// station name
	// pre : none
	// post: none
	// returns name of the station
	string Name();

	// station code list
	// pre : none
	// post: none
	// returns list of station codes of the station
	List<string> Code();

	// list of connections
	// pre : none
	// post: none
	// returns list of connections of the station
	List_Ptr<Connection, 30> Connections();

	// add station code
	// pre : none
	// post: station code is added to the list
	bool addCode(string c);

	// add connection
	// pre : none
	// post: connection object is added to the list
	bool addConn(Connection* conn);

	// remove connection
	// pre : none
	// post: connection is removed from the list
	// returns true if connection is removed; otherwise return false
	bool removeConn(Connection* conn);

	// check if station is an interchange
	// pre : none
	// post: none
	// returns true if station is interchange; otherwise return false
	bool isInterchange();

	// print out all details
	// pre : none
	// post: none
	// prints out details of a station to console
	void print();

	// print out name and code only
	// pre : none
	// post: none
	// print out name and code of a station to console
	void printMin();
};

