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

void revArray(int arr[], int n){
    int copyArr[n];
    for (int i = 0; i < n; i++)
    {
        copyArr[i] = arr[n-1-i];
    }
    
    // for (int i = 0; i < n; i++)
    // {
    //     arr[i] = copyArr[i];
    // }
    
    printArray(copyArr, n);
    
    //printArray(arr, n);
}

int main(){
    int arr[] ={5, 4, 3, 9, 2};
    int n = sizeof(arr)/sizeof(int);
    revArray(arr, n);
    return 0;
}