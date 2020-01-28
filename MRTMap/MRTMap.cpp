// MRTMap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include "Dictionary.h"
using namespace std;

// global variables
Dictionary codeStationDict;

void startup()
{
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

    }

    f.close();

    /*  */
}

int main()
{
    startup();
    
}
