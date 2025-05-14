#ifndef GRAPH_H
#define GRAPH_H
using namespace std;

#include "heap.h"
class Graph {
public:
    Graph(int vertices) {   //constructor for Graph involving the creating of 2D array for adjacency matrix and minHeap
        this->numVertices = vertices;
        adjMatrix= new int*[numVertices];
        for (int r = 0; r < numVertices; r++) {
            adjMatrix[r] = new int[numVertices];    //this new int[numVertices] is the columns
        }

        for (int r = 0; r < numVertices; r++) {
            for (int c = 0; c < numVertices; c++) {
                adjMatrix[r][c] = infinity;    //setting all the values at first to be the constant infinity
            }
        }
        minHeap= new MinHeap(vertices);
        totalCost=0;
    };
    ~Graph() {};    //figure this out at some point
    void addEdge(int u, int v, int weight) {    //set the weight at each slot r,c and c,r because it is undirected
        //u is the row
        //v is the col
        //weight is the value in there
        adjMatrix[u][v] = {weight};
        adjMatrix[v][u] = {weight};
    };
    void primMST() { //prints out the adjacency matrix based on the given input
        cout<<"Adjacency Matrix Based on Initial Input" <<endl;
        for (int c = 0; c < numVertices; c++) {
            cout << "     " << c << "   ";  //prints out all column values
        }
        cout << endl;
        for (int r = 0; r < numVertices; r++) {    //runs numVertices times, printing out the current row
            cout << r << "  { ";
            for (int c = 0; c < numVertices; c++) {    //responsible for printing value at adjMatrix[r][c]
                if (adjMatrix[r][c] == infinity)  {
                    cout<< "∞";
                }
                else {
                    cout << adjMatrix[r][c];
                }

                if (c == numVertices - 1) {    //special case when reaching the last possible column for formatting
                    cout << " }";
                }
                else {
                    cout << "        ";
                }
            }
            cout << endl;
        }

        minHeap->setAllVisitedArray(infinity);
        for (int r = 0; r < numVertices; r++) {
            //used to say numVertices
            for (int c = 0; c < numVertices; c++) { //used to say numVertices
                tempVal=adjMatrix[r][c];
                if (r ==0 && c==0) {
                    minHeap->insert(infinity,infinity);
                    minHeap->addToVisited(r);
                }
                else if (tempVal == infinity) {
                    minHeap->insert(infinity,infinity);
                }
                else {
                    minHeap->insert(c,tempVal);
                }
            }

            for (int i=0; i< numVertices; i++) {
                //Continuously runs until all options have been visited
                int tempVal = minHeap->extractVisited(i);
                if (minHeap->extractFromHeap(i) != tempVal ) {
                    //minHeap->insertInPositionArray(r);
                    tempMinVal= minHeap->extractMin();
                    tempMinValIndex= minHeap->extractMinIndex(); //this gives the value with the lowest weight's index
                    //then double check that the lowest weight associtaed vertex is not in the vistied array either
                    int associatedVertexWithMinWeight= minHeap->extractFromHeap(tempMinValIndex);

                    if (minHeap->isInPositionArray(associatedVertexWithMinWeight) == false) { //if index HAS NOT BEEN VISITED
                        cout << r <<"--" << associatedVertexWithMinWeight << "(" << tempMinVal << ")" << endl;
                        minHeap->addToVisited(associatedVertexWithMinWeight);
                        totalCost= totalCost+ tempMinVal;
                        break;
                    }
                    else { //if index HAS been VISITED
                        minHeap->decreaseKey(associatedVertexWithMinWeight,0); //maybe need to do something so th
                    }
                }
            }
            //minHeap->clearAllArrays();
        }

        //minHeap->insert(v, weight);
        // for (int r = 0; r < numVertices; r++) {
        //     for (int c = 0; c < numVertices; c++) {
        //         tempVal= adjMatrix[r][c];
        //         if (minHeap->isInMinHeap(r)==true && tempVal!=infinity) { //it is 0 atm
        //             minHeap->insert(c, tempVal);
        //         }
        //         else {
        //             minHeap->incrementCounter();
        //         }
        //     }
        //     tempMinVal= minHeap->extractMin();
        //     minHeap->decreaseKey(1,2); //use this to get rid of the
        //
        //     //after extracting the min which would be 0 at this point, you then gotta call decrease key which works togethwer with minheapify
        // }

        cout<< "\nTotal Cost: " << minHeap->getTotalCost() << endl;
    };  // Must print MST edges and total weight

private:
    int** adjMatrix;
    int numVertices;
    int tempVal;
    const int infinity = 999;
    int tempMinVal;
    int tempMinValIndex;
    MinHeap *minHeap;
    int totalCost;
};

#endif