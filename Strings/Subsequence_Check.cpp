/*
Problem:
https://practice.geeksforgeeks.org/problems/check-for-subsequence/0
*/

#include <bits/stdc++.h>
using namespace std;

vector <string> tokenize (string str)
{
    vector <string> tokens;
    string word;
    stringstream ss(str);
    while (getline(ss, word, ' '))
        tokens.push_back(word);

    return tokens;
}

void checkSub (string str)
{
    vector <string> tokens = tokenize(str);
    string s1 = tokens[0];
    string s2 = tokens[1];

    for (int i = 0; i < s2.length(); i++)
        if (s2[i] == s1[0])
            s1 = s1.substr(1);

    if (!s1.empty())
        cout << 0 << endl;
    else
        cout << 1 << endl;
}

int main()
{
    string str;
    getline(cin,str);
    checkSub(str);
    return 0;
}