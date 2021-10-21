/*
Problem:
https://practice.geeksforgeeks.org/problems/check-if-two-strings-are-k-anagrams-or-not/1
*/

#include <bits/stdc++.h>
using namespace std;
const int MAX_NUM = 26;

vector <string> tokenize (string str)
{
    vector <string> tokens;
    string word;
    stringstream ss(str);
    while (getline(ss, word, ' '))
        tokens.push_back(word);
    
    return tokens;
}

vector <int> charFreq(string str)
{
    vector <int> freq(MAX_NUM,0);
    int n = str.length();

    for (int i = 0; i < n; i++)
        freq[str.at(i) - 'a']++;
    
    return freq;
}

void checkAnagrams (string str, int n)
{
    vector <string> tokens = tokenize(str);
    string s1 = tokens[0];
    string s2 = tokens[1];
    int count = 0;
    vector <int> f1 = charFreq(s1);
    vector <int> f2 = charFreq(s2);

    if (s1.length() != s2.length())
        cout << 0 << endl;
    else
    {
        for (int i = 0; i < MAX_NUM; i++)
        {
            if (f1[i] != 0 && f2[i] != 0 || f1[i] == 0 && f2[i] == 0)
                continue;
            else
                count++;
        }

        if ((int)(count/2) == n)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}

int main()
{
    string str;
    getline(cin,str);
    int n;
    cin >> n;
    cin.ignore(32767,'\n');
    checkAnagrams(str,n);
    return 0;
}