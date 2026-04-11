#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Prim {
private:
    // Habit: Separate vectors for edge list properties
    vector<char> src, dst;
    vector<int> wt;

    void printMST(int V, vector<int> &parent, vector<int> &key) {
        int totalWeight = 0;
        cout << "\n== Minimum Spanning Tree Edges ==\n" << endl;
        cout << "\tEdge\tWeight" << endl;

        for (int i = 0; i < V; i++) {
            if (parent[i] != -1) {
                char u = (char)(parent[i] + 'A');
                char v = (char)(i + 'A');
                cout << "\t" << u << " - " << v << "\t" << key[i] << endl;
                totalWeight += key[i];
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
        vector<int> min_cost(V, INT_MAX); 
        vector<int> parent(V, -1);
        vector<bool> inMST(V, false);

        // Convert character input ('A') to integer index (0)
        int startNode = startNodeChar - 'A';
        min_cost[startNode] = 0; 

        for (int count = 0; count < V; count++) {
            int u = -1, minVal = INT_MAX;
            for (int i = 0; i < V; i++) {
                if (!inMST[i] && min_cost[i] < minVal) {
                    minVal = min_cost[i];
                    u = i;
                }
            }

            if (u == -1) break; 
            inMST[u] = true;

            // Convert current index u back to character to search the Edge List
            char uChar = (char)(u + 'A');

            for (int i = 0; i < E; i++) {
                char neighborChar;
                if (src[i] == uChar) neighborChar = dst[i];
                else if (dst[i] == uChar) neighborChar = src[i];
                else continue;

                int v = neighborChar - 'A'; // Convert neighbor back to index
                if (!inMST[v] && wt[i] < min_cost[v]) {
                    parent[v] = u;
                    min_cost[v] = wt[i];
                }
            }
        }
        printMST(V, parent, min_cost);
    }
};

int main() {
    int V, E;
    cout << "Enter upper range of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    Prim graph;

    cout << "Enter edges (u v w) - e.g., A B 5:" << endl;
    for (int i = 0; i < E; i++) {
        char u, v;
        int w;
        cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }

    char startNode;
    cout << "Enter starting vertex (A, B, etc.): ";
    cin >> startNode;

    graph.calculateMST(V, startNode);

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