#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int tar){
    int start = 0;
    int end = n-1;
    while(start<=end){
        int mid = (start + end)/2;
        if(tar == arr[mid]){
            return mid;
        }
        else if(tar < arr[mid]){
            end = mid -1;
        }
        else if(tar > arr[mid]){
            start = mid + 1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {4, 8, 10, 25, 50, 54};
    int n = sizeof(arr)/sizeof(int);
    int tar;
    cout << "Enter the target value: ";
    cin >> tar;
    int rslt = binarySearch(arr, n, tar);
    if(rslt < 0){
        cout << "Target value not found." << endl;
    }
    else{
        cout << "Target value found at index " << rslt << endl;
    }
    return 0;
}