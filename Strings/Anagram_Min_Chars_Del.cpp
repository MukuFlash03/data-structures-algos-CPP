/*
Problem:
https://practice.geeksforgeeks.org/problems/anagram-of-string/1
*/

#include <bits/stdc++.h>
using namespace std;
const int MAX_NUM = 26;

vector <int> charFreq(string str)
{
    vector <int> freq(MAX_NUM,0);
    int n = str.length();

    for (int i = 0; i < n; i++)
        freq[str.at(i) - 'a']++;
    
    return freq;
}

void checkAnagrams (string s1, string s2)
{
    int count = 0;
    vector <int> f1 = charFreq(s1);
    vector <int> f2 = charFreq(s2);
    for (int i = 0; i < MAX_NUM; i++)
        count += (max(f1[i],f2[i]) - min(f1[i],f2[i]));
    
    cout << count << endl;
}

int main()
{
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    checkAnagrams(s1,s2);
    return 0;
}