#include<iostream>
#include<cmath>
using namespace std;

int convert(int n){
    int power = 0, cnv = 0;
    while(n>0){
        int rem = n%10;
        cnv += rem*pow(2, power);
        n /= 10;
        power++;
    }
    return cnv;
}

int main()
{
    int n;
    cout << "Enter a binary number: ";
    cin >> n;
    cout << "Decimal Number: " << convert(n) << endl;
}