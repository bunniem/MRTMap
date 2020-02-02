#include "Line.h"

// constructors
Line::Line(){}
Line::Line(string n)
{
	name = n;
}

// add station object
bool Line::add(Station* s)
{
	// check for duplicates
	for (int i = 0; i < stations.getLength(); ++i)
	{
		if (stations.get(i) == s)
		{
			// duplicate stations
			return false;
		}
	}
	stations.add(s);
	return true;
}

// line name
string Line::Name()
{
	return name;
}

// line stations
List_Station Line::Stations()
{
	return stations;
}

// check if station exist on line
bool Line::existingStn(Station* s)
{
	for (int i = 0; i < stations.getLength(); ++i)
	{
		if (stations.get(i) == s)
		{
			return true;
		}
	}
	return false;
}

// print function
void Line::print(int i)
{
	if (i == 2)
	{
		cout << endl << "Station Line : " << name << endl << endl;
		cout << "Stations on the line" << endl;
		cout << "--------------------" << endl;
		stations.print();
		cout << "--------------------" << endl;
		cout << endl << "Note : Stations with * are interchanges" << endl;
	}
	else if (i == 3)
	{
		cout << endl << "Station Line : " << name << endl << endl;
		cout << "Stations on the line" << endl;
		cout << "--------------------" << endl;
		for (int i = 0; i < stations.getLength(); ++i)
		{
			cout << "[" << i + 1 << "] ";
			stations.get(i)->printMin();
		}
		cout << "--------------------" << endl;
		cout << endl << "Note : Stations with * are interchanges" << endl;
	}
}