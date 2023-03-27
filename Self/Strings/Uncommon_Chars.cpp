/*
Problem:
https://practice.geeksforgeeks.org/problems/uncommon-characters/0/
*/

#include <bits/stdc++.h>
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

void checkStr (string s1, string s2)
{
    vector <int> f1 = charFreq(s1);
    vector <int> f2 = charFreq(s2);

    for (int i = 0; i < MAX_NUM; i++)
    {
        if ((f1[i] == 0 && f2[i] == 0) || (f1[i] != 0 && f2[i] != 0))
            continue;
        else
            cout << (char)(i + 'a');
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(32767, '\n');
    
    while (t > 0)
    {
        string s1,s2;
        getline(cin,s1);
        getline(cin,s2);
        checkStr(s1,s2);
        t--;
    }
    return 0;
}