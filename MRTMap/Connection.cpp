#include "Connection.h"

// constructor
Connection::Connection(Station* s, int d, std::string l)
{
	station = s;
	distance = d;
	lineCode = l;
}

/* returns pointer to Station object */
Station* Connection::StationObj()
{
	return station;
}

/* returns distance (integer) */
int Connection::Distance()
{
	return distance;
}

/* returns the Line Code (string) */
std::string Connection::LineCode()
{
	return lineCode;
}