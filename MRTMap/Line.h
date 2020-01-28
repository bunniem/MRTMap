#pragma once
#include <string>
#include "Station.h"
#include "ListStation.h"
using namespace std;
class Line
{
private:
	string lineName;
	ListStation stnList;
public:
	Line(string n);

	bool addStn(Station s);

};

