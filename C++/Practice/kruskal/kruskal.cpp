#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Kruskal {
private:
    vector<tuple<char, char, int>> edges;
    unordered_map<char, char> parent;

    char findSet(char u) {
        if (parent[u] == u)
            return u;
        return parent[u] = findSet(parent[u]);
    }

    void unionSet(char u, char v) {
        parent[findSet(u)] = findSet(v);
    }

public:
    void addEdge(char u, char v, int w) {
        edges.push_back({u, v, w});
        parent[u] = u;
        parent[v] = v;
    }

    void findMST() {
        sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
            return get<2>(a) < get<2>(b);
        });

        int totalCost = 0;

        cout << "\n------------------------------------" << endl;
        cout << "Minimum Spanning Tree" << endl;
        cout << "------------------------------------" << endl;
        cout << "Edge     Weight" << endl;
        cout << "------------------------------------" << endl;

        for (auto [u, v, w] : edges) {
            if (findSet(u) != findSet(v)) {
                unionSet(u, v);
                totalCost += w;

                cout << u << " - " << v << " \t " << w << endl;
            }
        }

        cout << "------------------------------------" << endl;
        cout << "Total Cost: " << totalCost << endl;
        cout << "------------------------------------" << endl;
    }
};

int main() {
    int E;
    cout << "Enter number of edges: ";
    cin >> E;

    Kruskal graph;

    cout << "Enter edges (u v w):" << endl;
    for (int i = 0; i < E; i++) {
        char u, v;
        int w;
        cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }

    graph.findMST();

    return 0;
}