#include <vector>
#include <iostream>
#include "helpers.h"

using namespace std;

double Prims(vector<vector<double>> RC); 
void printCoords(const vector<vector<double>>& coords);
double avg(int n, int d); 

int main() {
    avg(10, 2);
    return 0;
}

// Function to calculate the average weight of the MST
// input: list of tuples of coordinates, number of vertices, number of dimensions
// output: average weight of the MST
double avg(int n, int d) {
    double sum = 0;
    // for (int i = 0; i < n; i++) {
        sum = Prims(randomCoords(n, d));
    // }
    printCoords(randomCoords(n, d));
    std::cout << "The output of Prim is: " << sum << std::endl;
    std::cout << "The average weight of the MST is: " << sum / n << std::endl;
    return sum / n;
}


// Function to print the coordinates
void printCoords(const vector<vector<double>>& coords) {
    for (const auto &vec : coords) {
        cout << "(";
        for (size_t i = 0; i < vec.size(); ++i) {
            cout << vec[i];
            if (i < vec.size() - 1) cout << ", ";
        }
        cout << ")" << endl;
    }
}


// To do's: 
// 1. Fix the insert function in heap.cpp
// 2. Figure out what heap takes in, tuple or no? 
// 3. Do graph 1 
// 4. Plot values 
// 5. Give simple function that describes plot behavior 
