// MRTMap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include "Dictionary.h"
#include "DictionaryList.h"
#include "List.h"

using namespace std;

// global variables
Dictionary codeStationDict;
List stationIndexList;

void startup()
{
    ifstream f;
    string line, code, station;

	// open Stations.csv file
	f.open("Stations.csv");

    // get each line of the file and split into code and station
    while (getline(f, line)) {
        istringstream ss(line);
        getline(ss, code, ',');
        getline(ss, station, ',');
        /* Add station codes and names to dictionary */
        codeStationDict.add(code, station);

        /* Add station to index list if station does not exist on index list */
        if (!stationIndexList.exist(station))
        {
            stationIndexList.add(station);
        }
    }

    f.close();
}

int main()
{
    startup();
}
