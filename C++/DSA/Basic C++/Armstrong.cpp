#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n, sum, count;
    cout<<"n = ";
    cin>>n;
    int m = n;
    int j = m;
    while (n!=0)
    {
        n = n/10;
        count ++;
    }
    while (j!=0)
    {
        n=j%10;
        sum += pow(n, count);
        j=j/10;
    }
    if (sum == m)
    {
        cout<<"Armstrong."<<endl;
    }
    else
    {
        cout<<"Not an Armstrong."<<endl;
    }
    
    

}