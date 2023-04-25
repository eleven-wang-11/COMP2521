
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

int dayTrip(Graph g, Vertex s, Vertex vs[]) {
    // TODO
    int nV = g->nV;
    bool visited[nV];
    for (int i = 0; i < nV; i++) {
    visited[i] = false;
    }

    int reachable_count = 0;

    // Process black edges (one day's driving)
    for (int neighbor = 0; neighbor < nV; neighbor++) {
        if (g->stdEdges[s][neighbor]) {
            visited[neighbor] = true;
            vs[reachable_count++] = neighbor;
        }
    }

    // Process red edges (half day's driving)
    for (int neighbor = 0; neighbor < nV; neighbor++) {
        if (g->fastEdges[s][neighbor] && !visited[neighbor]) {
            visited[neighbor] = true;
            vs[reachable_count++] = neighbor;

            for (int next_neighbor = 0; next_neighbor < nV; next_neighbor++) {
                if (g->fastEdges[neighbor][next_neighbor] && !visited[next_neighbor]) {
                    visited[next_neighbor] = true;
                    vs[reachable_count++] = next_neighbor;
                }
            }
        }
    }

    return reachable_count;
}

