#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v, weight; // Vertices and weight of the edge
};

// Function to find the root of a node (for Kruskal's algorithm)
int find(int parent[], int i) {
    if (parent[i] == -1) {
        return i;
    }
    return find(parent, parent[i]);
}

// Function to perform union of two subsets (for Kruskal's algorithm)
void unionSets(int parent[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    parent[xroot] = yroot; // Union the two sets
}


void kruskal(Edge edges[], int edge_count, int nodes) {
    
    for (int i = 0; i < edge_count - 1; i++) {
        for (int j = 0; j < edge_count - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    int parent[100]; // Parent array for union-find
    for (int i = 0; i < nodes; i++)
        parent[i] = -1; // Initialize parent array

    cout << "Kruskal's MST:\n";
    for (int i = 0; i < edge_count; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        // If including this edge does not cause a cycle
        int x = find(parent, u);
        int y = find(parent, v);
        if (x != y) {
            cout << u << " - " << v << " (Weight: " << weight << ")\n";
            unionSets(parent, x, y);
        }
    }
}

// Function to implement Prim's algorithm to find MST
void prim(int adjMatrix[100][100], int nodes) {
    bool inMST[100] = {false}; // Track vertices included in MST
    inMST[0] = true; // Start from the first vertex
    int edgesCount = 0;

    cout << "Prim's MST:\n";
    while (edgesCount < nodes - 1) {
        int minWeight = 10000; // Initialize to a large value
        int u = -1, v = -1;

        // Find the smallest edge connecting the MST with the remaining vertices
        for (int i = 0; i < nodes; i++) {
            if (inMST[i]) {
                for (int j = 0; j < nodes; j++) {
                    if (!inMST[j] && adjMatrix[i][j] != 0) { // Check if edge exists
                        if (minWeight > adjMatrix[i][j]) {
                            minWeight = adjMatrix[i][j];
                            u = i;
                            v = j;
                        }
                    }
                }
            }
        }

        // Include the found edge in the MST
        if (v != -1) {
            inMST[v] = true;
            edgesCount++;
            cout << u << " - " << v << " (Weight: " << minWeight << ")\n";
        } else {
            break; // Break the loop if no edge found
        }
    }
}

// Function to display the adjacency matrix
void displayAdjacencyMatrix(int adjMatrix[100][100], int nodes) {
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl; // New line for the next row
    }
}
#include <iostream>
using namespace std;

// Structure to represent an edge


// Function to compare the MSTs from Prim's and Kruskal's algorithms
void compareMSTs(Edge primEdges[], int primCount, Edge kruskalEdges[], int kruskalCount) {
    cout << "Comparison of Prim's and Kruskal's MSTs:\n";

    // Calculate total weight for Prim's MST
    int primTotalWeight = 0;
    for (int i = 0; i < primCount; i++) {
        primTotalWeight += primEdges[i].weight;
    }

    // Calculate total weight for Kruskal's MST
    int kruskalTotalWeight = 0;
    for (int i = 0; i < kruskalCount; i++) {
        kruskalTotalWeight += kruskalEdges[i].weight;
    }

    // Compare the total weights
    if (primTotalWeight != kruskalTotalWeight) {
        cout << "MSTs are different: Different total weights.\n";
        cout << "Total weight of Prim's MST: " << primTotalWeight << endl;
        cout << "Total weight of Kruskal's MST: " << kruskalTotalWeight << endl;
        return;
    }

    // Check if they have the same number of edges
    if (primCount != kruskalCount) {
        cout << "MSTs are different: Different number of edges.\n";
        return;
    }

    // Compare the edges
    bool isEqual = true; // Flag to check if they are equal
    for (int i = 0; i < primCount; i++) {
        bool found = false;
        for (int j = 0; j < kruskalCount; j++) {
            // Check if the edges are the same (considering undirected graph)
            if ((primEdges[i].u == kruskalEdges[j].u && primEdges[i].v == kruskalEdges[j].v) ||
                (primEdges[i].u == kruskalEdges[j].v && primEdges[i].v == kruskalEdges[j].u)) {
                found = true;
                break;
            }
        }
        if (!found) {
            isEqual = false;
            break;
        }
    }

    if (isEqual) {
        cout << "MSTs are the same with total weight: " << primTotalWeight << endl;
    } else {
        cout << "MSTs are different.\n";
    }
}



int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation

    int nodes;
    cout << "Enter the number of nodes: ";
    cin >> nodes;

    // Randomly generate the number of edges (between nodes-1 and nodes*(nodes-1)/2)
    int max_edges = nodes * (nodes - 1) / 2;
    int edges_count = rand() % (max_edges - (nodes - 1) + 1) + (nodes - 1); // Ensure at least nodes-1 edges
    cout << "Randomly generated number of edges: " << edges_count << endl;

    Edge edges[100]; // Array to hold edges
    int adjMatrix[100][100] = {0}; // Initialize adjacency matrix to 0

    // Generate random edges
    for (int i = 0; i < edges_count; ++i) {
        int u, v, weight;
        u = rand() % nodes; // Random node1
        v = rand() % nodes; // Random node2

        // Ensure u and v are different and there is no duplicate edge
        while (u == v || adjMatrix[u][v] != 0) {
            u = rand() % nodes; // Random node1
            v = rand() % nodes; // Random node2
        }

        weight = rand() % 10 + 1; 

        // Update the adjacency matrix and edges array
        adjMatrix[u][v] = weight; 
        adjMatrix[v][u] = weight; 
        edges[i].u = u;           
        edges[i].v = v;
        edges[i].weight = weight;
    }

    // Call Kruskal's algorithm
    kruskal(edges, edges_count, nodes);
    
    // Call Prim's algorithm
    prim(adjMatrix, nodes);

    // Display the adjacency matrix
    displayAdjacencyMatrix(adjMatrix, nodes);

    return 0;
}
