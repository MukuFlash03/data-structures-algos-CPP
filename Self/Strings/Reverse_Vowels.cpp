/*
Problem:
https://www.geeksforgeeks.org/reverse-vowels-given-string/?ref=rp
*/

#include <bits/stdc++.h>
#include <string>
#include <iostream>
using namespace std;

bool isVowel (char ch)
{
    return (ch=='a' || ch=='A' || ch=='e' || ch=='E' || ch=='i' || ch=='I' || ch=='o' || ch=='O' || ch=='u' || ch=='U'); 
}

string reverseVowel(string s)
{
    int k = -1;
    string vowels;
    char ch = ' ';
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s.at(i);
        if (isVowel(ch))
        {
            vowels.push_back(ch);
            k++;
        }
    }
    
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s.at(i);
        if (isVowel(ch))
        {
            s[i] = vowels.at(k);
            k--;
        }
    }

    return s;
}

int main()
{
    string t;
    getline(cin, t);
    int n = stoi(t);
    
    while (n > 0)
    {
        string str;
        getline(cin,str);
        string str1 = reverseVowel(str);
        cout << str1 << endl;
        n--;
    }
}