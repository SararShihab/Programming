#include <iostream>
#include <cmath>
using namespace std;
int decToBin(int n)
{
    int powr = 0, bin = 0;
    while (n > 0)
    {
        int lastDig = n % 2;
        bin += lastDig * pow(10, powr);
        n /= 2;
        powr++;
    }
    return bin;
}
int main()
{
    int n;
    cout << "Enter a decimal number: ";
    cin >> n;
    cout << "The binary value is " << decToBin(n) << endl;
    return 0;
}