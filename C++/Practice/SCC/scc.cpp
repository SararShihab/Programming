#include<iostream>
#include<unordered_map>
#include<vector>
#include<stack>
using namespace std;

class SCC{
    private:
    unordered_map<char, vector<char>> adj, revAdj;
    unordered_map<char, bool> vsted;
    stack<char> st;

    void dfs1(char u){
        vsted[u] = true;

        for(char v: adj[u]){
            if(!vsted[v]){
                dfs1(v);
            }
        }
        st.push(u);
    }

    void dfs2(char u){
        vsted[u] = true;
        cout << u << " ";
        for(char v: revAdj[u]){
            if(!vsted[v]){
                dfs2(v);
            }
        }
    }

    public:
    void addEdge(char u, char v){
        adj[u].push_back(v);
        revAdj[v].push_back(u);
    }

    void findSCC(){
        for(auto &p: adj){
            vsted[p.first]= false;
        }
        
        for(auto &p: adj){
            if(!vsted[p.first]){
                dfs1(p.first);
            }
        }

        for(auto &p: adj){
            vsted[p.first]=false;
        }

        int sccCounter = 1;

        while(!st.empty()){
            char u = st.top();
            st.pop();

            if(!vsted[u]){
                cout << "SCC" << sccCounter << ": ";
                dfs2(u);
                sccCounter++;
                cout<<endl;
            }
            
        }
    }
};

int main(){
    int E;
    cin >> E;
    SCC s;
    for(int i = 0; i < E; i++){
        char u, v;
        cin >> u >> v;
        s.addEdge(u, v);
    }

    s.findSCC();
    return 0;
}