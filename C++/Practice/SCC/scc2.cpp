#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class SCC{
    private:
        void dfs1(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st){
            vis[node]=1;

            for(int neighbor:adj[node]){
                if(!vis[neighbor]){
                    dfs1(neighbor, vis, adj, st);
                }
            }

            st.push(node);
        }

        void dfs2(int node, vector<int> &vis, vector<vector<int>> &adjT, vector<int> &component){
            vis[node]=1;
            component.push_back(node);
            for(int neighbor:adjT[node]){
                if(!vis[neighbor]){
                    dfs2(neighbor, vis, adjT, component);
                }
            }
        }
    
    public:
        void kosaraju(int V, vector<vector<int>> &adj){
            vector<int> vis(V, 0);
            stack<int> st;

            for(int i=0; i<V; i++){
                if(!vis[i]){
                    dfs1(i, vis, adj, st);
                }
            }

            vector<vector<int>> adjT(V);

            for(int i=0; i<V;i++){
                vis[i]=0;
                for(int neighbor:adj[i]){
                    adjT[neighbor].push_back(i);
                }
            }

            int sccCount=0;
            cout<<"\n== Present SCCs ==\n"<<endl;
            while(!st.empty()){
                int node = st.top();
                st.pop();

                if(!vis[node]){
                    vector<int> component;

                    dfs2(node, vis, adjT, component);

                    sccCount++;

                    cout<<"SCC "<<sccCount<<": ";

                    for(int n:component){
                        cout<<n<<" ";
                    }
                    cout<<endl;
                }
            }
            cout<< "\nTotal SCC: "<<sccCount;
        }
};

int main(){
    int V,E;
    cout<<"Enter number of vertex: ";
    cin>>V;
    cout<<"Enter number of edge: ";
    cin>>E;

    vector<vector<int>> adj(V);

    cout<<"Enter directed edges(u v)\n";
    for(int i=0; i<E; i++){
        int u, v; 
        cin>>u>>v;
        adj[u].push_back(v);
    }

    SCC obj;
    obj.kosaraju(V, adj);

    return 0;
}