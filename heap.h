#ifndef HEAP_H
#define HEAP_H

class MinHeap {
public:
    MinHeap(int capacity) {  //ethan's notes: constructor
        this->capacity = capacity;
        heapArray= new int[capacity]; //stores the first element of the array
        keyArray= new int[capacity];
        this->size = 0;
    };

    ~MinHeap(); //ethan's notes: destructor

    void insert(int vertex, int key) {
        // ethan's notes: must call minHeapify
        heapArray[size] = vertex;
        keyArray[size] = key;
        size++;//[57, 23]
        if (size > 1) { //if two or higher in the number of vertices
            minHeapify(size);
        }
    };

    int extractMin() {
        return keyArray; //double check, should be returning the lowest key val?
    }

    void decreaseKey(int vertex, int newKey);

    bool isInMinHeap(int vertex) {
        for (int i=0; i< capacity; i++) {
            if (heapArray[i] == vertex ) {
                return true;
            }
        }
        return false;
    }

    bool isEmpty() {
        for (int i=0; i< capacity; i++) {
            if (heapArray[i] != 0) {
                return false;
            }
        }
        return true;
    };

private:
    int* heapArray;        // Heap of vertex indices
    int* keyArray;         // Corresponding key values
    int* position;         // Maps vertex to its position in heap
    int capacity;
    int size;

    void minHeapify(int idx) {

    };
};

#endif