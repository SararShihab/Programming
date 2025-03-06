#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {3,23,4,34,34,3,8,2,23,2,3,1,3,4,1,4,2,3,4,1,4,1,4,2,3,4,134,234,14,23,4,123,42,42,42,241,24,124,42,42,5,5,645,64,64,6,756,756,75,8,8,9,79,98,9};
    
    int len = size(arr);
    
    sort(arr, arr + len);
    
    cout << "Minimum is: " << arr[0] << endl;
    cout << "Maximum is: " << arr[len -1];
    
    return 0;
}