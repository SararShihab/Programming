#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;

    cout << "Enter the length of the array: ";
    cin >> n;

    if(n <= 0)
    {
        cout << "Invalid input. Please enter a positive integer.";
        
        return 1;
    }

    int arr[n];

    cout << "Enter " << n << " elements of the array: ";
    
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the index for calculating the sum (0 to " << n-1 << "): ";
    cin >> x;

    if (x < 0 || x > n-1)
    {
        cout << "Invalid input. Please enter an value from 0 to " << n-1 << endl;
        
        return 1;
    }

    int sum = 0;

    for(int i = 0; i <= x; i++)
    {
        sum += arr[i];
    }

    cout << "The sumation between 0 to " << x << " index of the array is: " << sum << endl;

    return 0;
}