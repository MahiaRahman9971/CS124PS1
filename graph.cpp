#include <iostream>
#include <random>
#include <tuple>
#include <vector>
#include <cmath> 
using namespace std;

// Defining a function that generates random weights chosen uniformly at random on [0, 1] 
// input: number of vertices
// output: adj list of graph with random weights
vector<pair<pair<int, int>, float> > RandWeightGraph(int n) {
    vector<pair<pair<int, int>, float> > graph(n);
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);

    // Generate edges with random weights for every pair of vertices
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            float weight = dis(gen);
            // Add edge with vertices (i, j) and random weight
            graph.push_back(make_pair(make_pair(i, j), weight));
        }
    }
    return graph;
}

// Defining a function that generates random coordinates representing vertices 
// input: number of vertices, number of dimensions
// output: list of coordinates
vector<vector<float>> randomCoords(int n, int d) {
    vector<vector<float>> coords(n);
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);

    for (int i = 0; i < n; i++) {
        vector<float> coord(d);
        for (int j = 0; j < d; j++) {
            coord[j] = dis(gen);
        }
        coords[i] = coord;
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
vector<pair<pair<int, int>, float>> generateGraph(int n, int d) {
    vector<vector<float>> RC = randomCoords(n, d);
    vector<pair<pair<int, int>, float>> graph(n);
    for (int i = 0; i < RC.size(); i++) {
        for (int j = i + 1; j < RC.size(); j++) {
            pair<int, int> vertices = make_pair(i, j);
            float edge = computeEC(RC[i], RC[j]);
            graph.push_back(make_pair(vertices, edge));
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

