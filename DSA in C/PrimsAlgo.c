#include <stdio.h>
#include <limits.h>
#include <math.h>

#define MAX 10 // Maximum number of vertices

// Function to find the vertex with the minimum key value
int minimum_key(int key[], int mstSet[], int vertices) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < vertices; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to implement Prim's algorithm
void prim(int graph[MAX][MAX], int vertices) {
    int parent[MAX];   // Array to store the MST
    int key[MAX];      // Key values for picking the minimum weight edge
    int mstSet[MAX];   // To represent the vertices included in MST

    // Initialize all keys as infinite and mstSet[] as false
    for (int i = 0; i < vertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;         // Start from the first vertex
    parent[0] = -1;     // First node is the root of the MST

    // MST construction
    for (int count = 0; count < vertices - 1; count++) {
        int u = minimum_key(key, mstSet, vertices);
        mstSet[u] = 1;

        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the MST
    printf("Edge \tWeight\n");
    int total_weight = 0;
    for (int i = 1; i < vertices; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        total_weight += graph[i][parent[i]];
    }
    printf("Total Weight of MST: %d\n", total_weight);
}

int main() {
    int vertices;
    printf("Enter the number of vertices (minimum 6): ");
    scanf("%d", &vertices);

    if (vertices < 6) {
        printf("Please enter at least 6 vertices.\n");
        return 1;
    }

    int graph[MAX][MAX] = {0};

    int edges;
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (u v weight):\n");
    for (int i = 0; i < edges; i++) {
        int u, v, weight;
        scanf("%d %d %d", &u, &v, &weight);
        graph[u][v] = weight;
        graph[v][u] = weight;
    }

    printf("\nConstructing Minimum Spanning Tree...\n");
    prim(graph, vertices);

    return 0;
}
