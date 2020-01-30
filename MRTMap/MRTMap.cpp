// MRTMap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include "Dictionary.h"
#include "DictionaryList.h"
#include "DictionaryStnToCode.h"
#include "List.h"
#include "Graph.h"

using namespace std;

// global variables
Dictionary codeNameDict;
DictionaryStnToCode nameCodeDict;
DictionaryList lineDict;
List stationIndexList;

void startup()
{
    ifstream f;
    string line, code, name, stationLineName;
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
            nameCodeDict.replace(name, nameCodeDict.get(name) + "/" + code);
        }
        else
        {
            nameCodeDict.add(name, code);   //DictionaryStnToCode.h
        }

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
            getline(ss, stationLineName, ',');
            cout << stationLineName << endl; //print out the different lines

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
            if (!lineDict.add(stationLineName, row)) {
                oldList = lineDict.getItem(stationLineName);
                for (int i = 0; i < row.getLength(); ++i)
                {
                    oldList.add(row.get(i));
                }
                lineDict.replace(stationLineName, oldList);
            }
            else
            {
                lineDict.add(stationLineName, row);
            }
            for (int i = row.getLength(); i > 0; --i)
            {
                row.remove(i);
            }
        }
        iterator++;
    }
}

int main()
{
    startup();
    string station;
    string line;
    List lineList;

    cout << "Enter a station: ";
    getline(cin,station);
    cout << nameCodeDict.get(station);
    cout << "Enter a line: ";
    getline(cin, line);
    lineList = lineDict.getItem(line);
    for (int i = 0; i < lineDict.getItem(line).getLength(); ++i)
    {
        cout << codeNameDict.get(lineList.get(i)) << endl;
    }

    // array of graph edges as per above diagram.
    Graph::Edge edges[] =
    {
        // (x, y, w) -> edge from x to y having weight w
        { 0, 1, 6 }, { 1, 2, 7 }, { 2, 0, 5 }, { 2, 1, 4 },
        { 3, 2, 10 }, { 4, 5, 1 }, { 5, 4, 3 }
    };

    // Number of vertices in the graph
    int N = 6;

    // calculate number of edges
    int n = sizeof(edges) / sizeof(edges[0]);

    // construct graph
    Graph graph(edges, n, N);

    graph.printList();

    return 0;
    //can delete ltr
    //for (int i = 0; 1 < stationIndexList.getLength(); i++) {
    //    if (stationIndexList.get(i) == "Jurong East") {
    //        cout << i;
    //    }
    //}
}
