#include "Line.h"

// constructor
Line::Line(string n)
{
	lineName = n;
}

// add station to line
bool Line::addStn(Station s)
{
	stnList.add(s);
}