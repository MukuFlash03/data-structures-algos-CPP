/*
Problem:
https://www.geeksforgeeks.org/print-characters-frequencies-order-occurrence/?ref=rp
*/

#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
const int MAX_NUM = 26;

void charFreq(string str)
{
    vector <int> freq(MAX_NUM,0);
    int n = str.length();
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    for (int i = 0; i < n; i++)
        freq[str.at(i) - 'a']++;

    for (int i = 0; i < n; i++)
    {
        if (freq[str.at(i) - 'a'] != 0)
            cout << str.at(i) << freq[str.at(i) - 'a'] << " ";
        
        freq[str.at(i) - 'a'] = 0;
    }
}

int main()
{
    string str;
    getline(cin,str);
    charFreq(str);
    return 0;
}