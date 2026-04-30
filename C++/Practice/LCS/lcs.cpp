#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class LCS {
private:
    string X, Y;

    void displayResults(const vector<vector<int>>& dp) {
        int i = X.length();
        int j = Y.length();
        string res = "";

        while (i > 0 && j > 0) {
            if (X[i - 1] == Y[j - 1]) {
                res += X[i - 1];
                i--; j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
        reverse(res.begin(), res.end());

        cout << "\n------------------------------------" << endl;
        cout << "Matching String: " << res << endl;
        cout << "Length         : " << dp[X.length()][Y.length()] << endl;
        cout << "------------------------------------" << endl;
    }

public:
    void solve(string s1, string s2) {
        X = s1; 
        Y = s2;
        int m = X.length();
        int n = Y.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (X[i - 1] == Y[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        displayResults(dp);
    }
};

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    LCS solver;
    solver.solve(s1, s2);

    return 0;
}

/*
PRESIDENT
PROVIDENCE
*/