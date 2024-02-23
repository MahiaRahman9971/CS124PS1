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
   int* parent; 
   int* rank; 

public:
    DisjointSet(int n) {
        parent = new int[n];
        rank = new int[n];
    }

    void makeSet(int x) {
        parent[x] = x;
        rank[x] = 0;
    }

    int find(int x) {
        int root = x;
        while (root != parent[root]) {
            root = parent[root];
        }

        while (x != root) {
            int next = parent[x];
            parent[x] = root;
            x = next;
        }
        return root;
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
vector<float> kruskal(int n, int d, vector<pair<pair<int, int>, float>>& graph) {

    vector<float> X;
    DisjointSet ds(n);
    for (int i = 0; i < n; i++) {
        ds.makeSet(i);
    }


    sort(graph.begin(), graph.end(), [](const pair<pair<int, int>, float>& a, const pair<pair<int, int>, float>& b) {
        return a.second < b.second;
    });
    
    for (const auto& edge : graph) {
        int u = edge.first.first;
        int v = edge.first.second;
        float weight = edge.second;
        if (ds.find(u) != ds.find(v)) {
            X.push_back(weight);
            ds.unite(u, v);
        }
    }
    return X;
}
