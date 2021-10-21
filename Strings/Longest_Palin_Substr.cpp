/*
Problem:
https://practice.geeksforgeeks.org/problems/longest-palindromic-substring-in-linear-time/1
*/

#include <bits/stdc++.h>
using namespace std;

set <string> getSubstrings (string str)
{
    int l = str.length();
    set <string> strsub;

    for (int i = 0; i < l; i++)
        for (int j = 1; j <= l - i; j++)
            strsub.insert(str.substr(i,j));

   return strsub;
}

int checkPalin(string str)
{
    string s = "";
    s.assign(str);
    int l = s.length();

    for (int i = 0; i < l/2; i++)
        swap(s[i],s[l-i-1]);

    if ( !str.compare(s) )
         return str.length();
    else
        return 0;
}

void longPalin (string str)
{
    set <string> strsub = getSubstrings(str);
    set <string> :: iterator it;
    int flag = 0, len = 0;
    string word = "";

    for (it = strsub.begin(); it != strsub.end(); it++)
    {
        flag = len;
        len = max(len, checkPalin(*it));
        if (flag != len)
            word = *it;
    }
    cout << word << endl;
}

int main()
{
    string str;
    getline(cin,str);
    longPalin(str);
    return 0;
}