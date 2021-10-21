/*
Problem:
https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string/0
*/

#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h> 
using namespace std;

vector<string> tokenize(string str)
{
    vector <string> tokens;
    string word;
    stringstream checkstr(str);
    while (getline(checkstr, word, '.'))
        tokens.push_back(word);
    
    return tokens;
}

string reverse_word(vector <string> tokens)
{
    string str;
    for (int i = tokens.size() - 1; i >= 0; i--)
    str.append(tokens[i] + ".");
    
    return str;
}

int main()
{
    //int n;
    //cin >> n;
    string t;
    getline(cin, t);
    int n = stoi(t);
    
    while (n > 0)
    {
        string str;
        getline(cin, str);
        vector <string> tokens = tokenize(str.append("."));
        string str1 = reverse_word(tokens);
        cout << str1.erase(str1.size() - 1) << endl;
        n--;
    }
}