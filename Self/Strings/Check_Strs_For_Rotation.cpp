/*
Problem:
https://practice.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not/0
*/

#include <string>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void checkRotation (string s1, string s2)
{
    set <string> circ_str;
    int l =s1.length();
    s1.append(s1);

    // generate circular substrings of length m
    for (int i = 0; i < l; i++)
        circ_str.insert(s1.substr(i,l));

    if (circ_str.find(s2) != circ_str.end())
        cout << "1" << endl;
    else
        cout << "0" << endl;
}

int main()
{
    string s1, s2;
    getline(cin,s1);
    getline(cin,s2);
    checkRotation (s1,s2);
    return 0;
}