#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
using namespace std;

class Knapshak{
    private:
    vector<tuple<char, int, int>> items;

    void display(const vector<vector<int>> &dp, int capacity){
        int n = items.size();
        int w = capacity;
        int profit = dp[n][capacity];
        cout<<endl<<"it"<<" p"<< " wt" << endl;
        for(int i = n; i>0 && profit>0; i--){
            if(profit!=dp[i-1][w]){
                auto[it, p, wt]=items[i-1];
                cout<<it<<"  "<<p<<"  "<<wt<<endl;
                profit-=p;
                w-=wt;
            }
        }

        cout<<"total profit: "<< dp[n][capacity];
    }

    public:
    void addItem(char it, int p, int wt){
        items.push_back({it, p, wt});
    }
    void solve(int capacity){
        int n=items.size();
        vector<vector<int>> dp(n+1, vector<int>(capacity+1, 0));
        
        for(int i = 1; i<=n; i++){
            auto[it, p, wt] = items[i-1];
            for(int j=0; j <= capacity; j++){
                if(wt<=j){
                    dp[i][j]=max(dp[i-1][j], p+dp[i-1][j-wt]);
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        display(dp, capacity);
    }
};
int main(){
    int n;
    cin>>n;
    Knapshak k;
    for(int i=0; i<n; i++){
        char it;
        int p, wt;
        cin>>it>>p>>wt;
        k.addItem(it, p, wt);
    }
    int capacity;
    cin>>capacity;
    k.solve(capacity);
    return 0;
}