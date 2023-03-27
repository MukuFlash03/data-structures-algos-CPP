/*
Problem:
https://practice.geeksforgeeks.org/problems/anagram/0
*/

#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
const int MAX_NUM = 26;

vector<string> tokenize(string str)
{
    vector <string> tokens;
    string word;
    stringstream checkstr(str.append(" "));
    while (getline(checkstr, word, ' '))
        tokens.push_back(word);
    
    return tokens;
}

vector <int> charFreq(string str)
{
    vector <int> freq(MAX_NUM,0);
    int n = str.length();
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    for (int i = 0; i < n; i++)
        freq[str.at(i) - 'a']++;
    
    return freq;
}

void checkStr(vector <int> f1, vector <int> f2)
{   
    bool flag = false;

    for(int i = 0; i < 26; i++)
    {            
        if (f1[i] == f2[i])
            flag = true;
        else if (f1[i] != f2[i])
        {
            flag = false;
            break;
        }   
    }

    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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
        string s1 = tokens[0];
        string s2 = tokens[1];
        vector <int> f1 = charFreq(s1);
        vector <int> f2 = charFreq(s2);
        checkStr(f1,f2);
        t--;
    }
    return 0;
}