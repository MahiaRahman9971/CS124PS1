#include <iostream>
#include <vector>
#include <random>
#include "heap.cpp"

using namespace std;

vector<int> distance; 
vector<int> prev;
const int INF = numeric_limits<int>::max();

// Function to calculate the minimum spanning tree using Prim's algorithm
// input: list of tuples of coordinates
// output: total weight of the MST for the given graph
double Prims(vector<vector<double>> RC) {
    // Printing RC 
    cout << "RC contents:" << endl;
    for(int i = 0; i < RC.size(); ++i) {
        for(int j = 0; j < RC[i].size(); ++j) {
            std::cout << RC[i][j] << " ";
        }
        std::cout << std::endl;
    }

    int numVertices = RC.size();
    // print numVertices
    cout << "numVertices: " << numVertices << endl;

    double totalWeight = 0; 

    // Initializing vectors
    // Setting all elements of d to infinity 
    vector<double> dist(numVertices, INF);
    vector<double> stack(numVertices);
    vector<double> prev(numVertices, false);
    MinHeap heap(numVertices);

    // Starting our MST from the first vertex
    dist[0] = 0;
    heap.insertValue(0, 0);

    // Printing the contents of d
    cout << "dist contents:" << endl;
    for(int i = 0; i < dist.size(); ++i) {
        if(dist[i] == std::numeric_limits<int>::max()) {
            std::cout << "inf ";
        } else {
            std::cout << dist[i] << " ";
        }
    }

    while (heap.heapSize() != 0) {
        cout << "hello" << endl;
        int u = heap.deleteMin();
        heap.printHeap();
        stack.push_back(u);

        if (stack[u]) continue;
        stack[u] = true;

        // For every vertex in our graph
        for (int u = 0; u < numVertices; u++) {
            // For every vertex after u in our graph
            for (int v = u + 1; v < numVertices; v++) {
                // If v not in s
                double weight = computeEC(RC[u], RC[v]);
                cout << "u: " << u << endl;
                cout << "v: " << v << endl;
                cout << "weight: " << weight << endl;
                if (!stack[v] && dist[v] > weight) {
                    if (dist[v] > weight) {
                        dist[v] = weight;
                        prev[v] = u;
                        heap.insertValue(v, dist[v]);
                        heap.printHeap();
                    };
                }
            }
        }

        // Printing the contents of d
        cout << "dist contents:" << endl;
        for(int i = 0; i < dist.size(); ++i) {
            if(dist[i] == std::numeric_limits<int>::max()) {
                std::cout << "inf ";
            } else {
                std::cout << dist[i] << " ";
            }
        };
    }

    // Calculate the total weight of the MST
    for (int i = 0; i < dist.size(); i++) {
        totalWeight += dist[i];
    }  
    return totalWeight;
}