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

// print function
void Line::print()
{
	cout << endl << "Station Line : " << name << endl << endl;
	cout << "Stations on the line" << endl;
	cout << "------------------------" << endl;
	stations.print();
}