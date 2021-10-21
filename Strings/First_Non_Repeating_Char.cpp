/*
Problem:
https://practice.geeksforgeeks.org/problems/non-repeating-character/0
https://www.geeksforgeeks.org/given-a-string-find-its-first-non-repeating-character/
*/

#include <bits/stdc++.h>
using namespace std;
const int MAX_NUM = 26;

int charFreq(string str)
{
    vector <int> freq(MAX_NUM,0);
    map <char, int> charInd;
    map <char, int> :: iterator it;
    int n = str.length();
    int minInd = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (charInd.find(str[i]) == charInd.end())
            charInd[str[i]] = i;
        else if ((charInd.find(str[i]) != charInd.end()) && charInd[str[i]] != -1)
            charInd[str[i]] = -1;
    }

    for (it = charInd.begin(); it != charInd.end(); it++)
    {
        if (it -> second != -1)
            minInd = min(minInd, it -> second);
    }

    if (minInd != INT_MAX)
        return minInd;
    else
        return -1;
}

int main()
{
    string str;
    getline(cin,str);
    int res = charFreq(str);
    if (res == -1)
        cout << res << endl;
    else
        cout << str[res] << endl;
    return 0;
}