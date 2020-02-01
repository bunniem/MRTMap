// MRTMap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <algorithm>    // ONLY used for converting upper/lowercase string
#include <sstream>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include "Dictionary.h"
#include "DictionaryList.h"
#include "DictionaryStnToCode.h"
#include "List.h"
#include "Graph.h"
#include "Station.h"
#include "Line.h"
#include "Connection.h"
#include "Dictionary_Station.h"
#include "Dictionary_Line.h"

using namespace std;

// new global variables
List_Station stnList;
Dictionary_Station stnNameToStationDict;
Dictionary_Line stnLineToLineDict;
Dictionary stnCodeToStnNameDict;

// global variables
Dictionary codeNameDict;
DictionaryStnToCode nameCodeDict;
DictionaryList lineDict;
List stationIndexList;

// converts a given string to lowercase
string toLowercase(string s)
{
	for_each(s.begin(), s.end(), [](char& c) {
		c = tolower(c);
		});
	return s;
}

// new startup structure
void startup2()
{
	string stnCode, stnName, stnLineName, dist, line;
	List_Station stnLineList;
	ifstream f;
	int lineNum = 1;

	/* We use the data in stations.csv to convert station codes to names,
	as well as converting station names to station objects. We will also
	add station objects to a list with all stations of the network */

	// open Stations.csv file
	f.open("Stations.csv");

	// get each line of file
	while (getline(f, line))
	{
		// split into station code and station name
		istringstream s(line);
		getline(s, stnCode, ',');
		getline(s, stnName, ',');

		// add stnCode (as key) and stnName (as item) to dictionary
		stnCodeToStnNameDict.add(stnCode, stnName);

		// add stnNameLowercase (as key) and Station (as item) to dictionary

		// check if station in dictionary
		if (stnNameToStationDict.get(toLowercase(stnName)) == nullptr) // not found
		{
			Station* newStn = new Station(stnName, stnCode);	// create new station
			stnNameToStationDict.add(toLowercase(stnName), newStn);	// add station to dictionary
			stnList.add(newStn);	// add station to station list
		}
		else // found
		{
			Station* existingStn = stnNameToStationDict.get(toLowercase(stnName)); // get existing station
			existingStn->addCode(stnCode); // add in new station code
		}
	}

	f.close();

	/* We will use Routes.csv to associate stations to specific lines,
	and to add the connections (distances) to the stations */

	// open Routes.csv
	f.open("Routes.csv");

	while (getline(f, line))
	{
		if (lineNum % 2 == 1) // station line name and station codes line
		{
			// split into station line name and station code
			istringstream s(line);
			getline(s, stnLineName, ',');

			// check if station line in directory

			if (stnLineToLineDict.get(toLowercase(stnLineName)) == nullptr) // not found
			{
				Line* newStnLine = new Line(stnLineName); // create new station line
				stnLineToLineDict.add(toLowercase(stnLineName), newStnLine); // add station line to dictionary
			}
			Line* stnLine = stnLineToLineDict.get(toLowercase(stnLineName)); // get existing station line

			// add stations to a line
			while (getline(s, stnCode, ','))
			{
				stnName = stnCodeToStnNameDict.get(stnCode); // get station name using station code
				Station* stn = stnNameToStationDict.get(toLowercase(stnName));
				stnLine->add(stn); // add station to station line
				stnLineList.add(stn); // add line of stations to a list for adding distance later
			}
		}
		else // distance between stations line
		{
			// split into different distances
			istringstream s(line);

			// connection of first station
			Station* firstStn = stnLineList.get(0); // get first station
			getline(s, dist, ',');
			Connection* firstConn = new Connection(stnLineList.get(1), stoi(dist)); // create new connection with front station
			firstStn->addConnection(firstConn); // add connection to first station

			// connections of stations in between
			for (int i = 1; i < stnLineList.getLength()-1; ++i)
			{
				Station* bwStn = stnLineList.get(i); // stations in between
				Connection* frontConn = new Connection(stnLineList.get(i - 1), stoi(dist)); // create new connection with prev station
				bwStn->addConnection(frontConn); // add connection
				getline(s, dist, ','); // get distance to next station
				Connection* backConn = new Connection(stnLineList.get(i + 1), stoi(dist)); // create new conneciton with nxt station
				bwStn->addConnection(backConn); // add connection
			}
			
			// connection of last station
			Station* lastStn = stnLineList.get(stnLineList.getLength() - 1); // get last stations
			Connection* lastConn = new Connection(stnLineList.get(stnLineList.getLength()-2), stoi(dist));
			lastStn->addConnection(lastConn);

			// clear stnLineList for next station
			for (int i = stnLineList.getLength(); i > 0; --i)
			{
				stnLineList.remove(i-1);
			}
		}
		lineNum++;
	}

}

