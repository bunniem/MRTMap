#pragma once
#include "List_Ptr.h"
#include "Station.h"

class Line
{
private:
	string name;
	List_Ptr<Station, 100> stations;
	 
public:
	// constructors
	Line();
	Line(string n);

	// add station object
	bool add(Station* s);

	// line name
	string Name();

	// line stations
	List_Ptr<Station, 100> Stations();

	// check if station exist on line
	bool existingStn(Station* s);

	// print function
	void print(int i);
};

