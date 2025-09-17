#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, sum = 0;

    cout << "Enter a positive integer number: ";
    cin >> n;

    for (int i = 1; i <= n; i += 1)
    {
        if (i % 2 != 0)
        {
            sum += i;
        }
    }

    cout << "Sum of the odd numbers between 1 and " <<n<< " is: " <<sum<<endl;

    return 0;
}
