#include <iostream>
#include <limits.h>
#include <vector>
#include <set>
#include <list>

using namespace std;

class Graph
{
    int V;
    list<pair<int, int>> *adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<pair<int, int>>[V];
    }

    // function to add an edge to graph
    void addEdge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // print shortest path from s
    void shortestPath(int s);
};

void Graph::shortestPath(int src)
{
    // create a set to store vertices that are being
    // prerocessed
    set<pair<int, int>> setds;

    // Create a vector for distances and initialize
    // all distance as INF
    vector<int> dist(V, INT_MAX);

    // Insert source itself in Set and initialize its
    // distance as 0
    setds.insert(make_pair(0, src));

    dist[src] = 0;

    while (!setds.empty())
    {
        // The first vertex in Set is the minium distance
        // vertex, extract it from set
        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());

        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair))
        int u = tmp.second;

        // 'i' is used to get all adjacent vertices of a vertex
        list<pair<int, int>>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjecent
            // of u
            int v = (*i).first;
            int weight = (*i).second;

            // If there is shorter path to v through u
            if (dist[v] > dist[u] + weight)
            {
                /* If distance of v is not INF then it must be in 
                    out set, so removing it and inserting again 
                    with updated less distance.
                    Note: We extract only those vertices from Set
                    for which distance is finalized, So for them, 
                    we would never reach here.*/
                if (dist[v] != INT_MAX)
                    setds.erase(setds.find(make_pair(dist[v], v)));

                // updating distance of v
                dist[v] = dist[u] + weight;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }
    // print shortest distances stored in dist[]
    cout << "Vertex distance from Source" << endl;
    for (int i = 0; i < V; ++i)
    {
        cout << i << "\t\t" << dist[i] << endl;
    }
}

int main()
{
    int V = 9;
    Graph g(V);

    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.shortestPath(0);

    return 0;
}
