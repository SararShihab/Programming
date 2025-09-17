#include <iostream>
using namespace std;

int main()
{
    int arr[] = {4, 8, 9, 3, 1, 6};
    int len = sizeof(arr) / sizeof(int);
    int max = arr[0];
    int min = arr[0];
    for (int i = 0; i < len; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
        if (min > arr[i])
        {
            min = arr[i];
        }
        
    }
    cout << "Maximum value is " << max << endl;
    cout << "Minimum value is " << min << endl;
    return 0;
}