#ifndef GRAPH_H
#define GRAPH_H
using namespace std;

class Graph {
public:
    Graph(int vertices) {
        this->numVertices = vertices;
        adjMatrix= new int*[numVertices];
        for (int r = 0; r < numVertices; r++) {
            adjMatrix[r] = new int[numVertices]; //this new int[numVertices] is the columns
        }

        // for (int r = 0; r < numVertices; r++) {
        //     for (int c = 0; c < numVertices; c++) {
        //         adjMatrix[r][c] = {999}; //maybe include this so that it is not confusing with a weight of 0
        //     }
        // }
    };
    //~Graph(); FIX THIS
    void addEdge(int u, int v, int weight) {
        //u is the row
        //v is the col
        //weight is the value in there
        adjMatrix[u][v] = {weight};
        adjMatrix[v][u] = {weight};
    };
    void primMST() {
        cout<<"Adjacency Matrix"<<endl;
        for (int c = 0; c < numVertices; c++) {
            cout << "     " << c << "   ";
        }
        cout << endl;
        for (int r = 0; r < numVertices; r++) {
            cout << r << "    ";
            for (int c = 0; c < numVertices; c++) {
                cout << adjMatrix[r][c] << "        ";
            }
            cout << endl;
        }
    };  // Must print MST edges and total weight

private:
    int** adjMatrix;
    int numVertices;
};

#endif