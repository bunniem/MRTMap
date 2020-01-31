#include "Connection.h"

// constructor
Connection::Connection(Station* s, int d)
{
	station = s;
	distance = d;
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