#include <iostream>
#include <random>
#include "helpers.h"

using namespace std;

// Defining a function that generates random coordinates in the form of a vector containing n vectors
// input: number of vertices, number of dimensions
// output: list of tuple coordinates
vector<vector<double> > randomCoords(int n, int d) {
   vector<vector<double> > tuples;

   // Generating random numbers from 0 to 1
   // Citation: https://stackoverflow.com/questions/48716109/generating-a-random-number-between-0-1-c
   random_device rd;
   mt19937 gen(rd());
   uniform_real_distribution<> dis(0.0, 1.0);

   // For every vertex
   for (int i = 0; i < n; i++) {
       // Generate a tuple
       vector<double> tuple;
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
// input: (RC1, RC2) - two tuples of coordinates
// output: Eculedian distance between each two points
double computeEC(vector<double> coord1, vector<double> coord2) {
   double sum = 0.0;
   for (size_t i = 0; i < coord1.size(); i++) {
       sum += pow(coord2[i] - coord1[i], 2);
   }
   double distance = sqrt(sum);
   return distance;
}