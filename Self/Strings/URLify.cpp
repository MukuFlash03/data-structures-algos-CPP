/*
Problem:
https://practice.geeksforgeeks.org/problems/urlify-a-given-string/0
*/

#include <boost/algorithm/string.hpp>
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

void printURL (vector <string> tokens)
{
    int i = 0;
    for (i = 0; i <tokens.size()-1; i++)
        cout << tokens[i] << "%20";
    cout << tokens[i];
}

int main()
{
    string str;
    getline(cin,str);
    boost :: trim_right(str);
    boost :: trim_left(str);
    vector <string> words = tokenize(str.append(" "));
    printURL(words);
    return 0;
}