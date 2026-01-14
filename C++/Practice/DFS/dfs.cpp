#include<iostream>
#include<list>
#include<stack>
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

    void dfs(){
        stack<int> S;
        vector<bool> vsted(V, false);

        S.push(0);
        vsted[0] = true;

        cout << "DFS: ";
        while(S.size()>0){
            int u = S.top();
            S.pop();
            cout << u << " ";

            for(int v : l[u]){
                if(!vsted[v]){
                    vsted[v] = true;
                    S.push(v);
                }
            }
        }
        cout << endl;
    }

    
};

int main(){
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);

    g.dfs();

    return 0;
}
