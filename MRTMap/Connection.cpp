#include "Connection.h"

// constructor
Connection::Connection() {}

Connection::Connection(Station s, int d)
{
	stnConnect = s;
	distance = d;
}