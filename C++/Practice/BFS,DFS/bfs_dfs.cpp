#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;

class Graph{
    int V;
    list<int> *l;

public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void bfs(){
        queue<int> Q;
        vector<bool> vsted(V, false);

        Q.push(0);
        vsted[0] = true;

        cout << "BFS: ";
        while(!Q.empty()){
            int u = Q.front();
            Q.pop();
            cout << u << " ";

            for(int v : l[u]){
                if(!vsted[v]){
                    vsted[v] = true;
                    Q.push(v);
                }
            }
        }
        cout << endl;
    }

    void dfsHelper(int u, vector<bool> &vsted){
        vsted[u] = true;
        cout << u << " ";

        for(int v : l[u]){
            if(!vsted[v]){
                dfsHelper(v, vsted);
            }
        }
    }

    void dfs(){
        vector<bool> vsted(V, false);
        cout << "DFS: ";
        dfsHelper(0, vsted);
        cout << endl;
    }
};

int main(){
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);

    g.bfs();
    g.dfs();

    return 0;
}
