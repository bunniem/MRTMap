#pragma once
#include "Station.h"
class Connection
{
	Station* station;
	int distance;

public:
	// constructor
	Connection(Station* s, int d);

	// station name
	Station* StationObj();

	// distance
	int Distance();
};

