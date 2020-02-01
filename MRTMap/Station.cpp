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
List Station::Code()
{
	return code;
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
bool Station::addConnection(Connection* conn)
{
	connections.add(conn);
	return true;
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
		cout << connections.get(i)->Distance() << " Metres\t<----->\t" << otherStn->Name();
		if (otherStn->isInterchange()) { cout << "*"; }
		cout  << " (";
		for (int j = 0; j < otherStn->Code().getLength() - 1; ++j)
		{
			cout << otherStn->Code().get(j) << "/";
		}
		cout << otherStn->Code().get(otherStn->Code().getLength() - 1) << ")" << endl;
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
	cout << code.get(code.getLength() - 1) << ")";
	cout << endl;
}