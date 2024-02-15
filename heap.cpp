#include <iostream>
#include <random>
using namespace std;

// Defining the MinHeap class
// Note: This MinHeap is indexed from 1 (as mentioned in section) 
class MinHeap {
public:
    vector<double> heap;

    // ----- Constructors -----
    // Default 
    MinHeap() {
        // Inserting dummy value at index 0 to make indexing from 1
        heap.push_back(0);
    }
    // With vector
    MinHeap(vector<double> &vec) {
        heap.push_back(0); // dummy value
        for (double val : vec) {
            heap.push_back(val);
        }
        buildMinHeap();
    }

    // ----- Member Functions -----
    int size(); 
    void minHeapify(int);
    void buildMinHeap(); 
    double deleteMin();
    void insert(int);
};


// Size of the heap
int MinHeap::size() { return heap.size() - 1; };

// Heapify function
// Note: i is the index of the node we are heapifying 
void MinHeap::minHeapify(int i){
    int left = 2 * i;
    int right = 2 * i + 1;
    int smallest = i;

    if (left && heap[left] < heap[i])
        smallest = left;
    else
        smallest = i;
    if (right && heap[right] < heap[smallest])
        smallest = right;
    if (smallest != i){
        swap(heap[i], heap[smallest]);
        minHeapify(smallest);
    }
}

void MinHeap::buildMinHeap() {
    for (int i = size() / 2; i >= 1; i--) {
        minHeapify(i);
    }
}

double MinHeap::deleteMin() {
    double min = heap[1];
    heap[1] = heap[size()];
    heap.pop_back();
    minHeapify(1);
    return min;
}

// MAY NEED TO FIX THIS FUNCTION TO MAKE SURE THAT WE ARE INDEXING FROM 1
void MinHeap::insert(int v) {
    heap.push_back(v);
    int i = heap.size() - 1;
    heap[i] = v;
}
