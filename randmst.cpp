#include <iostream>
#include <vector>
#include <random>
#include "kruskals.cpp"

using namespace std;

// Calculate average MST edge weights
// input: number of graphs, number of dimensions, number of nodes
// output: average MST edge weights
float averageMST(int g, int d, int n) {
    float mstWeight = 0;
    for (int i = 0; i < g; i++) {
        vector<pair<pair<int, int>, float>> graph(n);
        graph = generateGraph(n, d);
        vector<float> MST = kruskal(n, d, graph);
        for (int i = 0; i < MST.size(); i++) {
            mstWeight += MST[i];
        };
    }
    return mstWeight/g;
}

// Generate points: (number of nodes, average mst weight)
// input: number of dimensions, maximum number of nodes
// output: list of points
vector<pair<int, float>> generatePointsAvgMST(int maxNodes) {
    vector<pair<int, float>> points;
    for (int i = 2; i < maxNodes; i+= 10) {
        points.push_back(make_pair(i, averageMST(1, 2, 1000)));
    }
    return points;
}

// usage: ./randmst 0 numpoints numtrials dimension
// usage: ./randmst 1
int main(int argc, char const *argv[]) {
    int default_0 = std::stoi(argv[1]);
    int numpoints = std::stoi(argv[2]);
    int numtrials = std::stoi(argv[3]);
    int dimension = std::stoi(argv[4]);

    if (default_0 == 0) {
        std::cout << averageMST(numtrials, dimension, numpoints) << " " << numpoints << " " << numtrials << " " << dimension << std::endl;
        return 0;
    }
    else{
        std::vector<int> n = {128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144};

        for(int num : n) {
            std::cout << num << ": " << averageMST(5, dimension, num) << std::endl;
        }
        return 0;
    }
}
