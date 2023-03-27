/*
Problem:
https://www.geeksforgeeks.org/create-new-string-alternately-combining-characters-two-halves-string-reverse/?ref=rp
*/

#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

string alt_halves(string str)
{
    string s;
    cout << s << endl;
    int n = str.length();
    int h1 = n/2;
    int h2 = n;
    
    while (h1 > 0 && h2 > n/2)
    {
        s += str[h1-1];
        h1--;
        s += str[h2-1];
        h2--;
    }
    if (h2 > n/2)
    {
        s += str[h2-1];
        h2--;
    }
    return s;
}

int main()
{
    string str;
    getline(cin,str);
    string str1 = alt_halves(str);
    cout << str1 << endl;
}