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

void selectionSort(int a[], int n){
    for (int i = 0; i < n-1; i++)
    {
        int minIdx = i;
        for (int j =  i+1; j < n; j++)
        {
            if(a[j]<a[minIdx]){
                minIdx = j;
            }
            
        }
        swap(a[i], a[minIdx]);
    }
    printArr(a, n);
}

int main(){
    int a[] = {40, 7, 9, 22, 6, 8};
    int n = sizeof(a)/sizeof(int);
    selectionSort(a, n);
    return 0;
}