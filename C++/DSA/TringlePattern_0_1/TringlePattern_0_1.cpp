#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter Row Number: ";
    cin >> n;
    bool val = 1;
    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= i; j++)
        {
            cout << val;
            val = !val;
            // if (i % 2 != 0)
            // {
            //     if (j == 1)
            //     {
            //         cout << 1;
            //     }
            //     else
            //     {
            //         cout << "01";
            //         j++;
            //     }
            // }
            // else
            // {
            //     cout << "01";
            //     j++;
            // }
        }
        cout << endl;
    }
}