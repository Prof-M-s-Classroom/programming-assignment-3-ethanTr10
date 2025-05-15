#ifndef GRAPH_H
#define GRAPH_H
using namespace std;

#include "heap.h"

class Graph {
public:
    Graph(int vertices) {   //Constructor for Graph involving the creating of 2D array for adjacency matrix and minHeap
        this->numVertices = vertices;
        adjMatrix = new int *[numVertices];
        for (int r = 0; r < numVertices; r++) {
            adjMatrix[r] = new int[numVertices]; //This new int[numVertices] is the columns
        }
        for (int r = 0; r < numVertices; r++) {
            for (int c = 0; c < numVertices; c++) {
                adjMatrix[r][c] = infinity; //Setting all the values at first to be the constant infinity
            }
        }
        minHeap = new MinHeap(vertices);
        totalCost = 0;
        associatedVertexWithMinWeight = 0;
    };

    ~Graph() {
    };

    void addEdge(int u, int v, int weight) {  //Set the weight at each slot r,c with the input weight
        adjMatrix[u][v] = {weight};
        adjMatrix[v][u] = {weight};
    };

    void primMST() {  //Prints out the adjacency matrix based on the given input and starts Prim's algorithm
        cout << "Adjacency Matrix Based on Initial Input" << endl;
        for (int c = 0; c < numVertices; c++) {
            cout << "     " << c << "   "; //Prints out all column values
        }
        cout << endl;
        for (int r = 0; r < numVertices; r++) {  //Runs numVertices times, printing out the current row
            cout << r << "  { ";
            for (int c = 0; c < numVertices; c++) {  //Responsible for printing value at adjMatrix[r][c]
                if (adjMatrix[r][c] == infinity) {
                    cout << "∞";
                } else {
                    cout << adjMatrix[r][c];
                }

                if (c == numVertices - 1) {  //Special case when reaching the last possible column for formatting
                    cout << " }";
                } else {
                    cout << "        ";
                }
            }
            cout << endl;
        }

        for (int r = 0; r < numVertices; r++) {  //A double for-loop to get the value within each row and column
            for (int c = 0; c < numVertices; c++) {
                tempVal = adjMatrix[r][c];
                if (r == 0 && c == 0) {  //Special case when nothing has been traversed yet to mark the first visited node
                    minHeap->insert(infinity, infinity);
                    minHeap->addToVisited(r);
                } else if (tempVal == infinity) {
                    minHeap->insert(infinity, infinity);
                } else {
                    minHeap->insert(c, tempVal);
                }
            }

            for (int i = 0; i < numVertices; i++) {  //Continuously runs until all options have been visited
                if (minHeap->extractFromHeap(i) != infinity) {      //If not the default value
                    tempMinVal = minHeap->extractMin();             //Returns the lowest key value
                    tempMinValIndex = minHeap->extractMinIndex();   //This gives the index of the lowest weight
                    associatedVertexWithMinWeight = minHeap->extractFromHeap(tempMinValIndex);  //Returns the vertex associated with the lowest weight
                    if (minHeap->isInPositionArray(associatedVertexWithMinWeight) == false) {   //If index has not been visited
                        cout << r << "--" << associatedVertexWithMinWeight << "(" << tempMinVal << ")" << endl;
                        minHeap->addToVisited(associatedVertexWithMinWeight);
                        totalCost = totalCost + tempMinVal;
                        break;
                    } else {  //If index has been visited
                        minHeap->decreaseKey(associatedVertexWithMinWeight, 0); //maybe need to do something so th
                    }
                }
            }
        }
        cout << "\nTotal Cost: " << totalCost << endl;
    };

private:
    int **adjMatrix;
    int numVertices;
    int tempVal;        //Used to keep track of values at different parts of the program
    const int infinity = 999; //Constant value used to set initial array values
    int tempMinVal;     //Returns the lowest key value
    int tempMinValIndex;    //This gives the index of the lowest weight
    MinHeap *minHeap;
    int totalCost;          //Keeps tracks of cumulative weight depending on path traversals
    int associatedVertexWithMinWeight;  //Vertex value with min weight
};

#endif
