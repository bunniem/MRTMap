#pragma once
class Station;

class Connection
{
private:
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

