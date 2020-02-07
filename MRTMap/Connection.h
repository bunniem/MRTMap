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
	// pre : none
	// post: none
	// returns station object in the connection
	Station* StationObj();

	/* returns distance (integer) */
	// pre : none
	// post: none
	// returns distance in the connection
	int Distance();

	/* returns the Line Code (string) */
	// pre : none
	// post: none
	// returns line code of the connection (e.g. East West Line -> EW)
	std::string LineCode();
};

