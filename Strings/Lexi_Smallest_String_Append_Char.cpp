/*
Problem URL:
https://www.geeksforgeeks.org/lexicographically-smallest-string-formed-by-appending-a-character-from-the-first-k-characters-of-a-given-string/?ref=rp
*/

#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

string generateLexiSmallStr (string str, int k)
{
    string word = "";

    while (str.length() > 0)
    {
        char ch = str[0];
        for (int i = 1; i < k && i < str.length(); i++)
            ch = min(ch,str[i]);
        
        word += ch;

        for (int i = 0; i < k; i++)
        {
            if (ch == str[i])
            {
                str.erase(str.begin() + i);
                cout << i << " " << str << endl;
                break;
            }
        }
    }
    
    return word;
}

int main()
{
    string str;
    getline(cin,str);
    int k;
    cin >> k;
    cin.ignore(32767, '\n');

    string lexistr = generateLexiSmallStr (str, k);
    cout << lexistr << endl;

    return 0;
}