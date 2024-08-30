#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <climits>
using namespace std;

class Vertex
{
public:
    string name; // name of current location
    map<string, int> neighbors; // Neighboring locations and their distances

    Vertex()
    {
        name = "n/a";
    }

    void AddNeighbor(string n, int d)
    {
        // add a neighbor (with name n and distance d) to neighbors
        neighbors[n] = d;
    }
};

class Graph
{
private:
    map<string, Vertex> locations; // all cities and their neighbors (i.e. adjacencies) in the graph    

public:
    Graph()
    {
    }

    Graph(string file = "distances.txt"){
        if(file == ""){
            return;
        }

        // Read road network data from a file
        ifstream inputFile(file);
        if (!inputFile) {
            cout << "Error: Unable to open input file." << endl;
            return;
        }

        // Parse the input file
        string sourceLocation, destLocation;
        int distance;
        while (inputFile >> sourceLocation >> destLocation >> distance) {
            locations[sourceLocation].name = sourceLocation;
            locations[destLocation].name = destLocation;
            locations[sourceLocation].neighbors[destLocation] = distance;
        }
        inputFile.close();
    }

    void ShowLocationInfo(){
        cout << "Locations:" << endl;
        for (const auto& pair : locations) {
            cout << pair.first << ": ";
            for (const auto& neighbor : pair.second.neighbors) {
                cout << neighbor.first << "(" << neighbor.second << "), ";
            }
            cout << endl;
        }        
    }

    void FindRoute(){
        queue<string> locationList;
        BuildLocationList(locationList);

        while (locationList.size() > 1) {
            map<string, string> shortestPath;
            map<string, int> distance;
            string src = locationList.front();
            locationList.pop();
            string des = locationList.front();

            if (src == des) continue;

            // If src and des are neighbor and the shortest distance is found, we can use it directly instead of calling fct again
            if (shortestPath.find(des) != shortestPath.end() && shortestPath.at(des) == src ||
            shortestPath.find(src) != shortestPath.end() && shortestPath.at(src) == des) {
                cout << "\nShortest Route from " << src << " to " << des << ":\n";
                cout << "Distance: " << distance.at(des) << " kilometers\n";
            } else {
                int totalDistance = dijkstra(shortestPath, distance, src, des);

                if (totalDistance == 0) { // no connection
                    cout << "\nNo route exists for the given locations.\n";
                } else {
                    cout << "\nShortest Route from " << src << " to " << des << ":\n";
                    cout << "Distance: " << totalDistance << " kilometers\n";

                    // Print the path
                    cout << "Route: ";
                    PrintPath(shortestPath, src, shortestPath.at(des));
                    cout << des << endl;
                }
            }
        }
    }

    void BuildLocationList(queue<string>& locationList) {
        string src;
        cout << "Enter the source location: ";
        cin >> src;
        locationList.push(src);

        if (locations.find(src) == locations.end()) {
            cerr << src << " does not existed.\n";
            return;
        }

        string des;
        cout << "Enter the destination location(s): ";
        cin >> des;

        int start;
        int next = -1;
        string tmp;

        do {
            start = next + 1;
            next = des.find(',', start);

            if (next == -1)
                tmp = des.substr(start);
            else
                tmp = des.substr(start, next - start);

            if (locations.find(tmp) == locations.end()) {
                cerr << tmp << " does not existed.\n";
                return;
            }

            locationList.push(tmp);

        } while (next != -1);
    }


    int dijkstra(map<string, string>& shortestPath, map<string, int>& distance, const string& src, const string& des) {
        auto comp = [](const pair<string, int>& left, const pair<string, int>& right) {
            return left.second < right.second;
        };

        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> pq(comp);
        pq.push({src, 0});

        //reset 2 maps
        shortestPath.clear();
        distance.clear();

        distance[src] = 0;

        while (!pq.empty()) {
            string cur = pq.top().first;
            pq.pop();

            for (auto adjCity : locations[cur].neighbors) {
                string next = adjCity.first;
                int tmpDistance = distance.at(cur) + adjCity.second;

                if (distance.find(next) == distance.end() || tmpDistance < distance.at(next)) {
                    distance[next] = tmpDistance;
                    pq.push(adjCity);
                    shortestPath[next] = cur;
                }
            }
        }

        return distance[des]; // return 0 if no connection
    }


    void PrintPath(const map<string, string>& shortestPath, const string& src, const string& des) {
        // All pre-conditions are checked before
        if (src == des) {
            cout << src << " -> ";
            return;
        }

        PrintPath(shortestPath, src, shortestPath.at(des));
        cout << des << " -> ";
    }

};

#endif