#include <iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    bool isPrime = true;
    cout << "Enter a Number: ";
    cin >> n;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            isPrime = false;
        }
    }
    if (isPrime)
    {
        cout << "Prime Number.";
    }
    else
    {
        cout << "Not a Prime Number.";
    }

    return 0;
}