#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

class Knapshak {
private:
    // Core storage: {Item ID, Profit, Weight}
    vector<tuple<char, int, int>> items;

public:
    void addItem(char obj, int p, int w) {
        items.push_back({obj, p, w});
    }

    void solve(int capacity) {
        int n = items.size();
        
        // DP table initialization
        vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

        // Building the table using Dynamic Programming logic
        for (int i = 1; i <= n; i++) {
            auto [obj, p, w] = items[i - 1];

            for (int j = 0; j <= capacity; j++) {
                if (w <= j) {
                    // Standard 0/1 DP: Max of (Include Profit vs. Exclude Item)
                    dp[i][j] = max(p + dp[i - 1][j - w], dp[i - 1][j]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        displayResults(dp, capacity);
    }

private:
    void displayResults(const vector<vector<int>>& dp, int capacity) {
        int n = items.size();
        
        cout << "\n------------------------------------" << endl;
        cout << "Item \t Weight \t Profit" << endl; 
        cout << "------------------------------------" << endl;

        int res = dp[n][capacity];
        int w = capacity;

        // Backtracking to identify selected items
        for (int i = n; i > 0 && res > 0; i--) {
            if (res != dp[i - 1][w]) {
                auto [obj, p, wt] = items[i - 1];
                
                // Matching your output alignment style
                cout << obj << " \t " << wt << " \t\t " << (double)p << endl;
                
                res -= p;
                w -= wt;
            }
        }

        cout << "------------------------------------" << endl;
        cout << "Total: \t\t\t " << (double)dp[n][capacity] << ".00" << endl;
        cout << "------------------------------------" << endl;
    }
};

int main() {
    int n;
    cin >> n;

    Knapshak bag;

    for (int i = 0; i < n; i++) {
        char obj;
        int p, w;
        cin >> obj >> p >> w;
        bag.addItem(obj, p, w);
    }

    int capacity;
    cin >> capacity;

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