#include <iostream>
#include <climits>

using namespace std;

class MinHeap {
   pair<int, float> *heap;
   int max_size;
   int heap_size;

public:
   MinHeap(int max_size) {
       this->heap_size = 0;
       this->max_size = max_size;
       // Allocate memory for 1 extra element as we start indexing from 1
       this->heap = new pair<int, float>[max_size + 1];
   }

   int heapSize() {
       return heap_size;
   }

   void minHeapify(int i) {
       int left = 2 * i;
       int right = 2 * i + 1;
       int smallest = i;

       if (left <= heap_size && heap[left].second < heap[i].second)
           smallest = left;
       if (right <= heap_size && heap[right].second < heap[smallest].second)
           smallest = right;

       if (smallest != i) {
           swap(heap[i], heap[smallest]);
           minHeapify(smallest);
       }
   }

   void buildMinHeap() {
       for (int i = heap_size / 2; i >= 1; i--) {
           minHeapify(i);
       }
   }

   int deleteMin() {
       if (heap_size < 1)
           return INT_MAX;
      
       pair<int, float> min = heap[1]; // Adjust for 1-based indexing
       heap[1] = heap[heap_size];
       heap_size--;
       minHeapify(1);

       return min.first; // Return the vertex index
   }

   void insertValue(int k, float v) {
       if (heap_size == max_size) {
           cout << "\nOverflow: Could not insertValue\n";
           return;
       }

       heap_size++;
       int i = heap_size;
       heap[i] = pair<int, float>(k, v);

       while (i > 1 && heap[i / 2].second > heap[i].second) {
           swap(heap[i], heap[i / 2]);
           i = i / 2;
       }
   }

   void printHeap() {
       cout << "Heap contents:" << endl;
       // If you want to see the 0th index, start from 0
       for (int i = 1; i <= heap_size; i++) {
           cout << "(" << heap[i].first << ", " << heap[i].second << ") ";
       }
       cout << endl;
   }
};

int main() {
   MinHeap minHeap(10);
   minHeap.insertValue(1, 10);
   minHeap.insertValue(2, 20);
   minHeap.insertValue(3, 30);
   minHeap.insertValue(4, 40);
   minHeap.insertValue(5, 50);
   minHeap.insertValue(6, 60);
   minHeap.insertValue(7, 70);
   minHeap.insertValue(8, 80);
   minHeap.insertValue(9, 90);
   minHeap.insertValue(10, 100);
   minHeap.printHeap();
   cout << "The Min val is " << minHeap.deleteMin() << endl;
   minHeap.printHeap();
   return 0;
}