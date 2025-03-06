#include<bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    
    char target;
    cout << "Enter a character to search: ";
    cin >> target;

    if(str.find(target) != string::npos)
    {
        cout << "The character '" << target << "' exists in the string.";
    }
    else
    {
        cout << "The character '" << target << "' does not exists in the string.";
    }
    
    return 0;
}