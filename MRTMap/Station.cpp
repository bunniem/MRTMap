#include "Station.h"

// constructor
Station::Station(string n, string c)
{
	name = n;
	code.add(c);
}

// add station code
bool Station::addCode(string c)
{
	code.add(c);
}

// add a connection
bool Station::addConn(Connection c)
{
	connList.add(c);
}