#include<iostream>
using namespace std;

void printArr(int a[], int n){
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void insertionSort(int a[], int n){
    for (int i = 1; i < n; i++)
    {
        int curr = a[i];
        int prev = i-1;
        while(prev >=0 && a[prev]>curr){
            swap(a[prev], a[prev+1]);
            prev--;
        }
        a[prev+1] = curr;
    }
    printArr(a, n);
}

int main(){
    int a[] = {5, 8, 9, 11, 25, 29};
    int n = sizeof(a)/sizeof(int);
    insertionSort(a, n);
    return 0;
}