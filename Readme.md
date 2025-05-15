[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Ethan Truong

## Files
- graph.h / graph.cpp
- heap.h / heap.cpp
- main.cpp (unchanged)
- README.md

## Description
Briefly describe what your program does and how the code is structured:
This program works by creating a graph based on the added edges from the main.cpp file. Then, an adjacency matrix is made and primMST() is called to create the minimum spanning tree using Prim's algorithm

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis


| Operation            | Time Complexity |
|----------------------|-----------------|
| Insert in MinHeap    | O(1)            |
| Extract Min          | O(N)            |
| Decrease Key         | O(1)            |
| Prim’s MST Overall   | O(N^4)          |

Explain why your MST implementation has the above runtime:
The insert in MinHeap is considered O(1) because the method takes in a vertex and a key and those values are used to set elements within arrays at a specific index, all being constant time operations. Extract min takes O(N) where N is the number of vertices because the function needs to traverse through all the elements in the array storing the weights to find the lowest weight. Decrease key is O(1) because the method just sets an element within key array to the value input newKey. Prim's MST overall is O(N^4) because I have multiple for loops and some are nested with extractMin of O(N) and extractMinIndex of O(N). Must be O(N^4) since I need to traverse through the rows and columns of the adjacency matrix and call the extractMin() and extractMinIndex().    

## Assumptions
Mention any design decisions or assumptions made:
I made the assumption that there would be no weights of 0 to help initiate the first vertex in the heap and indicate the starting vertex of it all. 

## Test Case Description
Include at least one input/output example used to verify correctness:
One test case I used was the following: 

g.addEdge(0,1,2);
g.addEdge(0,2,4);
g.addEdge(1,2,1);
g.addEdge(1,3,7);
g.addEdge(2,3,3); 

This graph includes 4 vertices and there are 5 edges. The expected output is the following:

0--1(2)
1--2(1)
2--3(3)

Total Cost: 6

## Test Plan
List what test cases and edge cases you tried: 
I have made edge cases for instances where there are vertices that have already been visited, when the vertex is the first one being added to the heap, and when the last element is being visited to format the adjacency matrix. I used the test case above. 