#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Graph {
    unordered_map<char, vector<pair<char, int>>> l;
public:
    void addEdge(char u, char v, int wt) {
        l[u].push_back({v, wt});
        l[v].push_back({u, wt});
    }

    void primsAlgo(char src) {
        priority_queue<tuple<int, char, char>, vector<tuple<int, char, char>>, greater<tuple<int, char, char>>> pq;
        unordered_map<char, bool> mst;

        pq.push({0, src, '\0'});
        int totalWeight = 0;

        cout << "\nEdge \t Weight\n";

        while (!pq.empty()) {
            auto [cost, u, parent] = pq.top();
            pq.pop();

            if (!mst[u]) {
                mst[u] = true;
                totalWeight += cost;

                if (parent != '\0') {
                    cout << parent << " - " << u << " \t " << cost << endl;
                }

                for (auto [v, wt] : l[u]) {
                    if (!mst[v]) {
                        pq.push({wt, v, u});
                    }
                }
            }
        }

        cout << "\nTotal Weight: " << totalWeight << endl;
    }
};

int main() {
    Graph g;

    int edges;
    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < edges; i++) {
        char u, v;
        int wt;
        cin >> u >> v >> wt;
        g.addEdge(u, v, wt);
    }

    char src;
    cout << "Enter starting node: ";
    cin >> src;

    g.primsAlgo(src);

    return 0;
}