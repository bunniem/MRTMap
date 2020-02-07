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

	/* returns pointer to Station object */
	Station* StationObj();

	/* returns distance (integer) */
	int Distance();

	/* returns the Line Code (string) 
	EW (LineCode)*/
	std::string LineCode();
};

