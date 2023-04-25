
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

int maxDegreeDiff(Graph g) {
    // TODO
    int nV = GraphNumVertices(g);
    int max_diff = 0;
    
    // Initialize arrays for in-degree and out-degree counts
    int in_degree[nV];
    int out_degree[nV];
    for (int i = 0; i < nV; i++) {
        in_degree[i] = 0;
        out_degree[i] = 0;
    }

    // Calculate in-degree and out-degree for each vertex
    for (int v = 0; v < nV; v++) {
        AdjList curr = g->edges[v];
        while (curr != NULL) {
            out_degree[v]++;
            in_degree[curr->v]++;
            curr = curr->next;
        }
    }

    // Find the maximum absolute degree difference
    for (int i = 0; i < nV; i++) {
        int diff = abs(in_degree[i] - out_degree[i]);
        if (diff > max_diff) {
            max_diff = diff;
        }
    }

    return max_diff;
}

