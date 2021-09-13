//John Hoffman - F00555643
//CSC 543
//Assignment 4 - Dijsktra's Algorithm
//09/12/2021

#include <iostream>
#include <climits>
using namespace std;

//Function to get the starting node from the user
int getStartingNode() {
    cout << "Please enter the starting node (0-5):";

    int startingNode;
    cin >> startingNode;

    while (startingNode > 5 || startingNode < 0) {
        cout << "ERROR: Please enter a number between 0 and 5:";
        cin >> startingNode;
    }

    return startingNode;
}

//Function to get the ending node from the user
int getEndingNode() {
    cout << "\nPlease enter the ending node (0-5):";

    int endingNode;
    cin >> endingNode;

    while (endingNode > 5 || endingNode < 0) {
        cout << "ERROR: Please enter a number between 0 and 5:";
        cin >> endingNode;
    }

    return endingNode;
}

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
void outputSolution(int distance[], int startingNode, int endingNode) {
    char startingVertex = 65 + startingNode;
    char endingVertex = 65 + endingNode;

    cout << "\nStarting Vertex = " << startingVertex;
    cout << "\nEnding Vertex = " << endingVertex;
    cout << "\nDistance = " << distance[endingNode];
}

//Function that implements Dijsktra's Algorithm using an adjacency matrix representation of a graph
void DijkstrasAlgorithm(int graph[6][6], int source, int destination) {

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
        for(int j = 0; j < 6; j++) {
            if(!visitedList[j] && graph[m][j] && distance[m] != INT_MAX && distance[m] + graph[m][j] < distance[j])
                distance[j] = distance[m] + graph[m][j];
        }
    }

    outputSolution(distance, source, destination);
}

//Main driver for the program
int main() {
    int startingNode = getStartingNode();
    int endingNode = getEndingNode();

    int graph[6][6] = {
        {0, 1, 2, 0, 0, 0},
        {1, 0, 0, 5, 1, 0},
        {2, 0, 0, 2, 3, 0},
        {0, 5, 2, 0, 2, 2},
        {0, 1, 3, 2, 0, 1},
        {0, 0, 0, 2, 1, 0}
    };
    
    DijkstrasAlgorithm(graph, startingNode, endingNode);
    return 0;                           
}