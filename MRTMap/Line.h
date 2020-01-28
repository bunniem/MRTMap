#pragma once
#include <string>
#include "Station.h"
using namespace std;
class Line
{
private:
	string lineName;
	ListStation<Station>stnList;
public:
	Line(string n);

	bool addStn(Station s);

};

