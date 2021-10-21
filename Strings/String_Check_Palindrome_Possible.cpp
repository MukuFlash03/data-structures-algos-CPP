/*
Problem:
https://www.geeksforgeeks.org/check-characters-given-string-can-rearranged-form-palindrome/
*/

#include <bits/stdc++.h>
using namespace std;

void checkPalin (string str)
{
    int l = str.length();
    vector <char> palin;
    char ch = ' ';

    for (int i = 0; i < l; i++)
    {
        auto iter = find(palin.begin(), palin.end(), str[i]);

        if (iter != palin.end())
            palin.erase(iter);
        else
            palin.push_back(str[i]);
   }

    if (l % 2 == 0 && palin.empty() || l % 2 == 1 && palin.size() == 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
        
}


int main()
{
    string str;
    getline(cin,str);
    checkPalin(str);
    return 0;
}