#include <iostream>
#include <random>
#include <tuple>
#include <vector>
#include <cmath> 
using namespace std;

random_device rd;
mt19937 gen(rd());
uniform_real_distribution<> dis(0.0, 1.0);

float threshold(int n, int d) {
    if (d == 0) {
        return 0.163 * exp(-0.009 * n) + 0.024;
    }
    else if (d == 2) {
        return 0.260 * exp(-0.005 * n) + 0.098;
    }
    else if (d == 3) {
        return 0.241 * exp(-0.002 * n) + 0.183;
    }
    else if (d == 4) {
        return 0.250 * exp(-0.001 * n) + 0.264;
    }
    else return 0;
}

// Defining a function that generates random coordinates representing vertices 
// input: number of vertices, number of dimensions
// output: list of coordinates
vector<vector<float>> randomCoords(int n, int d) {
    vector<vector<float>> coords(n);

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
    float edge;
    for (int i = 0; i < RC.size(); i++) {
        for (int j = i + 1; j < RC.size(); j++) {
            pair<int, int> vertices = make_pair(i, j);
            if (d == 0){
                edge = dis(gen);
            }
            else {
                edge = computeEC(RC[i], RC[j]);
            }
            if (edge < threshold(n, d)){
                graph.push_back(make_pair(vertices, edge));
            }
            
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

