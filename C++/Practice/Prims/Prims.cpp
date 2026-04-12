#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <tuple> // Required for tuple

using namespace std;

class Graph {
    unordered_map<char, vector<pair<char, int>>> l;
public:
    void addEdge(char u, char v, int wt) {
        l[u].push_back({v, wt});
        l[v].push_back({u, wt});
    }

    void primsAlgo(char src) {
        // priority_queue stores: {cost, current_node, parent_node}
        priority_queue<tuple<int, char, char>, vector<tuple<int, char, char>>, greater<tuple<int, char, char>>> pq;
        unordered_map<char, bool> mst;
        
        // Initial parent is a dummy '\0'
        pq.push({0, src, '\0'});
        int totalWeight = 0;

        cout << "\nEdge \t Weight" << endl;

        while (!pq.empty()) {
            auto [cost, u, parent] = pq.top();
            pq.pop();

            if (!mst[u]) {
                mst[u] = true;
                totalWeight += cost;

                // Print the edge if it's not the starting node
                if (parent != '\0') {
                    cout << parent << " - " << u << " \t " << cost << endl;
                }

                for (auto [v, wt] : l[u]) {
                    if (!mst[v]) {
                        pq.push({wt, v, u}); // Push current node 'u' as parent of 'v'
                    }
                }
            }
        }
        cout << "\nTotal Weight: " << totalWeight << endl;
    }
};

int main() {
    Graph g;
    int nodes, edges;
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++) {
        int wt;
        char u, v;
        cin >> u >> v >> wt;
        g.addEdge(u, v, wt);
    }

    char src;
    cin >> src;

    g.primsAlgo(src);
    return 0;
}