// MRTMap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include "Dictionary.h"
#include "List.h"

using namespace std;

// global variables
Dictionary codeStationDict;
List stationIndexList;

void startup()
{
    bool stationInIndex = false;
    // File pointer
    ifstream f;

    /* Add station codes and names to dictionary */
    string line, code, station;

	// open Stations.csv file
	f.open("Stations.csv");

    // get each line of the file and split into code and station
    while (getline(f, line)) {
        istringstream ss(line);
        getline(ss, code, ',');
        getline(ss, station, ',');
        codeStationDict.add(code, station); // add pair to dictionary

        // add station to index list
        for (int i = 0; i < stationIndexList.getLength(); ++i)
        {
            if (stationIndexList.get(i) == station)
            {
                stationInIndex = true;
                break;
            }
        }
        if (!stationInIndex)
        {
            stationIndexList.add(station);
        }
        stationInIndex = false;
    }

    f.close();

    /*  */
}

int main()
{
    startup();
    stationIndexList.print();
}
