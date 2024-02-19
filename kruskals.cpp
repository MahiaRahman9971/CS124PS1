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
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);
        if (xRoot == yRoot) return;

        // Union by rank
        if (rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot;
        } else if (rank[xRoot] > rank[yRoot]) {
            parent[yRoot] = xRoot;
        } else {
            parent[yRoot] = xRoot;
            rank[xRoot] += 1;
        }
    }
};


// Kruskal's algorithm to find MST
// input: number of vertices, graph
// output: weight of the MST
float kruskalMST(int n, vector<pair<pair<int, int>, float>>& graph) {
    sort(graph.begin(), graph.end(), [](const tuple<tuple<int, int>, float>& a, const tuple<tuple<int, int>, float>& b) {
        return get<1>(a) < get<1>(b);
    });

    DisjointSet ds(n);
    vector<pair<pair<int, int>, float>> mst;

    for (const auto& edge : graph) {
        int u = get<0>(get<0>(edge));
        int v = get<1>(get<0>(edge));

        if (ds.find(u) != ds.find(v)) {
            mst.push_back(edge);
            ds.unite(u, v);
        }
    }

    float mstWeight = 0;
    for (const auto& edge : mst) {
        mstWeight += get<1>(edge);
    }
    return mstWeight;
}

