/*
Problem:
https://practice.geeksforgeeks.org/problems/longest-distinct-characters-in-string/0
https://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/
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

int checkSubstr (string str)
{
    set <char> chars;
    for (int i = 0; i < str.length(); i++)
    {
        if (chars.find(str[i]) == chars.end())
            chars.insert(str[i]);
        else
            return 0;
    }
    return str.size();
}

int longSubstr (string str)
{
    set <string> strsub = getSubstrings(str);
    set <string> :: iterator it;
    string word = "";
    int len = 0, flag = 0;

    for (it = strsub.begin(); it != strsub.end(); it++)
    {
        flag = len;
        len = max(len, checkSubstr(*it));
        if (flag != len)
            word = *it;
    }

    cout << word << endl;
    return len;
}


int main()
{
    string str;
    getline(cin,str);
    int len = longSubstr(str);
    cout << len << endl;
    return 0;
}