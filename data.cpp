#include <iostream>
#include <vector>
#include <random>
#include "kruskals.cpp"

using namespace std;

// Function for generating points   
// input: number of dimensions, maximum number of nodes
// output: list of points (number of nodes, highest edge weight from the graph)
vector<pair<int, float>> generatePoints(int d, int maxNodes) {
    vector<pair<int, float>> points;
    for (int i = 2; i < maxNodes; i+= 10) {
        vector<vector<float>> RC = randomCoords(i, d);
        vector<pair<pair<int, int>, float>> graph = generateGraph(RC);
        float weight = highestEdgeWeight(i, graph);
        points.push_back(make_pair(i, weight));
    }
    return points;
}

// print points
// input: list of pairs of points
// output: none
void printPoints(const vector<pair<int, float>>& points) {
    for (const auto& point : points) {
        cout << point.first << " " << point.second << endl;
    }
}