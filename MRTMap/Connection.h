#pragma once
#include <string>
class Station;

class Connection
{
private:
	Station* station;
	int distance;
	std::string lineCode;

public:
	// constructor
	Connection(Station* s, int d, std::string l);

	// station name
	Station* StationObj();

	// distance
	int Distance();

	// line code
	std::string LineCode();
};

