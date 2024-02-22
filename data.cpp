#include <iostream>
#include <vector>
#include <random>
#include "kruskals.cpp"

using namespace std;

// Function for generating points   
// input: number of dimensions, maximum number of nodes
// output: list of points (number of nodes, highest edge weight from the graph)
vector<pair<int, float>> generatePointsEdgePruning(int d, int maxNodes) {
    vector<pair<int, float>> points;
    for (int i = 2; i < maxNodes; i+= 10) {
        vector<vector<float>> RC = randomCoords(i, d);
        vector<pair<pair<int, int>, float>> graph = generateGraph(RC);
        vector<float> MST = kruskal(i, d, graph);
        float weight = highestEdgeWeight(MST);
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

// function for calculating average MST edge weights
// input: number of graphs, number of dimensions, number of nodes
// output: average MST edge weights
float averageMST(int g, int d, int n) {
    float mstWeight = 0;
    for (int i = 0; i < g; i++) {
        vector<vector<float>> RC = randomCoords(n, d);
        vector<pair<pair<int, int>, float>> graph = generateGraph(RC);
        vector<float> MST = kruskal(n, d, graph);

        for (int i = 0; i < MST.size(); i++) {
            mstWeight += MST[i];
        };
    }
    return mstWeight/g;
}

// function for generating points: (numbr of nodes, average mst weight)
// input: number of dimensions, maximum number of nodes
// output: list of points
vector<pair<int, float>> generatePointsAvgMST(int d, int maxNodes) {
    vector<pair<int, float>> points;
    for (int i = 2; i < maxNodes; i+= 10) {
        points.push_back(make_pair(i, averageMST(10, d, i)));
    }
    return points;
}

int main(int argc, char const *argv[])
{
    printPoints(generatePointsAvgMST(2, 100));
}
