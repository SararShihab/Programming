#include<iostream>
#include<unordered_map>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

class GraphTraversal{
    private:
    unordered_map<char, vector<char>> adj;

    public:
    void addEdge(char u, char v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void bfs(char st){
        unordered_map<char, bool> vsted;
        queue<char> q;

        vsted[st]=true;
        q.push(st);
        cout << "BFS: ";
        while(!q.empty()){
            char u = q.front();
            q.pop();
            cout << u << " ";

            for(char v:adj[u]){
                if(!vsted[v]){
                    vsted[v]=true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }
  
    void dfs(char st){
        unordered_map<char, bool> vsted;
        stack<char> s;

        vsted[st] = true;
        s.push(st);
        cout << "DFS: ";
        while(!s.empty()){
            char u = s.top();
            s.pop();
            cout << u << " ";

            for(auto it = adj[u].rbegin(); it != adj[u].rend(); ++it){
                if(!vsted[*it]){
                    vsted[*it]=true;
                    s.push(*it);
                }
            }
        }
    }
};

int main(){
    int E;
    cin>>E;
    GraphTraversal gt;
    for(int i = 0; i<E; i++){
        char u, v;
        cin >> u >> v;
        gt.addEdge(u, v);
    }

    char s;
    cin >> s;
    gt.bfs(s);
    gt.dfs(s);
    return 0;
}