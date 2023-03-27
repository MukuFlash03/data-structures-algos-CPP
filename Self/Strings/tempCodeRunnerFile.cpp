/*
Problem:
https://practice.geeksforgeeks.org/problems/merge-two-strings/0
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> tokenize(string str)
{
    vector <string> tokens;
    string word;
    stringstream checkstr(str.append(" "));
    while (getline(checkstr, word, ' '))
        tokens.push_back(word);
    
    return tokens;
}

void mergeStr (string s1,string s2)
{
    int l1 = s1.length();
    int l2 = s2.length();
    string :: iterator it1 = s1.begin();
    string :: iterator it2 = s2.begin();
    int i = 0,j = 0;

    while (it1 != s1.end() && it2 != s2.end())
    {
        cout << s1[i++];
        cout << s2[j++];
        it1++;
        it2++;
    }

    
    if (it1 != s1.end())
        cout << s1.substr(i,l1);

    if (it2 != s2.end())
        cout << s2.substr(i,l2);
}

int main()
{
    string str;
    getline(cin,str);
    vector <string> tokens = tokenize(str);
    string s1 = tokens[0];
    string s2 = tokens[1];
    mergeStr(s1,s2);
    cout << endl;
    return 0;
}