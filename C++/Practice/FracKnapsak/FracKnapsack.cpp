#include <iostream>
#include <iomanip>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

class Knapshak {
private:
    vector<tuple<char, int, int>> items;

public:
    void addItem(char it, int p, int w) {
        items.push_back({it, p, w});
    }

    void solve(int capacity) {
        sort(items.begin(), items.end(), [](const auto& a, const auto& b) {
            auto [it1, p1, w1] = a;
            auto [it2, p2, w2] = b;
            return (double)p1 / w1 > (double)p2 / w2;
        });

        double totalProfit = 0.0;
        int currentWeight = 0;

        cout << "\n------------------------------------" << endl;
        cout << "Item \t Weight \t Profit" << endl; 
        cout << "------------------------------------" << endl;

        for (auto [it, p, w] : items) {
            if (currentWeight + w <= capacity) {
                currentWeight += w;
                totalProfit += p;
                cout << it << " \t " << w << " \t\t " << (double)p << endl;
            } else {
                int remaining = capacity - currentWeight;
                double fractionProfit = p * ((double)remaining / w);
                totalProfit += fractionProfit;

                cout << it << " \t " << remaining << " \t   (f)  " << fixed << setprecision(2) << fractionProfit << endl;

                currentWeight = capacity;
                break;
            }
        }

        cout << "------------------------------------" << endl;
        cout << "Total: \t\t\t " << fixed << setprecision(2) << totalProfit << endl;
        cout << "------------------------------------" << endl;
    }
};

int main() {
    int n;
    cin >> n;

    Knapshak bag;

    for (int i = 0; i < n; i++) {
        char it;
        int p, w;
        cin >> it >> p >> w;
        bag.addItem(it, p, w);
    }

    int capacity;
    cin >> capacity;

    bag.solve(capacity);
    return 0;
}


/*
7
1 12 3
2 5 1
3 16 4
4 7 2
5 9 9
6 11 4
7 6 3
15
*/