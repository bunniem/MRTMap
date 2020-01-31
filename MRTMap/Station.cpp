#include "Station.h"

// constructors
Station::Station() {}
Station::Station(string n, string c)
{
	name = n;
	code.add(c);
}

// station name
string Station::Name()
{
	return name;
}

// add station code
bool Station::addCode(string c)
{
	if (!code.exist(c))
	{
		code.add(c);
		if (code.getLength() > 1)
		{
			interchange = true;
		}
		return true;
	}
	return false;
}

// add connection
bool Station::addConnection(Connection* c)
{
	connection.add(c);
	return true;
}

// check if station is interchange
bool Station::isInterchange()
{
	return interchange;
}