void startup()
{
	fstream f;
	string line, code, name, stationLineName, dist;
	List oldList;
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
		// cout << code << endl;
		//cout << name << endl;
		codeNameDict.add(code, name);   //Dictionary.h
		if (!nameCodeDict.add(name, code)) {
			nameCodeDict.replacecode(name, nameCodeDict.getcode(name) + "/" + code);
			nameCodeDict.replaceinterchange(name, true);
			//add into interchange csv
		}
		else
		{
			nameCodeDict.add(name, code);   //DictionaryStnToCode.h
		}

		/* Add station to index list if station does not exist on index list */
		if (!stationIndexList.exist(name))
		{
			stationIndexList.add(name); //adding all the station name into stationIndexList
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
			getline(ss, stationLineName, ',');
			//cout << stationLineName << endl; //print out the different lines

			while (getline(ss, code, ','))
			{
				row.add(code);
				//break;
			}
		}
		else // distances
		{
			istringstream ss(line);
			while (getline(ss, dist, ','))
			{
				row2.add(dist);
				cout << dist << endl;
			}
			// add line to dictionary
		}
		iterator++;
		if (!lineDict.add(stationLineName, row)) {  //this check is used for the two EWL and CCL
			oldList = lineDict.getItem(stationLineName);
			for (int i = 0; i < row.getLength(); ++i)
			{
				oldList.add(row.get(i));
			}
			lineDict.replace(stationLineName, oldList);
		}
		for (int i = row.getLength(); i > 0; --i)
		{
			row.remove(i);
		}

	}
	for (int i = 0; i < row2.getLength(); i++) {
		cout << row2.get(i) << endl;
	}

}

//
//bool addStationCodeToRoute(string code) {
//	ofstream f;
//	f.open("Routes.csv");
//}

void addToCSV()
{
	string line, code, stnCode, name, stationLineName, line1, stationline, frontcode, backcode, frontdist, backdist, station, dist;
	List row, row2, lineList;
	int iterator = 1;

	ifstream originalCSV;
	ofstream replacementCSV;
	originalCSV.open("Routes.csv");
	replacementCSV.open("temp.csv", ios::in);

	while (getline(originalCSV, line))
	{
		if (iterator % 2 == 1) // station codes
		{
			istringstream ss(line);
			getline(ss, stationLineName, ',');
			if (stationLineName == stationline) { //So that we know which line to add the station to
				cout << stationLineName << endl;

				//for (int i = 0; i < )
			}
		}
		else // distances
		{
			istringstream ss(line);
			while (getline(ss, dist, ','))
			{
				row2.add(dist);
			}
			// add line to dictionary
		}

	}
}



