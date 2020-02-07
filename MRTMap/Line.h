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

	// add pointer to station object to the stations list
	// pre : stations < 100 in size
	// post: pointer added to stations list
	bool add(Station* s);

	// line name
	// pre : none
	// post: none
	// returns the name of the line
	string Name();

	// line stations
	// pre : none
	// post: none
	// returns the list of pointers to stations objects
	List_Ptr<Station, 100> Stations();

	// check if station exist on line
	// pre : none
	// post: none
	// returns true if pointer to station object exists in station list; otherwise returns false
	bool existingStn(Station* s);

	// print function
	// pre : 2 < i < 3
	// post: none
	// print out items to console
	void print(int i);
};

