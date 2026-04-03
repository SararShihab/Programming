#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class BellmanFord {
private:
    vector<int> src, dst, wt;

    void printDistances(int V, vector<int> &dist, int srcNode) {
        cout << "\n== Shortest Distances from Source " << srcNode << " ==\n" << endl;
        cout << "Vertex\tDistance" << endl;

        for (int i = 1; i <= V; i++) {
            cout << i << "\t";
            if (dist[i] == INT_MAX) cout << "INF";
            else cout << dist[i];
            cout << endl;
        }
    }

public:
    void addEdge(int u, int v, int w) {
        src.push_back(u);
        dst.push_back(v);
        wt.push_back(w);
    }

    void findShortestPath(int V, int srcNode) {
        int E = src.size();

        vector<int> dist(V + 1, INT_MAX);
        dist[srcNode] = 0;

        // Relax edges V-1 times
        for (int i = 1; i <= V - 1; i++) {
            for (int j = 0; j < E; j++) {
                int u = src[j];
                int v = dst[j];

                if (dist[u] != INT_MAX && dist[u] + wt[j] < dist[v]) {
                    dist[v] = dist[u] + wt[j];
                }
            }
        }

        // Check negative cycle
        bool hasCycle = false;
        for (int j = 0; j < E; j++) {
            int u = src[j];
            int v = dst[j];

            if (dist[u] != INT_MAX && dist[u] + wt[j] < dist[v]) {
                hasCycle = true;
                break;
            }
        }

        if (hasCycle) {
            cout << "\nError: Graph contains a negative weight cycle!" << endl;
        } else {
            printDistances(V, dist, srcNode);
        }
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    BellmanFord graph;

    cout << "Enter edges (u v wt):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    graph.findShortestPath(V, src);

    return 0;
}