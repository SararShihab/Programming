#include<iostream>
using namespace std;

void printArray(int revArr[], int n){
    cout << "Reversed Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << revArr[i] << " ";
    }
    cout << endl;
}

void revArray(int *arr, int n){
    int start = 0, end = n-1;
    while(start<end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    printArray(arr, n);
}

int main(){
    int arr[] ={7, 4, 5, 9, 10};
    int n = sizeof(arr)/sizeof(int);
    revArray(arr, n);
    return 0;
}