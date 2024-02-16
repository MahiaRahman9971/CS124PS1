#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

// Defining the MinHeap class
// Note: This MinHeap is indexed from 1
class MinHeap {
public:
    vector<pair<int, double>> heap; // Using pair instead of tuple for simplicity

    // ----- Constructors -----
    // Default
    MinHeap() {
        // Inserting dummy value at index 0 to make indexing from 1
        heap.push_back(make_pair(0, 0.0)); // dummy value
    }
    // With vector of pairs
    MinHeap(vector<pair<int, double>> &vec) {
        heap.push_back(make_pair(0, 0.0)); // dummy value
        for (auto &val : vec) {
            heap.push_back(val);
        }
        buildMinHeap();
    }

    // ----- Member Functions -----
    int size();
    void minHeapify(int);
    void buildMinHeap();
    int deleteMin();
    void insert(pair<int, double>);
};

// Size of the heap
int MinHeap::size() { return heap.size() - 1; }

// Heapify function
void MinHeap::minHeapify(int i) {
    int left = 2 * i;
    int right = 2 * i + 1;
    int smallest = i;

    if (left <= size() && heap[left].second < heap[i].second)
        smallest = left;
    if (right <= size() && heap[right].second < heap[smallest].second)
        smallest = right;
    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        minHeapify(smallest);
    }
}

void MinHeap::buildMinHeap() {
    for (int i = size() / 2; i >= 1; i--) {
        minHeapify(i);
    }
}

int MinHeap::deleteMin() {
    pair<int, double> min = heap[1];
    heap[1] = heap[size()];
    heap.pop_back();
    minHeapify(1);
    return min.first; // Return the vertex index
}

void MinHeap::insert(pair<int, double> v) {
    heap.push_back(v);
    int i = heap.size() - 1;

    while (i > 1 && heap[i / 2].second > heap[i].second) {
        swap(heap[i], heap[i / 2]);
        i = i / 2;
    }
}
