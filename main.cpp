#include <vector>
#include <iostream>
#include "helpers.h"

using namespace std;

double Prims(vector<vector<double>> RC); 
double avg(vector<vector<double>> RC, int n, int d); 

int main() {
    
}

// Function to calculate the average weight of the MST
// input: list of tuples of coordinates, number of vertices, number of dimensions
// output: average weight of the MST
double avg(vector<vector<double>> RC, int n, int d) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += Prims(randomCoords(n, d));
    }
    return sum / n;
    std::cout << "The average weight of the MST is: " << sum / n << std::endl;
}




// To do's: 
// 1. Fix the insert function in heap.cpp
// 2. Figure out what heap takes in, tuple or no? 
// 3. Do graph 1 
// 4. Plot values 
// 5. Give simple function that describes plot behavior 
