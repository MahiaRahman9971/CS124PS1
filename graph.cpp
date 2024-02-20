#include <iostream>
#include <random>
#include <tuple>
#include <vector>
#include <cmath> 
using namespace std;

// Defining a function that generates random coordinates in the form of a vector containing n vectors
// input: number of vertices, number of dimensions
// output: list of coordinates
vector<vector<float>> randomCoords(int n, int d) {
    vector<vector<float>> coords;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);

    for (int i = 0; i < n; i++) {
        vector<float> coord;
        for (int j = 0; j < d; j++) {
            coord.push_back(dis(gen));
        }
        coords.push_back(coord);
    }
    return coords;
}

// Defining a function that calculates the distance between two points
// input: (coord1, coord2) - two vectors of coordinates
// output: Euclidean distance between each two points
float computeEC(const vector<float>& coord1, const vector<float>& coord2) {
    float sum = 0.0;
    for (int i = 0; i < coord1.size(); i++) {
        sum += pow(coord2[i] - coord1[i], 2);
    }
    return sqrt(sum);
}

// Generate graph from list of coordinates
// input: list of coordinates
// output: graph
vector<pair<pair<int, int>, float>> generateGraph(const vector<vector<float>>& RC) {
    vector<pair<pair<int, int>, float>> graph;
    for (int i = 0; i < RC.size(); i++) {
        for (int j = i + 1; j < RC.size(); j++) {
            float distance = computeEC(RC[i], RC[j]);
            pair<int, int> edge = make_pair(i, j);
            graph.push_back(make_pair(edge, distance));
        }
    }
    return graph;
}

// Print graph
// input: graph 
// output: none
void printGraph(const vector<pair<pair<int, int>, float>>& graph) {
    for (const auto& edge : graph) {
        cout << get<0>(get<0>(edge)) << " " << get<1>(get<0>(edge)) << " " << get<1>(edge) << endl;
    }
}

// Get the highest edge weight from the graph
// input: dimension, graph
// output: highest edge weight
float highestEdgeWeight(int n, vector<pair<pair<int, int>, float>> graph) {
    float max = 0;
    for (int i = 0; i < n; i++) {
        if (get<1>(graph[i]) > max) {
            max = get<1>(graph[i]);
        }
    }
    return max;
}