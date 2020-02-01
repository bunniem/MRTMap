#pragma once
#include "List_Station.h"
class Line
{
private:
	string name;
	List_Station stations;
	 
public:
	// constructors
	Line();
	Line(string n);

	// add station object
	bool add(Station* s);

	// line name
	string Name();

	// line stations
	List_Station Stations();

	// print function
	void print();
};

