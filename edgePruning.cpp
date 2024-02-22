#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <fstream>
#include "kruskals.cpp"
using namespace std;

// Get the highest edge weight from the graph
// input: list of edges
// output: highest edge weight
float highestEdgeWeight(vector<float> edgeList) {
    float max = 0;
    for (const auto& edge : edgeList) {
        if (edge > max) {
            max = edge;
        }
    }
    return max;
}

// Function for generating points   
// input: number of dimensions, maximum number of nodes
// output: list of points (number of nodes, highest edge weight from the graph)
vector<pair<int, float>> generatePointsEdgePruning(int maxNodes, int d) {
    vector<pair<int, float>> points;
    for (int i = 0; i <= maxNodes; i += 10) {
        vector<pair<pair<int, int>, float>> graph = generateGraph(i, d);
        vector<float> MST = kruskal(i, d, graph);
        float weight = highestEdgeWeight(MST);
        points.push_back(make_pair(i, weight));
    }
    return points;
}

// print points
// input: list of pairs of points
// output: none
void outputPointsTextFile(const vector<pair<int, float>>& points) {
    // Create and open a text file
    ofstream MyFile("2DPruning.txt");

    for (const auto& point : points) {
        // Write to the file
        MyFile << point.first << " " << point.second << endl;
    }

    // Close the file
    MyFile.close();
}

// function for determining threshold 
// input: number of nodes, dimensions
// output: threshold


int main() {
    // int n = 4;  
    // int d = 2;  
    // // vector<vector<float>> RC = randomCoords(n, d);
    // vector<vector<float>> RC = {{0.4603, 0.44525},{0.591422, 0.80881}, {0.516874, 0.039684}, {0.768217, 0.660744}};
    // vector<pair<pair<int, int>, float>> graph = generateGraph(RC);
    // printGraph(graph);

    // // Apply Kruskal's algorithm
    // vector<float> weight = kruskal(n, d, graph);

    // float totalWeight = 0;
    // // Print the MST edge weights
    // for (const auto& w : weight) {
    //     totalWeight += w;
    // }

    // cout << "Total weight of MST: " << totalWeight << endl;

    outputPointsTextFile(generatePointsEdgePruning(10000, 2));

    return 0;
}

// get rid of the get<>