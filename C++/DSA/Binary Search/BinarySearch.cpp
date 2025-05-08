#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int tar){
    int start = arr[0];
    int end = arr[n-1];
    while(start>=end){
        int mid = (start + end)/2;
        if(tar > mid){
            start = mid + 1;
        }
        else if(tar < mid){
            end = mid -1;
        }
        else if(tar == mid){
            return mid;
        }
        else{
            return -1;
        }
    }
}

int main(){
    int arr[] = {4, 8, 10, 25, 50, 54};
    int n = sizeof(arr)/sizeof(int);
    int tar;
    cout << "Enter the target value: ";
    cin >> tar;
    int ret = binarySearch(arr, n, tar);
    cout << ret << endl;
    return 0;
}