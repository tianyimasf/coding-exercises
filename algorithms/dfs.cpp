#include <iostream>
#include <vector>
using namespace std;

class Graph{
    public:
    int n;
    vector<int> edges[100];
    bool marked[100];

    Graph(int nodeNum)
    {
        n = nodeNum;
        for (int i = 0; i < 100; i++)
        {
            marked[i] = false;
        }
    }

    void addEdge(int s, int t)
    {
        edges[s].push_back(t);
    }
};

void DFS(Graph *G, int root)
{
    cout << "Node: " << root << "\n";
    G->marked[root] = true;
    for (auto i : G->edges[root]){
        if (!G->marked[i]){
            DFS(G, i);
        }
    }
}

int main()
{
    Graph *G = new Graph(10);
    G->addEdge(0, 1);
    G->addEdge(0, 4);
    G->addEdge(0, 5);
    G->addEdge(1, 3);
    G->addEdge(1, 4);
    G->addEdge(2, 1);
    G->addEdge(3, 2);
    G->addEdge(3, 4);

    DFS(G, 0);
}