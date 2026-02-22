#include <iostream>
#include <vector>
using namespace std;

class AP {
private:
    int timer = 0;

    void dfs(int node, int parent,
             vector<int> &vis,
             vector<int> &tin,
             vector<int> &low,
             vector<int> &mark,
             vector<vector<int>> &adj) {

        vis[node] = 1;
        tin[node] = low[node] = timer++;
        int child = 0;

        for (int neighbor : adj[node]) {

            if (neighbor == parent){ 
                continue;
            }

            if (!vis[neighbor]) {

                dfs(neighbor, node, vis, tin, low, mark, adj);

                low[node] = min(low[node], low[neighbor]);

                if (low[neighbor] >= tin[node] && parent != -1) {
                    mark[node] = 1;
                }

                child++;

            } else {
                low[node] = min(low[node], tin[neighbor]);
            }
        }

        if (parent == -1 && child > 1) {
            mark[node] = 1;
        }
    }

public:

    void findArticulationPoints(int n, vector<vector<int>> &adj) {

        vector<int> vis(n, 0);
        vector<int> tin(n);
        vector<int> low(n);
        vector<int> mark(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, -1, vis, tin, low, mark, adj);
            }
        }

        cout << "Articulation Points:\n";
        bool found = false;

        for (int i = 0; i < n; i++) {
            if (mark[i] == 1) {
                cout << i << " ";
                found = true;
            }
        }

        if (!found) {
            cout << "None";
        }

        cout << endl;
    }
};

int main() {

    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);

    cout << "Enter edges (u v) for undirected graph:\n";

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    AP obj;
    obj.findArticulationPoints(V, adj);

    return 0;
}