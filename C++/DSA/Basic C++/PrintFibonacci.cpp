#include<iostream>
using namespace std;
int main()
{
    int n, first = 0, second = 1;
    cout << "Enter a number: ";
    cin >> n;
    if (n==1)
    {
        cout << first;
    }
    else if(n==2){
        cout << first << " " << second;
    }
    else{
        cout << first << " " << second << " ";
        for (int i = 3; i <= n; i++)
        {
            int third = first+second;
            cout << third << " ";
            first = second;
            second = third;
        }
        
    }
    return 0;
}