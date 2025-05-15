#ifndef HEAP_H
#define HEAP_H

class MinHeap {
public:
    MinHeap(int capacity) {  //Constructor of the min heap and all the necessary arrays
        this->capacity = capacity;
        heapArray= new int[capacity]; //Stores the first element of the array
        keyArray= new int[capacity];
        visited= new int[capacity];
        position= new int[capacity];
        this->indexOfVisited=0;
        this->size = 0;
    };

    ~MinHeap();

    void insert(int vertex, int key) {  //Changes the values of the arrays accordingly based on the vertex and weight
        if (key==0) { //Goes with the assumption that none of the weights will be 0 between vertices
            keyArray[size]=key;
            heapArray[size]=vertex;
            visited[size]=vertex;
            size++;
        }
        else {
            heapArray[size] = vertex;
            keyArray[size] = key;
            size++;
        }
    };

    int extractMin() { //Returns the value with the lowest weight
        int tempMin=keyArray[0];
        for (int i=0; i < size; i++) {
            if (keyArray[i] < tempMin) {
                tempMin = keyArray[i];
            }
        }
        return tempMin;
    }

    int extractMinIndex() { //Returns the index with the lowest weight
        int minIndex=0;
        int tempMin=keyArray[0];
        for (int i=0; i < size; i++) {
            if (keyArray[i] < tempMin) {
                tempMin = keyArray[i];
                minIndex = i;
            }
        }
        return minIndex;
    }

    int extractFromHeap(int index) { //Returns the value at a particular given index within heapArray
        return heapArray[index];
    }

    int extractVisited(int index) { //Returns the value at a particular given index within visited array
        return visited[index];
    }

    void decreaseKey(int vertex, int newKey) { //Sets the value at a particular given index with newKey
        keyArray[vertex] = newKey;
    };

    void addToVisited(int value) { //Adds the given value to the visited array
        visited[indexOfVisited] = value;
        indexOfVisited++;
    }

    bool isInMinHeap(int vertex) { //Peruses through every element within the heapArray and returns true if a match has
        //been found with the given vertex input
        for (int i=0; i< capacity; i++) {
            if (heapArray[i] == vertex ) {
                return true;
            }
        }
        return false;
    }

    bool isInPositionArray(int vertex) { //Peruses through every element within the position array and returns true if
        //a match has been found with the given vertex input
        for (int i=0; i< capacity; i++) {
            if (position[i] == vertex ) {
                return true;
            }
        }
        return false;
    }

    bool isEmpty() { //Peruses through every element within the heap array and returns false if a value not equal to
        //default 0 is found
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
    int* visited;        // Array of all the visited vertices

    int capacity;
    int size;
    int indexOfVisited;        // Keeps track of index for the visited array

    void minHeapify(int idx) { //Helper method to reset the values within the arrays for the next row in adjacency matrix
        for (int i=0; i < idx; i++) {
            keyArray[i] = 0;
            heapArray[i] = 0;
            position[i] = 999;
        }
    }
};

#endif