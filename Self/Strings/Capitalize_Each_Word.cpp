/*
Problem:
https://practice.geeksforgeeks.org/problems/upper-case-conversion/0
*/

#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h> 
using namespace std;

vector<string> tokenize(string str)
{
    vector <string> tokens;
    string word;
    stringstream checkstr(str);
    while (getline(checkstr, word, ' '))
    {
        word[0] = toupper(word[0]);
        tokens.push_back(word);
    }
    return tokens;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(32767, '\n');
    while (t > 0)
    {
        string str;
        getline(cin,str);
        vector <string> tokens = tokenize(str);
        auto iter = tokens.begin();
        /*while (iter != tokens.end())
            cout  << *iter++ << " ";

          */    
        string res = "";
        while (iter != tokens.end())
        {
            res += *iter + " ";
            iter++;
        }
        if (res.length() != str.length())
            res = res.substr(0,str.length());

        cout << res << endl; 
        t--;
    }
    return 0;
}