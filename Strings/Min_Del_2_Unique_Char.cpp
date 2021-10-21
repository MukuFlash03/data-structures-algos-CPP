/*
Problem:
https://www.geeksforgeeks.org/minimum-deletions-from-string-to-reduce-it-to-string-with-at-most-2-unique-characters/?ref=rp
*/

#include <string>
#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;
const int LETTER_NUM = 26;

vector <int> charFreq (string str)
{
    int n = str.length();
    vector <int> freq(LETTER_NUM, 0);

    for (int i = 0; i < n; i++)
        freq[str.at(i) - 'a'] += 1;
    return freq;
}

int minDel (vector <int> freq, string str)
{
    int n, i, j, z, minimum;
    n = str.length();
    minimum = INT_MAX;
    
    for (i = 0; i < 26; i++)
    {
        for (j = i + 1; j < 25; j++)
        {
            z = freq[i] + freq[j];
            minimum = min(minimum, n - z);  
        }
    }
    return minimum;
}

int main()
{
    string s;
    getline(cin,s);
    vector <int> freq = charFreq(s);
    int ans = minDel(freq, s);
    cout << ans << endl;
}