int main()
{
	startup2();
	stnList.get(0)->print();



	//startup();
	//fstream f;
	//string line, code, stnCode, name, stationLineName, line1, stationline, frontcode, backcode, frontdist, backdist, station;
	//List row, row2, lineList;
	//int iterator = 1;

	//int option;


	//while (true)
	//{
	//	// MAIN MENU
	//	cout << "\nMRT MAIN MENU\n---------------------------\n";
	//	cout << "[1] Display all stations in a given line\n[2] Display station information\n[3] Add a new station on a given line\n";
	//	cout << "[4] Display a route and its price, given the source and destination\n[5] Remove a station\n[6] Create a line\n";
	//	cout << "[0] Exit program\n";
	//	cout << "---------------------------\nSelect an option: ";
	//	cin >> option;
	//	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	//	// Functions
	//	switch (option)
	//	{
	//	case 0:
	//		return 0;
	//	case 1:
	//		cout << "Enter a line: ";
	//		getline(cin, line);
	//		lineList = lineDict.getItem(line);
	//		for (int i = 0; i < lineDict.getItem(line).getLength(); ++i)
	//		{
	//			cout << codeNameDict.get(lineList.get(i)) << endl; //printing the different line
	//		}
	//		break;
	//	case 2:
	//		cout << "Enter a station: ";
	//		getline(cin, station);
	//		cout << "Station Code: " << nameCodeDict.getcode(station) << endl;
	//		cout << "Station Name: " << station << endl;
	//		cout << "Interchange: " << boolalpha << nameCodeDict.getinterchange(station);
	//		break;
	//	case 3:
	//		cout << "\nStation Details\n---------------------------\nEnter a Station Line: ";
	//		getline(cin, stationline);
	//		cout << "Enter a Station Name: ";
	//		cin >> station;
	//		cout << "Enter a Station Code: ";
	//		cin >> stnCode;
	//		cout << "\nLocation to add station\n---------------------------\nEnter the Front Station Code: "; //if front station empty only prompt for the back distance
	//		cin >> frontcode;			
	//		cout << "Enter the Back Station Code: "; //if back station empty only prompt for the front distance
	//		cin >> backcode;

	//		cout << "Enter the distance from " << frontcode << " to " << stnCode << ": ";
	//		cin >> frontdist;

	//		cout << "Enter the distance from " << stnCode << " to " << backcode << ": ";
	//		cin >> backdist;

	//		// open Routes.csv file
	//		ifstream originalCSV;
	//		fstream replacementCSV;
	//		char replacement[100] = "C:/Users/User/source/repos/MRTMap/MRTMap/temp.csv";
	//		char constantcsv[100] = "C:/Users/User/source/repos/MRTMap/MRTMap/Routes.csv";
	//		originalCSV.open("Routes.csv");
	//		replacementCSV.open(replacement, ios::out);
	//		int addedNewLine = 0;

	//		// get stations and its distances and add it to dictionary
	//		while (getline(originalCSV, line))
	//		{
	//			if (iterator % 2 == 1) // station codes
	//			{
	//				istringstream ss(line);
	//				getline(ss, stationLineName, ',');
	//				if (stationLineName == stationline) { //So that we know which line to add the station to
	//					//cout << stationLineName << endl; //print out the different lines
	//					if (frontcode == "NIL") { //means adding to the front
	//						row.add(stnCode); //add newly created code 
	//						while (getline(ss, code, ','))
	//						{
	//							row.add(code);
	//						}
	//					}
	//					else if (backcode == "NIL") { //means adding to the back
	//						while (getline(ss, code, ','))
	//						{
	//							row.add(code); 
	//						}
	//						row.add(stnCode); //add newly created code 
	//					}
	//					else { //add in the middle
	//						while (getline(ss, code, ','))
	//						{
	//							if (code == backcode) { //doesnt add the stncode
	//								row.add(stnCode); //add newly created code 
	//							}
	//							cout << code;
	//							row.add(code);
	//						}
	//					}
	//					//while (getline(ss, code, ','))
	//					//{
	//					//	row.add(code);
	//					//}
	//					addedNewLine = 1;
	//				}
	//				//try to delete the line and add the new row to that line or we can create a new excel to repopulate that excel with data
	//				//from the old excel and add the new row in it.

	//			}
	//			else // distances
	//			{
	//				istringstream ss(line);
	//				while (getline(ss, code, ','))
	//				{
	//					row2.add(code);
	//				}
	//				// add line to dictionary
	//			}
	//			iterator++;
	//			if (addedNewLine == 0) {
	//				replacementCSV << line << endl; //adding the line to the new csv
	//			}
	//			else {
	//				
	//				//adding the row into the specific line in the new csv
	//				replacementCSV << stationline;
	//				for (int i = 0; i < row.getLength(); i++) {
	//					replacementCSV << "," << row.get(i);
	//				}
	//				replacementCSV << endl;
	//				addedNewLine = 0;
	//			}

	//			rename(replacement, constantcsv);
	//			//if (line[0] == stationline) {

	//			//}

	//		}
	//		originalCSV.close();
	//		replacementCSV.close();
	//		//try to delete the line and add the new row to that line or we can create a new excel to repopulate that excel with data
	//		//from the old excel and add the new row in it.


	//		//fstream f;
	//		//int iterator = 1;
	//		//string stationLine;
	//		//f.open("Routes.csv");

	//		//while (getline(f, line1)) {
	//		//	if (iterator % 2 == 1) // station codes
	//		//	{
	//		//		stringstream ss(line);
	//		//		getline(ss, stationLine, ',');
	//		//		cout << stationLine << endl;
	//		//	}
	//		//	iterator++;
	//		//}




	//	//case 4:
	//	//case 5:

	//	}
	//}

















 //   // array of graph edges as per above diagram.
 //   Edge edges[] =
 //   {
 //       // (x, y, w) -> edge from x to y having weight w
 //       { 0, 1, 6 }, { 1, 2, 7 }, { 2, 0, 5 },
 //       { 3, 2, 10 }, { 5, 4, 3 }
 //   };

 //   // Number of vertices in the graph
 //   int N = 6;

 //   // calculate number of edges
 //   int n = sizeof(edges) / sizeof(edges[0]);

 //   // construct graph
 //   Graph graph(edges, n, N);

 //   graph.printList();

 //   return 0;
 //   //can delete ltr
 //   //for (int i = 0; 1 < stationIndexList.getLength(); i++) {
 //   //    if (stationIndexList.get(i) == "Jurong East") {
 //   //        cout << i;
 //   //    }
 //   //}
}
