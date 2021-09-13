//John Hoffman - F00555643
//CSC 543
//Assignment 4 - Dijsktra's Algorithm
//09/12/2021

#include <iostream>
#include <climits>
using namespace std;

//Function to find the vertex with the minumum distance value that have not been added to the shortest path tree
int minimumDistance(int distance[], bool visitedList[]) {
    int minimum = INT_MAX;
    int minimum_index = 0;
              
    //Loop through the list and update the distance values as necessary
    for(int i = 0; i < 6; i++) {
        if(visitedList[i] == false && distance[i] <= minimum) {
            minimum = distance[i];
            minimum_index = i;
        }
    }
    return minimum_index;
}

//Function to output the solution
void outputSolution(int distance[]) {
    cout << "Vertex\t\tDistance from source vertex" << endl;

    for(int i = 0; i < 6; i++) { 
        char str = 65 + i; 
        cout << str << "\t\t\t" << distance[i] << endl;
    }
}

//Function that implements Dijsktra's Algorithm using an adjacency matrix representation of a graph
void DijkstrasAlgorithm(int graph[6][6], int source) {

    //Array that will hold the minimum distance to each vertex
    int distance[6];

    //Array to mark whether a vertex has been visited
    bool visitedList[6];
    
    //Loop through each list and prepare each node for the algorithm
    for(int k = 0; k < 6; k++)
    {
        distance[k] = INT_MAX;
        visitedList[k] = false;    
    }
    

    //Set the source vertex to 0, the distance is 0 because it is pointing to itself
    distance[source] = 0;           
    
    //Loop through the list and check each vertex to find the shortest path
    for(int i = 0; i < 6; i++) {
        int m = minimumDistance(distance,visitedList); 
        visitedList[m] = true;

        //Update the distance of the neighboring vertex
        for(int k = 0; k<6; k++) {
            if(!visitedList[k] && graph[m][k] && distance[m] != INT_MAX && distance[m] + graph[m][k] < distance[k])
                distance[k] = distance[m] + graph[m][k];
        }
    }

    outputSolution(distance);
}

//Main driver for the program
int main() {
    int graph[6][6] = {
        {0, 1, 2, 0, 0, 0},
        {1, 0, 0, 5, 1, 0},
        {2, 0, 0, 2, 3, 0},
        {0, 5, 2, 0, 2, 2},
        {0, 1, 3, 2, 0, 1},
        {0, 0, 0, 2, 1, 0}
    };
    
    DijkstrasAlgorithm(graph,0);
    return 0;                           
}