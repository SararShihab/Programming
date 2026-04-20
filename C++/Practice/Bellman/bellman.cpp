#include<iostream>
#include<vector>
#include<climits>
#include<unordered_map>
#include<tuple>

using namespace std;

class Bellman{
    private:
    vector<tuple<char, char, int>> edges;
    vector<char> uniqueVertices;
    unordered_map<char, bool> exists;

    void printDst(char srcNode, unordered_map<char, int> &dst){
        cout << "\n------------------------------------" << endl;
        cout << "Vertex \t Distance from " << srcNode << endl;
        cout << "------------------------------------" << endl;
        
        for(char v : uniqueVertices){
            cout << v << " \t ";
            if(dst[v] == INT_MAX){
                cout << "INF";
            } else{
                cout << dst[v];
            }
            cout << endl;
        }
        cout << "------------------------------------" << endl;
    }

    public:
    void addEdge(char u, char v, int w){
        edges.push_back({u, v, w});

        if(!exists[u]){
            uniqueVertices.push_back(u);
            exists[u] = true;
        }
        if(!exists[v]){
            uniqueVertices.push_back(v);
            exists[v] = true;
        }
    }

    void shortest(char srcNode){
        unordered_map<char, int> dst;

        for(char v: uniqueVertices){
            dst[v]=INT_MAX;
        }

        if(exists.count(srcNode)){
            dst[srcNode]=0;
        }

        int V = uniqueVertices.size();

        for(int i = 1; i<= V-1; i++){
            for( auto [u, v, w] : edges){
                if (dst[u] != INT_MAX && dst[u]+w < dst[v]){
                    dst[v]=dst[u]+w;
                }
            }
        }

        bool hasCycle = false;
        for(auto [u,v,w] : edges){
            if(dst[u] != INT_MAX && dst[u]+w<dst[v]){
                hasCycle = true;
                break;
            }
        }

        if(hasCycle){
            cout<<"\nError: Graph contains a negative cycle..." << endl;
        } else{
            printDst(srcNode, dst);
        }
    }
};

int main(){
    int E;
    cin>>E;

    Bellman graph;

    for(int i=0; i<E; i++){
        char u, v;
        int w;
        cin>>u>>v>>w;
        graph.addEdge(u,v,w);
    }

    char srcNode;
    cin>>srcNode;

    graph.shortest(srcNode);

    return 0;
}

/*
10
1 2 6
1 3 5
1 4 5
2 5 -1
3 2 -2
3 5 1
4 3 -2
4 6 -1
5 7 3
6 7 3
1
*/