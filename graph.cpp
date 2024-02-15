#include <iostream>
#include <random>
using namespace std;

// Defining a function that generates random coordinates in the form of a vector containing n vectors
std::vector<std::vector<double>> randomCoords(int n, int d) {
    std::vector<std::vector<double>> tuples;

    // Generating random numbers from 0 to 1
    // Citation: https://stackoverflow.com/questions/48716109/generating-a-random-number-between-0-1-c
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    // For every vertex
    for (int i = 0; i < n; i++) {
        // Generate a tuple 
        std::vector<double> tuple;
        // Add a random number to the tuple for every dimension
        // Citation: https://stackoverflow.com/questions/17984268/how-do-i-add-elements-to-an-empty-vector-in-a-loop 
        for (int j = 0; j < d; j++) {
            tuple.push_back(dis(gen));
        }
        // Add the tuple to the list of tuples
        tuples.push_back(tuple);
    }
    return tuples;
}

// Defining a function that calculates the distance between two points
// input: list of tuple coordinates
// output: adjacnecy matrix with Eculedian distance between each pair of points
std::vector<std::vector<double>> EW(std::vector<std::vector<double>> tuples) {
    // Get the number of vertices
    int n = tuples.size();
    // Create an adjacency matrix
    std::vector<std::vector<double>> adj(n, std::vector<double>(n, 0));
    // For every pair of vertices
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Calculate the distance between the two points
            double distance = 0;
            for (int k = 0; k < tuples[i].size(); k++) {
                distance += pow(tuples[i][k] - tuples[j][k], 2);
            }
            distance = sqrt(distance);
            // Add the distance to the adjacency matrix
            adj[i][j] = distance;
            adj[j][i] = distance;
        }
    }
    // unordered_map < int, string > hashmap;
    return adj;
}

