#pragma once
#include "Station.h"
class Connection
{
private:
	Station stnConnect;
	int distance;
public:
	Connection();
	Connection(Station s, int d);
};

