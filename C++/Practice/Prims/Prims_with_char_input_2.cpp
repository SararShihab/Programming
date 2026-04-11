#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Prims {
private:
    vector<char> src, dst;
    vector<int> wt;

    void printMST(int V, vector<int> &parent, vector<int> &minCost) {
        int totalWeight = 0;
        cout << "\n== Minimum Spanning Tree Edges ==\n" << endl;
        cout << "\tEdge\tWeight" << endl;

        for (int i = 0; i < V; i++) {
            if (parent[i] != -1) {
                char u = (char)(parent[i] + 'A');
                char v = (char)(i + 'A');
                cout << "\t" << u << " - " << v << "\t" << minCost[i] << endl;
                totalWeight += minCost[i];
            }
        }
        cout << "\nTotal MST Weight: " << totalWeight << endl;
    }

public:
    void addEdge(char u, char v, int w) {
        src.push_back(u);
        dst.push_back(v);
        wt.push_back(w);
    }

    void calculateMST(int V, char startNodeChar) {
        int E = src.size();
        vector<int> minCost(V, INT_MAX);
        vector<int> parent(V, -1);
        vector<bool> inMST(V, false);

        int startNode = startNodeChar - 'A';
        minCost[startNode] = 0;

        for (int i = 0; i < V; i++) {
            int u = -1, minVal = INT_MAX;
            for (int j = 0; j < V; j++) {
                if (!inMST[j] && minCost[j] < minVal) {
                    minVal = minCost[j];
                    u = j;
                }
            }

            if (u == -1) {
                break;
            }
            inMST[u] = true;

            char uChar = (char)(u + 'A');

            for (int k = 0; k < E; k++) {
                char neighborChar;
                if (src[k] == uChar) {
                    neighborChar = dst[k];
                } else if (dst[k] == uChar) {
                    neighborChar = src[k];
                } else {
                    continue;
                }

                int v = neighborChar - 'A';
                if (!inMST[v] && wt[k] < minCost[v]) {
                    parent[v] = u;
                    minCost[v] = wt[k];
                }
            }
        }
        printMST(V, parent, minCost);
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    Prims obj;

    cout << "Enter edges (u v w):" << endl;
    for (int i = 0; i < E; i++) {
        char u, v;
        int w;
        cin >> u >> v >> w;
        obj.addEdge(u, v, w);
    }

    char startNode;
    cout << "Enter starting vertex: ";
    cin >> startNode;

    obj.calculateMST(V, startNode);

    return 0;
}


/*
edge inputs: 
S A 7
S C 8
A B 6
A B 9
A C 3
C B 4
C D 3
C C 1
B D 2
B T 5
D T 2
*/