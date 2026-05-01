#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class LCS{
    private:
    string x, y;

    void displayResult(const vector<vector<int>> &dp){
        int i = x.length();
        int j = y.length();
        string res = "";

        while(i>0 && j>0){
            if(x[i-1] == y[j-1]){
                res += x[i-1];
                i--;
                j--;
            } else if(dp[i-1][j] > dp[i][j-1]){
                i--;
            } else{
                j--;
            }
        }
        reverse(res.begin(), res.end());

        cout << "\n---------------------------------" << endl;
        cout << "Matching String: " << res << endl;
        cout << "Length         : " << dp[x.length()][y.length()] << endl;
        cout << "---------------------------------" << endl;
    }
    
    public:
    void solve(string s1, string s2){
        x = s1;
        y = s2;
        int m = x.length();
        int n = y.length();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j<=n; j++) {
                if(x[i-1]==y[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                } else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        displayResult(dp);
    }
};

int main(){
    string s1, s2;
    cout << "Enter both strings: " << endl;
    cin >> s1 >> s2;

    LCS solver;
    solver.solve(s1, s2);

    return 0;
}

/*
PRESIDENT
PROVIDENCE
*/