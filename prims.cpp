#include <iostream>
#include <random>
#include "helpers.h"

using namespace std;

vector<int> distance; 
vector<int> prev;

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
        prev[0] = NULL;
        h.insert((0, 0));


        while (h.size() != 0) {
            // u is the index of the vertex with the smallest distance
            // CONFUSED ABOUT HOW TO TAKE CARE OF U, WE INSERT TUPLES INTO OUR HEAP??
            // SO DELETEMIN MUST RETURN WHAT?? 
            int u = h.deleteMin();
            s.push_back(u);

            // For every vertex in our graph
            for (int vu = 0; vu < size; vu++) {
                // For every vertex after vu in our graph
                for (int vv = vu + 1; vv < size; vv++) {
                    // If vv not in s
                    if (find(s.begin(), s.end(), vv) == s.end()) {
                        int weight = computeEC(RC[vu], RC[vv]);
                        if (d[vv] > weight) {
                            d[vv] = weight;
                            prev[vv] = u;
                            h.insert((vv, d[vv]));
                        };
                    }
                }
            }

            // Calculate the total weight of the MST
            int totalWeight = 0;
            for (int i = 0; i < size; i++) {
                totalWeight += d[i];
            }
            return totalWeight;
        }
    }