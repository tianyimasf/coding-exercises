#include <iostream>
#include <queue>
using namespace std;

class Graph{
    public:
    int n;
    vector<int> edges[100];
    bool marked[100];

    Graph(int nodeNum){
        n = nodeNum;
        for (int i = 0; i < 100; i++){
            marked[i] = false;
        }
    }

    void addEdge(int s, int t){
        edges[s].push_back(t);
    }
};

void printQueue(queue<int> q){
    queue<int> qc = q;
    while (!qc.empty())
    {
        cout << qc.front() << " ";
        qc.pop();
    }
    cout << "\n";
}

void BFS(Graph* G, int root){
    queue<int> q;
    q.push(root);

    while (!q.empty()){
        int e = q.front();
        if (!G->marked[e]){
            for (auto i : G->edges[e]){
                q.push(i);
            }
        G->marked[e] = true;
        cout << "Node: " << e << " \n";
        }
        q.pop();
    }
    cout << "\n";
}

int main(){
    Graph* G = new Graph(10);
    G->addEdge(0, 1);
    G->addEdge(0, 4);
    G->addEdge(0, 5);
    G->addEdge(1, 3);
    G->addEdge(1, 4);
    G->addEdge(2, 1);
    G->addEdge(3, 2);
    G->addEdge(3, 4);

    BFS(G, 0);
}