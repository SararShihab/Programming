#include<bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    char target;

    cout << "Enter a string: ";
    getline(cin, str);

    cout << "Enter a character to search: ";
    cin >> target;

    int x = count(str.begin(), str.end(), target);

    cout << "The character '" << target << "' appears " << x << " times in the string.";

    return 0;
}