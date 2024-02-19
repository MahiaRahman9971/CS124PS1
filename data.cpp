#include <iostream>
#include <vector>
#include <random>
#include "kruskals.cpp"

using namespace std;

// Function for generating points (number of nodes, mst weight)
// input: number of dimensions
// output: list of pairs of points
vector<pair<int, float>> generatePoints(int d) {
    vector<pair<int, float>> points;
    for (int i = 1; i <= 1000; i+=10) {
        vector<vector<float>> RC = randomCoords(i, d);
        vector<pair<pair<int, int>, float>> graph = generateGraph(RC);
        float weight = kruskalMST(i, graph);
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

int main() {
    printPoints(generatePoints(2));
    return 0;
}