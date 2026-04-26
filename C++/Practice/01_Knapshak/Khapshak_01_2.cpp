#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

using namespace std;

class Knapshak{
    private:
    vector<tuple<char, int , int>> items;

    void displayResults(const vector<vector<int>> &dp, int capacity){
        int n = items.size();

        cout<<"\n----------------------------------------"<<endl;
        cout<<"Object \t Weight \t Profit"<<endl;
        cout<<"----------------------------------------"<<endl;

        int res = dp[n][capacity];
        int w = capacity;

        for(int i=n; i>0 && res>0; i--){
            if(res != dp[i-1][w]){
                auto [obj, p, wt] = items[i-1];

                cout << obj << " \t " << wt << " \t\t " << (double)p << endl;

                res -= p;
                w -= wt;
            }
        }

        cout<<"----------------------------------------"<<endl;
        cout<<"Total: \t\t\t " << (double)dp[n][capacity] << ".00" <<endl;
        cout<<"----------------------------------------"<<endl;
    }

    public:
    void addItem(char obj, int p, int w){
        items.push_back({obj, p, w});
    }

    void solve(int capacity){
        int n = items.size();

        vector<vector<int>> dp(n+1, vector<int>(capacity+1, 0));

        for(int i=1; i<=n; i++){
            auto [obj, p, w] = items[i-1];

            for(int j=0; j<=capacity; j++){
                if(w<=j){
                    dp[i][j]=max(dp[i-1][j], p + dp[i-1][j-w]);
                } else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        displayResults(dp, capacity);
    }
};

int main(){
    int n;
    cin>>n;

    Knapshak bag;

    for(int i=0; i<n; i++){
        char obj;
        int p, w;
        cin>>obj>>p>>w;
        bag.addItem(obj, p, w);
    }

    int capacity;
    cin>>capacity;

    bag.solve(capacity);
    return 0;
}

/*
4
1 4 3
2 3 2
3 6 5
4 5 4
5
*/