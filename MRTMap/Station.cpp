#include "Station.h"

// constructors
Station::Station() {}
Station::Station(string n, string c)
{
	name = n;
	code.add(c);
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

// station name
string Station::Name()
{
	return name;
}

// check if station is interchange
bool Station::isInterchange()
{
	return interchange;
}