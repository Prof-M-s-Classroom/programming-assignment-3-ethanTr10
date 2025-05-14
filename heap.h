#ifndef HEAP_H
#define HEAP_H

class MinHeap {
public:
    MinHeap(int capacity) {  //ethan's notes: constructor
        this->capacity = capacity;
        heapArray= new int[capacity]; //stores the first element of the array
        keyArray= new int[capacity];
        visited= new int[capacity];
        unvisited= new int[capacity];
        position= new int[capacity];
        this->totalCost=0;
        this->indexOfVisited=0;
        this->size = 0;
        this->indexOfMinHeap=0;
    };

    ~MinHeap(); //ethan's notes: destructor

    void insert(int vertex, int key) {
        // ethan's notes: must call minHeapify
        if (key==0) { //goes with the assumption that none of the weights will be 0 between vertices
            keyArray[size]=key; //keys should be the weight
            heapArray[size]=vertex; //
            //position[size]=vertex;
            visited[sizeForVisitedArray]=vertex;
            sizeForVisitedArray++;
            size++;
        }
        else {
            //position[size]=vertex;
            heapArray[size] = vertex;
            keyArray[size] = key;
            size++;//[57, 23]
        }
        if (size%4==0) { //if two or higher in the number of vertices
            minHeapify(size);
        }


    };

    void insertInMinHeap(int vertex) {
        heapArray[indexOfMinHeap] = vertex;
    }

    void insertInPositionArray(int vertex) {
        position[indexOfMinHeap] = vertex;
    }

    int extractMin() { //returns the index with the lowest weight

        int tempMin=keyArray[0];
        for (int i=0; i < size; i++) {
            if (keyArray[i] < tempMin) {
                tempMin = keyArray[i];
            }
        }
        return tempMin;
    }

    int extractMinIndex() { //returns the index with the lowest weight
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

    int extractFromHeap(int index) {
        return heapArray[index];
    }

    int extractKey(int index) {
        return keyArray[index];
    }

    int extractVisited(int index) {
        return visited[index];
    }

    void decreaseKey(int vertex, int newKey) {
        keyArray[vertex] = newKey;
    };

    void setAllVisitedArray(int value) {
        for (int i=0; i < capacity; i++) {
            visited[i] = value;
        }
    }

    void clearAllArrays() {
        for (int i=0; i < capacity; i++) {
            keyArray[i] = 0;
            heapArray[i] = 0;
            position[i] = 999;
        }
    }

    void addToVisited(int value) {
        visited[indexOfVisited] = value;
        indexOfVisited++;
    }

    bool isInMinHeap(int vertex) {
        for (int i=0; i< capacity; i++) {
            if (heapArray[i] == vertex ) {
                return true;
            }
        }
        return false;
    }

    bool isInPositionArray(int vertex) {
        for (int i=0; i< capacity; i++) {
            if (position[i] == vertex ) {
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
    int getTotalCost() {
        cout<< "keyArray contains ";
        for (int i=0; i< capacity; i++) {
            cout << keyArray[i] << " ";
        }

        cout << "\n" << endl;

        cout<< "heapArray contains ";
        for (int i=0; i< capacity; i++) {
            cout << heapArray[i] << " ";
        }
        cout << "\n" << endl;

        cout<< "positionArray contains ";
        for (int i=0; i< capacity; i++) {
            cout << position[i] << " ";
        }

        cout << "\n" << endl;
        cout<< "visited contains ";
        for (int i=0; i< capacity; i++) {
            cout << visited[i] << " ";
        }
        cout << "\n" << endl;

        return totalCost;
    }

    void incrementCounter() {
        counter++;
    }

private:
    int* heapArray;        // Heap of vertex indices
    int* keyArray;         // Corresponding key values
    int* position;         // Maps vertex to its position in heap

    int* visited;
    int* unvisited;



    int indexOfMinHeap;
    int capacity;
    int size;
    int sizeForVisitedArray;
    int counter;
    int indexOfVisited;
    int totalCost; //DELETE ALL OF TOTAL COST FROM HEAP.H....ITS LITERALLY ALL JUST FOR TESTING
    void minHeapify(int idx) {

    };
};

#endif