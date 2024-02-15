#include <iostream>
#include <random>
using namespace std;

// graph.cpp
vector<vector<double>> randomCoords(int n, int d);
double computeEC(vector<double> coord1, vector<double> coord2);

// heap.cpp
class MinHeap {
    public:
        std::vector<double> heap;

        // Constructors 
        MinHeap() {};
        MinHeap(std::vector<double> &heap): heap(heap) {};

        int size() {return heap.size();}
        void minHeapify(int i);
        void buildMinHeap();
        void insert(double n);
        double deleteMin();
};

// mst.cpp
double Prims(vector<vector<double>> RC);
double avg(vector<vector<double>> RC, int n, int d);
