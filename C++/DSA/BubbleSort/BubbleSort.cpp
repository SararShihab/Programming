#include <iostream>
using namespace std;

void printArray(int a[], int n)
{
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int a[], int n)
{
    bool isSwap = false;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                isSwap = true;
            }
        }
        if (!isSwap)
        {
            cout << "The array is already sorted." << endl;
            return;
        }
        
    }
    printArray(a, n);
}
int main()
{
    // int a[] = {78, 55, 34, 90, 64, 37, 59, 85};
    int a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a) / sizeof(int);
    bubbleSort(a, n);
    return 0;
}