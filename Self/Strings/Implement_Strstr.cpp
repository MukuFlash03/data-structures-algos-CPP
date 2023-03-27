/*
Problem:
https://practice.geeksforgeeks.org/problems/implement-strstr/1
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> tokenize(string str)
{
    vector <string> tokens;
    string word;
    stringstream checkstr(str);
    while (getline(checkstr, word, ' '))
        tokens.push_back(word);
    
    return tokens;
}

int calcInd (string str)
{
    vector <string> tokens = tokenize(str.append(" "));
    string s1 = tokens[0];
    string s2 = tokens[1];
    int l1 = s1.length();
    int l2 = s2.length();
    for (int i = 0; i <= l1 - l2; i++)
        if (s1.substr(i,l2) == s2)
            return i;

    return -1;
}

int main()
{
    string str;
    getline(cin,str);
    int ind = calcInd(str);
    cout << ind << endl;
    return 0;
}