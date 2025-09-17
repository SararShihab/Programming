#include<iostream>
using namespace std;

int LinSearch(int arr[], int n, int k){
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==k){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = {2, 4, 6, 8, 10, 12, 14 ,16};
    int n = sizeof(arr)/sizeof(int);
    int k;
    cout << "Enter search item: ";
    cin >> k;
    int rslt = LinSearch(arr, n, k);
    if(rslt<0){
        cout << "Item not found." << endl;
    }
    else{
        cout << "Item found at " << rslt << "th index" << endl;
    }
    return 0;
}