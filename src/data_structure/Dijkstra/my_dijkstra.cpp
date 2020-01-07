#include "my_dijkstra.h"
#include <limits.h>
#include <iostream>

My_Graph::My_Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void My_Graph::addEdge(int u, int v, int w) {
    adj[u].push_back(std::make_pair(v, w));
    adj[v].push_back(std::make_pair(u, w));
}

void My_Graph::shortestPath(int src) {
    // 
    std::set<std::pair<int, int>> setds;
    std::vector<int> dist(V, INT_MAX);
    std::vector<int> from(V, 0);
    setds.insert(std::make_pair(0, src));
    dist[src] = 0;

    while(!setds.empty()) {
        auto tmp = setds.begin();
        setds.erase(setds.begin());
        // int weight = tmp->first;
        int u = tmp->second;
        
        for(auto it = adj[u].begin(); it != adj[u].end(); ++it) 
        {
            int v = it->first;
            int weight = it->second;
            if(dist[v] > dist[u] + weight) {
                if(dist[v] != INT_MAX) {
                    setds.erase(setds.find(std::make_pair(dist[v], v)));
                }
                setds.insert(std::make_pair(dist[u] + weight,v));
                dist[v] = dist[u] + weight;
                from[v] = u;
            }
        }
    }
    std::cout << "Vertex distance from Source" << std::endl;
    for (int i = 0; i < V; ++i)
    {
        std::cout << i << "\t" << dist[i]  << "\t" << from[i] << std::endl;
    }
}