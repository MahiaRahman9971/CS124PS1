#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>
#include "graph.cpp"
#include "edge_pruning.cpp"
using namespace std;

// Disjoint set data structure
class DisjointSet {
private:
   vector<int> parent, rank;

public:
   DisjointSet(int n) : parent(n), rank(n, 0) {
       for (int i = 0; i < n; ++i) {
           parent[i] = i;
       }
   }

   int find(int x) {
       if (x != parent[x]) {
           parent[x] = find(parent[x]);  // Path compression
       }
       return parent[x];
   }

   void unite(int x, int y) {
       link(find(x), find(y));
   }

   int link(int x, int y) {
       if (rank[x] > rank[y]) {
           return link(y, x);
       } 
       else if (rank[x] == rank[y]) {
            rank[y]++;
       }
       parent[x] = y;
       return y;
   };
};

// Kruskal's algorithm to find MST
// input: number of vertices, dimensions, graph
// output: list of MST edge weights
vector<float> kruskalMST(int n, int d, vector<pair<pair<int, int>, float>>& graph) {

    // Prune the graph
    float t = threshold(n, d);
    vector<float> newGraph;
    for (const auto& edge : graph) {
        if (edge.second < t) {
            newGraph.push_back(edge.second);
        }
    }

    // Sort the new graph
    sort(newGraph.begin(), newGraph.end());

    DisjointSet ds(n);
    vector<float> mst;
    for (const auto& edge : graph) {
        int u = edge.first.first;
        int v = edge.first.second;
        float weight = edge.second;
        if (ds.find(u) != ds.find(v)) {
            ds.unite(u, v);
            mst.push_back(weight);
        }
    }
    return mst;
}
