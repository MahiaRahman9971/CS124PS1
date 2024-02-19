#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>
#include <random>
#include <utility> 
#include <vector> 
using namespace std;

// graph.cpp
vector<vector<double> > randomCoords(int n, int d);
double computeEC(vector<double> coord1, vector<double> coord2);

// // heap.cpp
// class MinHeap {
//     pair<int, double> *heap; 
//     int max_size; 
//     int heap_size; 

// public:
//     MinHeap(int max_size); 

//     int heapSize();
//     void minHeapify(int i); 
//     void buildMinHeap(); 
//     int deleteMin(); 
//     void insertValue(int k, double v);
//     void printHeap(); 
// };

// mst.cpp
double Prims(vector<vector<double> > RC);
double avg(vector<vector<double> > RC, int n, int d);

#endif