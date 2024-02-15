#include <iostream>
#include <random>
using namespace std;

class MinHeap {
    public:
        std::vector<double> heap;

        int size() {return heap.size();}

        MinHeap(std::vector<double> &heap);
        void minHeapify(int);
        void buildMinHeap(std::vector<double>);
        void insert(double);
        void extractMin();
};

// N is the index of the node we are heapifying 
void MinHeap::minHeapify(int N){
    int smallest = N;
    int left = 2 * N;
    int right = 2 * N + 1;

    if (left && heap[left] < heap[N])
        smallest = left;
    else
        smallest = N;
    if (right && heap[right] < heap[smallest])
        smallest = right;
    if (smallest != N){
        std::swap(heap[N], heap[smallest]);
        minHeapify(smallest);
    }
}

void MinHeap::buildMinHeap(std::vector<double> heap){
    for (int i = heap.size() / 2; i > 1; i--){
        minHeapify(i);
    }
}

void Insert(std::vector<double> &heap, int v){
    heap.push_back(v);
    int i = heap.size() - 1;
    heap[i] = v;
}


