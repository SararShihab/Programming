#include<iostream>
#include<climits>

using namespace std;

void maxSubArraySum(int *arr, int n){
    int maxSum = INT_MIN;
    for (int start = 0; start < n; start++){
        for (int end = start; end < n; end++){
            int currentSum=0;
            for (int i = start; i <= end; i++){
                currentSum += arr[i];
            }
            maxSum = max(maxSum, currentSum); 
        }
    }
    cout << "Maximum sum of Subarrays: " << maxSum;
}

int main(){
    int arr[] = {2, -3, 6, -5, 4, 2};
    int n = sizeof(arr)/sizeof(int);

    maxSubArraySum(arr, n);

    return 0;
}