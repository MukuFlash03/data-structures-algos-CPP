/*
Problem:
https://www.geeksforgeeks.org/print-common-characters-two-strings-alphabetical-order-2/?ref=rp
*/

#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
const int MAX_NUM = 26;

vector <int> charFreq(string str)
{
    vector <int> freq(MAX_NUM,0);
    int n = str.length();
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    for (int i = 0; i < n; i++)
        freq[str.at(i) - 'a']++;
    
    return freq;
}

void printCommon(vector <int> f1, vector <int> f2)
{
    for (int i = 0; i < 26; i++)
    {
        int a1 = f1[i];
        int a2 = f2[i];
        if(a1 != 0 && a2 != 0)
        {
            for (int j = 0; j < min(a1,a2); j++)
                cout << (char)('a' + i);
        }
    }
}

int main()
{
    string s1, s2;
    getline(cin,s1);
    getline(cin,s2);
    vector <int> f1 = charFreq(s1);
    vector <int> f2 = charFreq(s2);
    printCommon(f1,f2);
    return 0;
}