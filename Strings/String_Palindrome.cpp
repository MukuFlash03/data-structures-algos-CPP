/*
Problem:
https://practice.geeksforgeeks.org/problems/palindrome-string/0
https://practice.geeksforgeeks.org/problems/save-ironman/0
*/

#include <bits/stdc++.h>
using namespace std;

string extractAlphaNumeric (string str)
{
    string s = "";
    for (int i = 0; i < str.length(); i++)
        if (isalpha(str.at(i))|| isdigit(str.at(i)))
            s += str.at(i);

    return s;
}

void checkPalin(string str)
{
    string s = "";
    s.assign(str);
    int l = s.length();

    for (int i = 0; i < l/2; i++)
        swap(s[i],s[l-i-1]);

    if ( !str.compare(s) )
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
}

int main()
{
    string str;
    getline(cin,str);
    transform (str.begin(), str.end(), str.begin(), ::tolower);
    string s = extractAlphaNumeric(str);
    checkPalin(s);
    return 0;
}