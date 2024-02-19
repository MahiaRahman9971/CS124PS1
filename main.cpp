#include <iostream>
#include <vector>
#include <random>
#include "kruskals.cpp"

using namespace std;


// int main() {
//     int n = 5;  // Number of vertices
//     int d = 2;  // Number of dimensions
//     vector<vector<float>> RC = randomCoords(n, d);
//     // vector<vector<float>> RC = {{0.4603, 0.44525},{0.591422, 0.80881}, {0.516874, 0.039684}, {0.768217, 0.660744}};
//     vector<pair<pair<int, int>, float>> graph = generateGraph(RC);

//     // Apply Kruskal's algorithm
//     float weight = kruskalMST(n, graph);
//     cout << weight << endl;

//     return 0;
// }

// Function to calculate the average weight of the MST
// input: list of tuples of coordinates, number of vertices, number of dimensions
// output: average weight of the MST
// float avg(vector<vector<float> > RC, int n, int d) {
//    float sum = 0;
//    for (int i = 0; i < n; i++) {
//        sum += Prims(randomCoords(n, d));
//    }
//    return sum / n;
  
// }


// Errors:
// 1. heap class in helpers.h not being recognized in other files due to linker error


// To do's:
// 1. Fix the insert function in heap.cpp
// 2. Figure out what heap takes in, tuple or no?
// 3. Do graph 1
// 4. Plot values
// 5. Give simple function that describes plot behavior
