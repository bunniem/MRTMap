#include "Station.h"

// constructors
Station::Station() {}
Station::Station(string n, string c)
{
	name = n;
	code.add(c);
}

// station name
string Station::Name()
{
	return name;
}

// station code list
List<string> Station::Code()
{
	return code;
}

// list of connections
List_Ptr<Connection, 30> Station::Connections()
{
	return connections;
}

// add station code
bool Station::addCode(string c)
{
	if (!code.exist(c))
	{
		code.add(c);
		if (code.getLength() > 1)
		{
			interchange = true;
		}
		return true;
	}
	return false;
}

// add connection
bool Station::addConn(Connection* conn)
{
	connections.add(conn);
	return true;
}

// remove connection
bool Station::removeConn(Connection* conn)
{
	for (int i = 0; i < connections.getLength(); ++i)
	{
		if (connections.get(i) == conn)
		{
			connections.remove(i);
			return true;
		}
	}
	return false;
}

// check if station is interchange
bool Station::isInterchange()
{
	return interchange;
}

// print out all details
void Station::print()
{
	cout << endl << "Station : " << name;
	if (interchange) { cout << "*"; }
	cout << " (";

	for (int i = 0; i < code.getLength()-1; ++i)
	{
		cout << code.get(i) << "/";
	}
	cout << code.get(code.getLength() - 1) << ")" << endl << endl;

	cout << "Connection(s) to other station(s) :" << endl;
	cout << "----------------------------------" << endl;
	for (int i = 0; i < connections.getLength(); ++i)
	{
		Station* otherStn = connections.get(i)->StationObj();
		cout << (float)connections.get(i)->Distance() / 1000 << " KM\t<-----" << connections.get(i)->LineCode() << "----->\t";
		otherStn->printMin();
	}
	cout << "----------------------------------" << endl;
	cout << endl << "Note : Stations with * are interchanges" << endl;
}

// print out name and code only
void Station::printMin()
{
	cout << name;
	if (interchange == true) { cout << "*"; }
	cout << " (";
	for (int i = 0; i < code.getLength() - 1; ++i)
	{
		cout << code.get(i) << "/";
	}
	cout << code.get(code.getLength() - 1) << ")" << endl;
}