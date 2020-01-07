#include "my_dijkstra.h"
#include <limits.h>

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back(std::make_pair(v, w));
    adj[v].push_back(std::make_pair(u, w));
}

void Graph::shortestPath(int src) {
    // 
    std::set<std::pair<int, int>> setds;
    std::vector<int> dist(V, INT_MAX);
}