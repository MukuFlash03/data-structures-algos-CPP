/*
Problem URL
https://www.geeksforgeeks.org/strings-formed-from-given-characters-without-any-consecutive-repeating-characters/?ref=rp
*/

#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool check (string s1, string s2)
{
    set <char> str2;
    for (int i = 0; i < s2.length(); i++)
        str2.insert(s2[i]);

    for (char c : s1)
        if (str2.find(c) == str2.end())
            return false;

    for (int i = 0; i < s1.length() - 1; i++)
        if (s1[i] == s1[i+1])
            return false;

    return true; 
}

void generateString (vector <string> strarr, string str)
{
    vector <string> :: iterator i;
    for (i = strarr.begin(); i != strarr.end(); i++)
    {
        if (check (*i, str))
            cout << *i << endl;
    }
}

int main ()
{
    string s2;
    getline(cin,s2);

    /*Enter strings separated by a space; Input tokenization*/
    string str;
    getline(cin,str);
    str += ' ';
    vector <string> tokens;
    stringstream checkstr(str);
    string word;
    while(getline(checkstr,word, ' '))
        tokens.push_back(word);

    generateString (tokens,s2);
    return 0;
    
}