#pragma once
#include <string>
#include "ListString.h"
#include "ListConnection.h"
#include "Connection.h"
using namespace std;

class Station
{
private:
	string name;
	ListString<string> code;
	ListConnection<Connection> ConnList;
	bool interchange;

public:
	Station();
	Station(string n, string c);
	bool addCode(string c);
	bool addConn(Connection con);
	void ToString();
};

