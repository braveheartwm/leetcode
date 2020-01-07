#include <list>
#include <vector>
#include <set>

class Graph {
private:
    int V; //顶点数
    // 该数组用于储存每个顶点相邻顶点以及权重
    std::vector<std::list<std::pair<int, int>>> adj;
public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void shortestPath(int src);
};