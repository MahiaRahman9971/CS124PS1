#include <iostream>
#include <random>
#include "helpers.h"

using namespace std;

vector<int> distance; 
vector<int> prev;
int totalWeight = 0;

// Function to calculate the minimum spanning tree using Prim's algorithm
// input: list of tuples of coordinates
// output: total weight of the MST for the given graph
double Prims(vector<vector<double>> RC) {
        int size = RC.size();

        // Initializing vectors
        // Setting all elements of d to infinity 
        vector<int> d(size, numeric_limits<int>::max());
        vector<int> s(size);
        vector<int> prev(size);
        MinHeap h;

        // Starting our MST from the first vertex
        d[0] = 0;
        //we don't really need null, and it causing issues with int being set to null
        // we can solve by making prev a vector of pointers but we don't need to know prevs
        // prev[0] = NULL;
        h.insert({0, 0.0});


        while (h.size() != 0) {
            // u is the index of the vertex with the smallest distance
            // CONFUSED ABOUT HOW TO TAKE CARE OF U, WE INSERT TUPLES INTO OUR HEAP??
            // SO DELETEMIN MUST RETURN WHAT?? 
            int u = h.deleteMin();
            s.push_back(u);

            // For every vertex in our graph
            for (int u = 0; u < size; u++) {
                // For every vertex after u in our graph
                for (int v = u + 1; v < size - 1; v++) {
                    // If v not in s
                    if (find(s.begin(), s.end(), v) == s.end()) {
                        int weight = computeEC(RC[u], RC[v]);
                        if (d[v] > weight) {
                            d[v] = weight;
                            // prev[v] = u;
                            h.insert({v, d[v]});
                        };
                    }
                }
            }

            // Calculate the total weight of the MST
            for (int i = 0; i < size; i++) {
                totalWeight += d[i];
            }  
        }
        return totalWeight;
    }