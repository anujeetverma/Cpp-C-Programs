#include <iostream>
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

// Function to implement Kruskal's algorithm to find MST
void kruskal(Edge edges[], int edge_count, int nodes) {
    // Sort edges based on weight using a simple bubble sort
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
        }
    }
}

int main() {
    int nodes, edges_count;
    int adjMatrix[100][100] = {0}; // Initialize adjacency matrix to 0

    cout << "Enter the number of nodes: ";
    cin >> nodes;

    cout << "Enter the number of edges: ";
    cin >> edges_count;

    Edge edges[100]; // Array to hold edges

    cout << "Enter the edges in the format: node1 node2 weight" << endl;
    for (int i = 0; i < edges_count; ++i) {
        int u, v, weight;
        cout << "Edge " << (i + 1) << ": ";
        cin >> u >> v >> weight;

        // Input validation
        if (u < 0 || u >= nodes || v < 0 || v >= nodes) {
            cout << "Error: Invalid node index." << endl;
            --i; // Decrement i to retry this input
            continue; // Skip this iteration
        }
        if (weight < 0) {
            cout << "Error: Weight must be non-negative." << endl;
            --i; // Decrement i to retry this input
            continue; // Skip this iteration
        }

        // Update the adjacency matrix and edges array
        adjMatrix[u][v] = weight; // Set edge weight for u to v
        adjMatrix[v][u] = weight; // Set edge weight for v to u (undirected)
        edges[i].u = u;           // Initialize the edge
        edges[i].v = v;
        edges[i].weight = weight;
    }

    // Call Kruskal's algorithm
    kruskal(edges, edges_count, nodes);
    
    // Call Prim's algorithm
    prim(adjMatrix, nodes);

    return 0;
}
