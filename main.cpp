#include <vector>
#include <iostream>
#include "helpers.h"
#include "heap.cpp"

using namespace std;

double Prims(vector<vector<double>> RC); 
void printCoords(const vector<vector<double>>& coords);
double avg(int n, int d); 

int main() {
    avg(10, 2);
    return 0;
    // Testing the Prims function
    // vector<vector<double> > test = randomCoords(4, 2);
    // cout << Prims(test) << endl;
    cout << Prims({{0.4603, 0.44525},{0.591422, 0.80881}, {0.516874, 0.039684}, {0.768217, 0.660744}}) << endl;

    // cout << avg(test, 4, 2) << endl;
    return 0;
}

// Function to calculate the average weight of the MST
// input: list of tuples of coordinates, number of vertices, number of dimensions
// output: average weight of the MST
double avg(int n, int d) {
double avg(vector<vector<double> > RC, int n, int d) {
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

// Errors: 
// 1. heap class in helpers.h not being recognized in other files due to linker error

// To do's: 
// 1. Fix the insert function in heap.cpp
// 2. Figure out what heap takes in, tuple or no? 
// 3. Do graph 1 
// 4. Plot values 
// 5. Give simple function that describes plot behavior 
