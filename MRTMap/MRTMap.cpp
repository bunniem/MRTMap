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
Dictionary codeNameDict;
DictionaryList lineDict;
List stationIndexList;

void startup()
{
    ifstream f;
    string line, code, name;
    List row, row2;
    int iterator = 1;

	// open Stations.csv file
	f.open("Stations.csv");

    // get each line of the file and split into code and name
    while (getline(f, line)) {
        istringstream ss(line);
        getline(ss, code, ',');
        getline(ss, name, ',');
        /* Add station codes and names to dictionary */
        codeNameDict.add(code, name);

        /* Add station to index list if station does not exist on index list */
        if (!stationIndexList.exist(name))
        {
            stationIndexList.add(name);
        }
    }

    f.close();

    // open Routes.csv file
    f.open("Routes.csv");

    // get stations and its distances and add it to dictionary
    while (getline(f, line))
    {
        if (iterator % 2 == 1) // station codes
        {
            istringstream ss(line);
            getline(ss, name, ',');
            while (getline(ss, code, ','))
            {
                row.add(code);
            }
        }
        else // distances
        {
            istringstream ss(line);
            while (getline(ss, code, ','))
            {
                row2.add(code);
            }
            // add line to dictionary
            lineDict.add(name, row, row2);
        }
    }
}

int main()
{
    startup();
}
