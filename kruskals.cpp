#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>
#include "graph.cpp"
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
       } else {
           if (rank[x] == rank[y]) {
               rank[y]++;
           }
       }
       parent[x] = y;
       return y;
   };
};

// Kruskal's algorithm to find MST
// input: number of vertices, graph
// output: weight of the MST
float kruskalMST(int n, vector<pair<pair<int, int>, float>>& graph) {
   sort(graph.begin(), graph.end(), [](const pair<pair<int, int>, float>& a, const pair<pair<int, int>, float>& b) {
       return a.second < b.second;
   });

   DisjointSet ds(n);
   float MSTweight = 0.0;
   for (const auto& edge : graph) {
       int u = edge.first.first;
       int v = edge.first.second;
       float w = edge.second;
       if (ds.find(u) != ds.find(v)) {
           MSTweight += w;
           ds.unite(u, v);
       }
   }
   return MSTweight;
}

// int main() {
//     int n = 5;  // Number of vertices
//     int d = 2;  // Number of dimensions
//     // vector<vector<float>> RC = randomCoords(n, d);
//     vector<vector<float>> RC = {{0.4603, 0.44525},{0.591422, 0.80881}, {0.516874, 0.039684}, {0.768217, 0.660744}};
//     vector<pair<pair<int, int>, float>> graph = generateGraph(RC);

//     // Apply Kruskal's algorithm
//     float weight = kruskalMST(n, graph);
//     cout << weight << endl;

//     return 0;
// }