#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Prim {
private:
    // Habit: Separate vectors for Edge List (Bellman style)
    vector<int> src, dst, wt;

    void printMST(int V, vector<int> &parent, vector<int> &key) {
        int totalWeight = 0;
        cout << "\n== Minimum Spanning Tree Edges ==\n" << endl;
        cout << "\tEdge\tWeight" << endl;

        for (int i = 0; i < V; i++) {
            if (parent[i] != -1) {
                // Formatting matches your tab-spaced table habit
                cout << "\t" << parent[i] << " - " << i << "\t" << key[i] << endl;
                totalWeight += key[i];
            }
        }
        cout << "\nTotal MST Weight: " << totalWeight << endl;
    }

public:
    // Habit: Simple addEdge pushing to separate vectors
    void addEdge(int u, int v, int w) {
        src.push_back(u);
        dst.push_back(v);
        wt.push_back(w);
    }

    void calculateMST(int V, int startNode) {
        int E = src.size();
        vector<int> key(V, INT_MAX);
        vector<int> parent(V, -1);
        vector<bool> inMST(V, false);

        // Standard initialization using INT_MAX from climits
        key[startNode] = 0;

        for (int count = 0; count < V; count++) {
            // 1. Find node with minimum key among vertices not yet in MST
            int u = -1, minVal = INT_MAX;
            for (int i = 0; i < V; i++) {
                if (!inMST[i] && key[i] < minVal) {
                    minVal = key[i];
                    u = i;
                }
            }

            if (u == -1) break; 
            inMST[u] = true;

            // 2. Update keys of neighbors by scanning the edge list
            for (int i = 0; i < E; i++) {
                int v = -1;
                
                // Check if current node u is part of the edge (u, v) or (v, u)
                if (src[i] == u) v = dst[i];
                else if (dst[i] == u) v = src[i];
                else continue;

                // Relaxation-style update specific to Prim's
                if (!inMST[v] && wt[i] < key[v]) {
                    parent[v] = u;
                    key[v] = wt[i];
                }
            }
        }

        printMST(V, parent, key);
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    Prim graph;

    cout << "Enter edges (u v w):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }

    int startNode;
    cout << "Enter starting vertex: ";
    cin >> startNode;

    graph.calculateMST(V, startNode);

    return 0;
}