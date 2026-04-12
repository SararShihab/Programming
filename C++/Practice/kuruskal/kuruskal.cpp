#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Class to handle Cycle Detection (Disjoint Set Union)
class DSU {
private:
    unordered_map<char, char> parent;
public:
    void makeSet(char c) {
        parent[c] = c;
    }

    char find(char c) {
        if (parent[c] == c) return c;
        // Path compression for efficiency
        return parent[c] = find(parent[c]);
    }

    void unite(char a, char b) {
        char rootA = find(a);
        char rootB = find(b);
        if (rootA != rootB) {
            parent[rootB] = rootA;
        }
    }
};

// Class to represent an Edge
class Edge {
public:
    char u, v;
    int wt;
    
    // Constructor for easy push_back
    Edge(char u, char v, int wt) {
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
};

class KruskalGraph {
private:
    vector<Edge> edgeList;
    DSU dsu;
    int numNodes;

public:
    KruskalGraph(int n) {
        this->numNodes = n;
    }

    void addEdge(char u, char v, int wt) {
        edgeList.push_back(Edge(u, v, wt));
        // Ensure both nodes are initialized in DSU
        dsu.makeSet(u);
        dsu.makeSet(v);
    }

    // Helper function for sorting (Non-Lambda approach)
    static bool compareEdges(Edge a, Edge b) {
        return a.wt < b.wt;
    }

    void findMST() {
        // 1. Sort edges in ascending order of cost
        sort(edgeList.begin(), edgeList.end(), compareEdges);

        int totalWeight = 0;
        int edgesCount = 0;

        cout << "\n== Kruskal's MST Edges ==\n" << endl;
        cout << "Edge \t Cost" << endl;

        // 2. Iterate through sorted edges and check for cycles
        for (auto &edge : edgeList) {
            if (dsu.find(edge.u) != dsu.find(edge.v)) {
                dsu.unite(edge.u, edge.v);
                totalWeight += edge.wt;
                cout << edge.u << " - " << edge.v << " \t " << edge.wt << endl;
                edgesCount++;
            }
            
            // Optimization: MST always has (V-1) edges
            if (edgesCount == numNodes - 1) break;
        }

        cout << "\nTotal MST Weight: " << totalWeight << endl;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    KruskalGraph g(V);

    cout << "Enter edges (u v w):" << endl;
    for (int i = 0; i < E; i++) {
        char u, v;
        int wt;
        cin >> u >> v >> wt;
        g.addEdge(u, v, wt);
    }

    g.findMST();

    return 0;
}