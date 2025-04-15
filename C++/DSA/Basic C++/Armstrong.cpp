#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, sum = 0, count = 0;
    cout << "Enter a number: ";
    cin >> n;
    int m = n;
    int p = m;
    while (n != 0)
    {
        n /= 10;
        count++;
    }
    while (p != 0)
    {
        n = p % 10;
        sum += pow(n, count);
        p /= 10;
    }
    if (sum == m)
    {
        cout << "Armstrong Number.";
    }
    else
    {
        cout << "Not an Armstrong Number.";
    }

    return 0;
}
