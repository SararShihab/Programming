#include<iostream>
#include<climits>

using namespace std;

void kadane(int *arr, int n){
    int maxSum = INT_MIN;
    int currentSum = 0;
 
    for (int i = 0; i < n; i++) {
        currentSum += arr[i];
        maxSum = max(maxSum, currentSum);
        
        if(currentSum<0){
            currentSum = 0;
        }
    }
    cout << "Maximum sum of Subarrays: " << maxSum;
}

int main(){
    int arr[] = {2, -3, 6, -5, 4, 2};
    int n = sizeof(arr)/sizeof(int);

    kadane(arr, n);
}