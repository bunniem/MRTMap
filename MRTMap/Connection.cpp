#include "Connection.h"

// constructor
Connection::Connection(Station* s, int d, std::string l)
{
	station = s;
	distance = d;
	lineCode = l;
}

// station name
Station* Connection::StationObj()
{
	return station;
}

// distance
int Connection::Distance()
{
	return distance;
}

// line code
std::string Connection::LineCode()
{
	return lineCode;
}