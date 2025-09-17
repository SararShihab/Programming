#include<iostream>
using namespace std;

int fact(int a)
{
    int f = 1;
    for (int i = 1; i <= a; i++)
    {
        f *= i;
    }
    return f;
}
int cofficient(int n, int r)
{
    return fact(n)/(fact(r)*fact(n-r));
}
int main()
{
    int n, r;
    cout << "Enter the values of n and r: ";
    cin >> n;
    cin >> r;
    cout << "The binomial cofficient is " << cofficient(n, r) << endl;

}